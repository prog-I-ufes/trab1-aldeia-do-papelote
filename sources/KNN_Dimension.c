#include "../headers/KNN_Dimension.h"
#include <stdlib.h>

// Libera uma estrutura do tipo Tcommand_data da memoria
void freeCommands(Tcommand_data *data){
    free(data->data);
    free(data);
}