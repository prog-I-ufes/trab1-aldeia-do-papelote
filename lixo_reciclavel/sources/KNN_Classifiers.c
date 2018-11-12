#include "../headers/KNN_Classifiers.h"
#include <stdio.h>

double Accuracy(int A, int T){
    return 100.0*A/T;
}