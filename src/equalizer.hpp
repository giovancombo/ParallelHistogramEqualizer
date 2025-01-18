#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#ifndef EQUALIZER_HPP
#define EQUALIZER_HPP

struct Histogram {
    std::vector<int> counts;
    std::vector<int> cdf;
    double mean, stddev;
    Histogram() : counts(256, 0), cdf(256, 0), mean(0), stddev(0) {}
};

struct Image {
    int width, height;
    std::vector<unsigned char> pixels;
    Histogram histogram;
    Image(int w, int h) : width(w), height(h), pixels(w * h, 0), histogram() {}

    Image(const std::string& path) {
        std::ifstream file(path, std::ios::binary);
        std::string format;
        int maxval;

        if (!file) {
            throw std::runtime_error("Cannot open file: " + path);
        }

        file >> format;
        file >> width >> height;
        file >> maxval;
        file.get();

        pixels.resize(width * height);
        file.read(reinterpret_cast<char*>(pixels.data()), pixels.size());
    }

    void save(const std::string& path) const {
        std::ofstream file(path, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Cannot create file: " + path);
        }
        file << "P6\n" << width << " " << height << "\n255\n";
        file.write(reinterpret_cast<const char*>(pixels.data()), pixels.size());
    }
};

struct SequentialResult {
    float seqHistTime, seqCdfComputeTime, seqCdfNormalizeTime, seqTransformTime, seqExecutionTime;
};

struct ParallelResult {
    float parHistTime, parCdfComputeTime, parCdfNormalizeTime, parTransformTime, parExecutionTime;
    int numThreads, blockSize;
    float speedup, efficiency;
};

class HistogramEqualizer {
private:
    Image inputImage;
    Image outputImage;

public:
    HistogramEqualizer(const std::string& imagePath);
    ~HistogramEqualizer();
    void saveImage(const std::string& filename);

    SequentialResult equalizerSequential();
    ParallelResult equalizerParallel(int numThreads, int blockSize, float seqExecutionTime);
};

#endif
