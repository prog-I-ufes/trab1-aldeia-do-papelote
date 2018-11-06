#ifndef _H_DIMENSION
#define _H_DIMENSION

typedef struct Dimension{
	int x;
	int y;
} TDimension;

typedef struct csv_map{
    int lines;
    int *length_line;
} Tcsv_map;

typedef struct csv_data{
    Tcsv_map map;
    char** data;
} Tcsv_data;

typedef struct command{
    int k;
    char distance;
    float r;
} Tcommand;

typedef struct command_data{
    Tcommand *data;
    Tcsv_map map;
} Tcommand_data;

int getArea(TDimension d);
void freeCommands(Tcommand_data *data);

#endif