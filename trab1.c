#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/KNN_Classifiers.h"
#include "headers/KNN_Dimension.h"
#include "headers/KNN_Distance.h"
#include "headers/KNN_FileManager.h"
#include "headers/KNN_Matrix.h"
#include "headers/KNN_Vector.h"

void runCommands(Tcommand_data* commands, Tcsv_data* training_content, Tcsv_data* test_content, char *path_result){
    // Variaveis de controle de loops
	int i = 0;
	int j = 0;
	int k = 0;

	int vet_len = 0; // tamanho horizontal do vetor
	int correct = 0; // corretas da acuracia

	float acuracia = 0;

	int test_rotule = 0; // auxiliar para guardar o rotulo do teste atual
	int *knn_rotule; // vetor de k rotulos mais proximos
	int *index; // vetor de controle de indices

	// Variaveis que guardam quantos tipos de rotulos existem
	// para o teste e para o treino
	
	double **m_test = splitNumbers(test_content, &vet_len); // matriz de teste
	double **m_train = splitNumbers(training_content, &vet_len); // matriz de treino
	
	int distinct_test = distinctRotules(m_test, test_content->map.lines, vet_len);
	int distinct_train = distinctRotules(m_train, training_content->map.lines, vet_len);

	double *dist = create_F_Vector(training_content->map.lines); // vetor de distancias

	// Variveis para escrever as predicoes apos rodar o algoritmo
	Tcsv_map content_map;
	content_map.lines = distinct_test + 4 + test_content->map.lines;
	content_map.length_line = malloc( sizeof(int) * content_map.lines );
	for( i = 2 ; i < distinct_test ; i++ ){
		content_map.length_line[i] = (distinct_train * 2) + 1;
	}
	char **content = create_R_CharacterMatrix(content_map);
	char* path_result_f;

	// Algoritmo de KNN
	for( k = 0 ; k < commands->map.lines - 1 ; k++ ){
		index = create_I_Vector(commands->data[k].k);
		knn_rotule = create_I_Vector(commands->data[k].k);

		printf("Command: %d, %c, %.2f\n", commands->data[k].k, commands->data[k].distance, commands->data[k].r);
		correct = 0;
                    
        for( i = 0 ; i < test_content->map.lines ; i++ ){
			// SALVA O ROTULO DE TESTE REAL
			test_rotule = m_test[i][vet_len - 1];

			// PERCORRE TODAS AS LINHAS DO TREINO COMPARANDO
			// A DISTANCIA DO TESTE COM A DO TREINO
			switch(commands->data[k].distance){
				case 'E':
					for( j = 0 ; j < training_content->map.lines ; j++ ){
						dist[j] = euclidianDistance(m_test[i], m_train[j], vet_len - 1);
					}
					break;
				case 'M':
					for( j = 0 ; j < training_content->map.lines ; j++){
						dist[j] = minkowskyDistance(m_test[i], m_train[j], vet_len - 1, commands->data[k].r);
					}
					break;
				case 'C':
					for( j = 0 ; j < training_content->map.lines ; j++){
						dist[j] = chebyshevDistance(m_test[i], m_train[j], vet_len - 1);
					}
					break;
			}

			kMinors(dist, training_content->map.lines, commands->data[k].k, index);
			
			for( j = 0 ; j < commands->data[k].k ; j++){
				knn_rotule[j] = m_train[index[j]][vet_len - 1];
			}

			if( recorrence(knn_rotule, commands->data[k].k) == test_rotule )
				correct++;

			content[3 + distinct_test + i][0] = i + 48;
		}
		content[i][0] = ' ';

		char snum[6];
		

		//writeInFile(path_result_f, content, content_map.lines);

		acuracia = Accuracy(correct, test_content->map.lines);
		printf("acuracia: %f\n", acuracia);
		    
		free(index);
		free(knn_rotule);
	}

	freedoubleMatrix(m_test, test_content->map.lines);
	freedoubleMatrix(m_train, training_content->map.lines);
	
	freeCharacterMatrix(content, content_map.lines);

	free(dist);
	free(content_map.length_line);	
	
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

    runCommands(commands, training_content, test_content, predicts_path);

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
