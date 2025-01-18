#include <iostream>
#include <fstream>
#include <filesystem>
#include "equalizer.hpp"
using namespace std;

int main() {
    vector<int> IMAGE_SIZES = {256, 512, 1024, 2048};
    vector<int> NUM_THREADS = {2, 4, 8, 12, 16, 24, 32};
    vector<int> BLOCK_SIZES = {4, 8, 12, 16, 20, 24, 32};
    const int NUM_TIMES = 1000;

    for(const auto& size : IMAGE_SIZES) {
        string folder_path = "../images/data/" + to_string(size) + "/";
        cout << "\nProcessing images of size " << size << "x" << size << endl;

        for(const auto& entry : std::filesystem::directory_iterator(folder_path)) {
            string imageName = entry.path().filename().string();
            cout << "\nProcessing image: " << imageName << endl;

            HistogramEqualizer equalizer(folder_path + imageName);
            SequentialResult seqResult = {0, 0, 0, 0, 0};

            for(int i = 0; i < NUM_TIMES; i++) {
                auto tempResult = equalizer.equalizerSequential();
                seqResult.seqHistTime += tempResult.seqHistTime;
                seqResult.seqCdfComputeTime += tempResult.seqCdfComputeTime;
                seqResult.seqCdfNormalizeTime += tempResult.seqCdfNormalizeTime;
                seqResult.seqTransformTime += tempResult.seqTransformTime;
                seqResult.seqExecutionTime += tempResult.seqExecutionTime;
            }

            cout << "Sequential Execution Times (over " << NUM_TIMES << " runs):"
                 << "\nHistogram Time: " << seqResult.seqHistTime << " us"
                 << "\nCDF Compute Time: " << seqResult.seqCdfComputeTime << " us"
                 << "\nCDF Normalize Time: " << seqResult.seqCdfNormalizeTime << " us"
                 << "\nTransform Time: " << seqResult.seqTransformTime << " us"
                 << "\nTotal Time: " << seqResult.seqExecutionTime << " us\n";

            for(auto numThreads : NUM_THREADS) {
                for(auto blockSize: BLOCK_SIZES) {
                    cout << "\nTesting with " << numThreads << " threads and block size " << blockSize << endl;
                    ParallelResult parResult = {0, 0, 0, 0, 0, numThreads, blockSize, 0, 0};

                    for(int i = 0; i < NUM_TIMES; i++) {
                        auto tempResult = equalizer.equalizerParallel(numThreads, blockSize, seqResult.seqExecutionTime);
                        parResult.parHistTime += tempResult.parHistTime;
                        parResult.parCdfComputeTime += tempResult.parCdfComputeTime;
                        parResult.parCdfNormalizeTime += tempResult.parCdfNormalizeTime;
                        parResult.parTransformTime += tempResult.parTransformTime;
                        parResult.parExecutionTime += tempResult.parExecutionTime;
                    }

                    parResult.speedup = seqResult.seqExecutionTime / parResult.parExecutionTime;
                    parResult.efficiency = parResult.speedup / numThreads;

                    cout << "Parallel Execution Times (over " << NUM_TIMES << " runs):"
                         << "\nHistogram Time: " << parResult.parHistTime << " us"
                         << "\nCDF Compute Time: " << parResult.parCdfComputeTime << " us"
                         << "\nCDF Normalize Time: " << parResult.parCdfNormalizeTime << " us"
                         << "\nTransform Time: " << parResult.parTransformTime << " us"
                         << "\nTotal Time: " << parResult.parExecutionTime << " us"
                         << "\nSpeedup: " << parResult.speedup
                         << "\nEfficiency: " << parResult.efficiency * 100 << "%\n";
                }
            }
        }
    }
    csv_results.close();
    return 0;
}
