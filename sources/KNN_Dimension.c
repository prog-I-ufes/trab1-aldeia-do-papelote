#include "../headers/KNN_Dimension.h"
#include <stdlib.h>

int getArea(TDimension t){
    return t.x*t.y;
}

void freeCommands(Tcommand_data *data){
    int i = 0;
    
    free(data->data);

    free(data);
}