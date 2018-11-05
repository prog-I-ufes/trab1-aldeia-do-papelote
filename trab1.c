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

    Tcsv_data* training_content;
    Tcsv_data* test_content;

    training_path = readLineFile(config);
    test_path = readLineFile(config);
    predicts_path = readLineFile(config);

    printf("\n%s\n", training_path);
    printf("%s\n", test_path);
    
    training_content = readFileToMatrix(training_path);
    //test_content = readFileToMatrix(test_path);
    
    free(training_path);
    free(test_path);
    free(predicts_path);

    return 0;
}