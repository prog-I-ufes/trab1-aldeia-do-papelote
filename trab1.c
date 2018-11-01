#include "headers/KNN_Classifiers.h"
#include "headers/KNN_Dimension.h"
#include "headers/KNN_Distance.h"
#include "headers/KNN_FileManager.h"
#include "headers/KNN_Matrix.h"
#include "headers/KNN_Vector.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    FILE* config = openFile("config.txt", 'r');
    FILE* training;
    FILE* test;

    char* training_path;
    char* test_path;
    char* predicts_path;

    training_path = readLineFile(config);
    test_path = readLineFile(config);
    predicts_path = readLineFile(config);

    training = openFile(training_path, 'r');
    test = openFile(test_path, 'r');

    free(training_path);
    free(test_path);
    free(predicts_path);

    closeFile(config);
    closeFile(training);

    return 0;
}