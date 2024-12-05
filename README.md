# Parallel Histogram Equalization in C++ with OpenMP

Final Term Assignment for the Parallel Programming for Machine Learning course, held by professor Marco Bertini at University of Florence, Italy.

## 1 - Introduction
Logica dietro all'operazione di base del'histogram equalization, menzionando brevemente le operazioni che potrebbero essere parallelizzabili.

## 2 - Code
Presentazione del problema e riassunto breve dell'approccio, menzionando i vantaggi ottenibili tramite l'utilizzo di OpenMP.

### 2.1 - Hardware and Software setup
Hardware; versione di OpenMP e di C++; studio rapido del CMake

### 2.2 - Hyperparameters
Valori di range dei vari iperparametri.

### 2.3 - Sequential implementation
Elenco degli svantaggi dell'implementazione sequenziale, dei punti deboli che causano rallentamenti; complessità operazionale con l'O grande.

### 2.4 - Parallel implementation
Presentazione iniziale delle aspettative che ho riguardo l'implementazione parallela, ovvero lo speedup.
Poi, implementazione passo passo di clausole diverse partendo dalla direttiva base, nei vari punti in cui sono state inserite.

## 3 - Tests and Results
Serie di plot

### 3.1 - Number of Threads

...

## 4 - Conclusion
recap totale molto rapido dell'esperienza, menzionando la configurazione di iperparametri migliore, e la configurazione di direttiva+clausole migliore per questo problema.
