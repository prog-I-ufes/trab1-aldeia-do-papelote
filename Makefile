all: trab1.c KNN_Distance.o KNN_Vector.o KNN_Classifiers.o KNN_FileManager.o KNN_Dimension.o KNN_Matrix.o 
	gcc trab1.c -o trab1 KNN_Distance.o KNN_Vector.o KNN_Classifiers.o KNN_FileManager.o KNN_Dimension.o KNN_Matrix.o -lm

KNN_FileManager.o: sources/KNN_FileManager.c headers/KNN_FileManager.h KNN_Dimension.o KNN_Matrix.o
	gcc -c sources/KNN_FileManager.c headers/KNN_FileManager.h KNN_Dimension.o KNN_Matrix.o

KNN_Matrix.o: sources/KNN_Matrix.c headers/KNN_Matrix.h KNN_Dimension.o
	gcc -c sources/KNN_Matrix.c headers/KNN_Matrix.h KNN_Dimension.o -lm

KNN_Dimension.o: sources/KNN_Dimension.c headers/KNN_Dimension.h
	gcc -c sources/KNN_Dimension.c headers/KNN_Dimension.h

KNN_Classifiers.o: sources/KNN_Classifiers.c headers/KNN_Classifiers.h
	gcc -c sources/KNN_Classifiers.c headers/KNN_Classifiers.h

KNN_Vector.o: sources/KNN_Vector.c headers/KNN_Vector.h
	gcc -c sources/KNN_Vector.c headers/KNN_Vector.h -lm

KNN_Distance.o: sources/KNN_Distance.c headers/KNN_Distance.h
	gcc -c sources/KNN_Distance.c headers/KNN_Distance.h -lm

clean:
	rm *.o; rm  headers/*.gch;
