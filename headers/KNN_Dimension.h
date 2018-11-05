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

int getArea(TDimension d);

#endif