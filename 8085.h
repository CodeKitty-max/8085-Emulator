#include <asm-generic/types.h>
#include <stdio.h>
#include <stdbool.h>
#define X 0 //is for the unused bits in the flag registers

/*According to manual, registers are often referenced in pairs.
  The first component in the structure refers to the first value in the register pair
  The second one likewise
  The term regPair refers to the register pair*/
typedef struct{
    __u8 reg1;
    __u8 reg2;
} regPair;


/*It's probs easier to use a __u16 as a simple data structure but fuck this 
I don't feel like doing ungodly binary manipulations just to load data haha*/

//registers
__u8 A = 0x00; //8-bit accumulator
regPair B; //register reference for B-C pair
regPair D; //register reference for H-L pair
regPair H; //register reference for H-L pair
__u8 flags[8];


//Sets flags as desired
__u8 setFlags(bool Cval, bool Pval, bool Aval, bool Zval, bool Sval){
    __u8 ret = 0;
    __u8 flags[8] = {Cval, X, Pval, X, Aval, X, Zval, Sval};
    for(__u8 i = 0; i < 8; i++){
        if(flags[i])
            ret |= (1 << i);
    }       

    return ret;
}

//Resets the flags
__u8 resetFlags(__u8* flags){
   //pointer to store the value of zero 
    __u8* resValPointer;
    __u8 resVal = 0;
    resValPointer = &resVal;
    
   //reassigning value of flags to zero 
    flags = resValPointer;
    __u8 resetFlags = *(__u8*) flags;
    return resetFlags;
}


//This is for getting the individual flags
void getFlags(__u8* ret){
    __u8 derefFlags = *(__u8*) ret;
    __u8 flagArray[8];//8-bit array that contains 8-bit flag number
    __u8 filteredArray[5];//filtered array that only contains 5 usable flags
    //takes in decimal form of flags and converts them to binary
    for(int i = 0; i < 8; i++){
      flagArray[i] = derefFlags&(1<<i)?1:0;
    }
    //assigning values to the filtered array to form a 5 value array
    filteredArray[0] = flagArray[0]; //Cval
    filteredArray[1] = flagArray[2]; //Pval
    filteredArray[2] = flagArray[4]; //Aval
    filteredArray[3] = flagArray[6]; //Zval
    filteredArray[4] = flagArray[7]; //Sval  

    //create map for individual positions representing the various flags
    insert("Cval", filteredArray[0]); //INDEX 0
    insert("Pval", filteredArray[1]); //INDEX 1
    insert("Aval", filteredArray[2]); //INDEX 2
    insert("Zval", filteredArray[3]); //INDEX 3
    insert("Sval", filteredArray[4]); //INDEX 4

    //Printing the set flags
    printSetFlagMap();
}
