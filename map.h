#include <stdio.h> 
#include <string.h> 
  
#define MAX_SIZE  8 // Maximum number of elements in the map 
  
int size = 0; // Current number of elements in the map 
char keys[MAX_SIZE][100]; // Array to store the keys 
int values[MAX_SIZE]; // Array to store the values 

//function declarations
int getIndex(char key[]); 
void insert(char key[], int value); 
int get(char key[]);
void printMap(); 
void printSetFlagMap();

