#include "headers/KNN_Classifiers.h"
#include "headers/KNN_Dimension.h"
#include "headers/KNN_Distance.h"
#include "headers/KNN_FileManager.h"
#include "headers/KNN_Matrix.h"
#include "headers/KNN_Vector.h"
#include <stdlib.h>
#include <stdio.h>

void runCommands(Tcommand_data* commands, Tcsv_data* training_content, Tcsv_data* test_content){
    int k = 0;

    for( k = 0 ; k < commands->map.lines ; k++ ){
        switch(commands->data[k].distance){
            case 'E':
                //runEuclidian(training_content, test_content, commands->data[k].k);
                break;
            case 'M':
                //runMinkowsky(training_content, test_content, commands->data[k].k, commands->data[k].r);
                break;
            case 'C':
                //runChebyshev(training_content, test_content, commands->data[k].k);
                break;
        }
    }

    printf("\n");

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