#include "headers/KNN_Classifiers.h"
#include "headers/KNN_Dimension.h"
#include "headers/KNN_Distance.h"
#include "headers/KNN_FileManager.h"
#include "headers/KNN_Matrix.h"
#include "headers/KNN_Vector.h"

void readPaths(FILE* f, char* test, char* training, char* predicts){
     training = readLineFile(f);
     test = readLineFile(f);
     predicts = readLineFile(f);
}

int main(void){
    FILE* config = openFile("config.txt", 'r');
    
    char* training_path;
    char* test_path;
    char* predicts_path;

    readPaths(config, training_path, test_path, predicts_path);

    closeFile(config);

    return 0;
}