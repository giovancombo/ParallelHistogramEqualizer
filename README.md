# Parallel Histogram Equalization in C++ with OpenMP

Final Term Assignment for the Parallel Programming for Machine Learning course, held by professor Marco Bertini at University of Florence, Italy.

## 1 - Abstract
Presentazione del problema e riassunto breve dell'approccio, menzionando i vantaggi ottenibili tramite l'utilizzo di OpenMP, con accenno ai risultati ottenuti.

## 2 - Setup
Logica dietro all'operazione di base del'histogram equalization, menzionando brevemente le operazioni che potrebbero essere parallelizzabili.

### 2.1 - Hardware and Software
Hardware; versione di OpenMP e di C++; studio rapido del CMake

### 2.2 - Hyperparameters
Valori di range dei vari iperparametri.

## 3 - Sequential implementation
Elenco degli svantaggi dell'implementazione sequenziale, dei punti deboli che causano rallentamenti; complessità operazionale con l'O grande.

## 4 - Parallel implementation
Presentazione iniziale delle aspettative che ho riguardo l'implementazione parallela, ovvero lo speedup.
Poi, implementazione passo passo di clausole diverse partendo dalla direttiva base, nei vari punti in cui sono state inserite.

## 5 - Speedup and Efficiency Tests
Serie di plot

### 5.1 - Number of Threads

...

## 6 - Conclusion
recap totale molto rapido dell'esperienza, menzionando la configurazione di iperparametri migliore, e la configurazione di direttiva+clausole migliore per questo problema.
