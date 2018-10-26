#!/bin/bash

# CREATES A TEMP DIRECTORY
mkdir temp;
# MOVES ALL SOURCES TO TEMP
cp sources/* temp/;
# MOVES THE MAIN FILE TO TEMP
cp main.c temp/;
# COMPILE ALL AND MAKES KNN
gcc -o -lm temp/*.c ;
# MOVES KNN TO CURRENT DIRECTORY
#cp temp/knn knn;
# REMOVE TEMP DIRECTORY AND TEMP FILES
