#include "headers/KNN_Classifiers.h"
#include "headers/KNN_Dimension.h"
#include "headers/KNN_Distance.h"
#include "headers/KNN_FileManager.h"
#include "headers/KNN_Matrix.h"
#include "headers/KNN_Vector.h"
#include <stdlib.h>
#include <stdio.h>

void runEuclidian(Tcsv_data* training_content, Tcsv_data* test_content, int k){
    int i = 0;
    int j = 0;

    float** training_data;
    float** test_data;

    int* training_rotules = (int*) malloc(sizeof(int) * k);
    int* test_rotule = (int*) malloc(sizeof(int));

    int vet_len = 0;

    float* dist = (float*) malloc(sizeof(float) * training_content->map.lines);
    float* k_minors;
    int* k_index = malloc(sizeof(int) * k);

    training_data = splitNumbers(training_content, &vet_len);
    test_data = splitNumbers(test_content, &vet_len);

    for( i = 0 ; i < test_content->map.lines  ; i++ ){
        for( j = 0 ; j < training_content->map.lines - 1 ; j++ ){
            dist[j] = euclidianDistance(test_data[i], training_data[j], vet_len);
        }
        k_minors = kMinors(dist, training_content->map.lines, k, k_index);
        *test_rotule = test_data[i][vet_len - 1];
        for( j = 0 ; j < k ; j++ ){
            training_rotules[j] = training_data[k_index[j]][vet_len - 1];
            printf("index: %.2d | %d \n", k_index[j], training_rotules[j]);
        }
        printf("\n");
    }
    
    free_F_Vector(dist);
    free_F_Vector(k_minors);
    free_I_Vector(k_index);
    free_I_Vector(training_rotules);
    free(test_rotule);

    freeFloatMatrix(training_data, training_content->map.lines);
    freeFloatMatrix(test_data, test_content->map.lines);
}

void runMinkowsky(Tcsv_data* training_content, Tcsv_data* test_content, int k, float r){

}

void runChebyshev(Tcsv_data* training_content, Tcsv_data* test_content, int k){

}

void runCommands(Tcommand_data* commands, Tcsv_data* training_content, Tcsv_data* test_content){
    int i = 0;

    for( i = 0 ; i < commands->map.lines ; i++ ){
        switch(commands->data[i].distance){
            case 'E':
                runEuclidian(training_content, test_content, commands->data[i].k);
                break;
            case 'M':
                runMinkowsky(training_content, test_content, commands->data[i].k, commands->data[i].r);
                break;
            case 'C':
                runChebyshev(training_content, test_content, commands->data[i].k);
                break;
        }
        if(commands->data[i].distance == 'E') break;
    }

}

int main(void){
    
    FILE* config = openFile("config.txt", 'r');
    Tcommand_data* commands;

    char* training_path;
    char* test_path;
    char* predicts_path;

    Tcsv_data* training_content;
    Tcsv_data* test_content;

    training_path = readLineFile(config);
    test_path = readLineFile(config);
    predicts_path = readLineFile(config);

    closeFile(config);
    
    commands = readInstructions("config.txt");

    training_content = readFileToMatrix(training_path);
    test_content = readFileToMatrix(test_path);

    runCommands(commands, training_content, test_content);

    free(training_path);
    free(test_path);
    free(predicts_path);

    freeCharacterMatrix(training_content->data, training_content->map.lines);
    freeCharacterMatrix(test_content->data, test_content->map.lines);

    free(commands->map.length_line);
    freeCommands(commands);
    
    free(training_content->map.length_line);
    free(test_content->map.length_line);

    free(training_content);
    free(test_content);
    
    return 0;
}