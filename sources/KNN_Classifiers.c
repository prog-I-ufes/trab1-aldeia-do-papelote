#include "../headers/KNN_Classifiers.h"
#include <stdio.h>

// Mede a acuracia dos acertos em relacao as tentativas 
double Accuracy(int A, int T){
    return 100.0*A/T;
}