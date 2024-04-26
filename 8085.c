#include <asm-generic/types.h>
#include <stdio.h>
#include <stdbool.h>
#include "map.h"
#define X 0
#include "8085.h"



int main(){

    __u8 flag1 = setFlags(1, 0, 1, 0, 1);
    __u8 *flagPointer;
    flagPointer = &flag1;
    for (int i = 0; i < 8; i++){
        printf("[%d] The individual values of the various flags are: [%d]\n", i, flag1&(1<<i)?1:0);
    }
 
 //the code below is purely for testing the logic in the first few lines of getFlags 
     //Array to store flag values for testing
/*    __u8 testFlagArr[5];
    //_________
    __u8 flagArr[8];
    __u8 derefPointer = *flagPointer;
    for (int i = 0; i < 8; i++){
        flagArr[i] =  derefPointer&(1<<i)?1:0;
    }

    for (int i = 0; i<sizeof(flagArr)/ sizeof(flagArr[i]); i++){
        printf("%d", flagArr[i]);
        printf("  \n");
    }
    //
    testFlagArr[0] = flagArr[0];
    testFlagArr[1] = flagArr[2];
    testFlagArr[2] = flagArr[4];
    testFlagArr[3] = flagArr[6];
    testFlagArr[4] = flagArr[7];

    for(int i=0;i<sizeof(testFlagArr)/sizeof(testFlagArr[i]);i++){
        printf("%d", testFlagArr[i]);
    }
    
    insert("Cval", testFlagArr[0]); //INDEX 0
    insert("Pval", testFlagArr[1]); //INDEX 1
    insert("Aval", testFlagArr[2]); //INDEX 2
    insert("Zval", testFlagArr[3]); //INDEX 3
    insert("Sval", testFlagArr[4]); //INDEX 4

    printMap();
    printSetFlagMap();*/
    //flag1 = resetFlags(&flag1);
    //printf("%d\n", flag1);
    getFlags(&flag1);

    //Getting a Map/Dict of setflags
    
}