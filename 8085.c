#include <asm-generic/types.h>
#include <stdio.h>
#include <stdbool.h>

#include "map.h"
#define X 0
#include "8085.h"


//Implementation for Instructions
/*Struct is as follows:
    Mnemonic
    Opcode Function(Function pointer)
    Address Mode(Function pointer)
    Cycle Count*/
typedef struct{
    //For 16-bit and 8-bit Operation Codes
    union{
        __u16 (*operate)(void) = NULL;
        __u8 (*operate)(void) = NULL;
        void (*operate) (void) = NULL;
    } opcode;
    __u8 (*addressMode)(void) = NULL;
    __u8  cycles = 0;
}instruction;

//Assembly Instruction Lookup Table
static const instruction[] ={
    ["SUB"] = {SUB, IMP, 7}, ["LXI"]  = {LXI , IMM, 3}, ["ANA"]  = {ANA, REG, 1}, ["HLT"] = {HLT, NULL, 1}, 
    ["ADD"] = {ADD, IMP, 2}, ["MOV"]  = {MOV , REG, 1}, ["ANI"]  = {ANI, IMM, 2}, ["NOP"] = {NOP, NULL, 0},
    ["JMP"] = {JMP, IMM, 3}, ["MVI"]  = {MVI , IMM, 2}, ["ORA"]  = {ORA, REG, 1}, ["OUT"] = {OUT, DIR , 3},
    ["CNZ"] = {CNZ, IMM, 3}, ["LHLD"] = {LHLD, DIR, 5}, ["ORI"]  = {ORI, IMM, 2}, 
    ["JNC"] = {JNC, IMM, 2}, ["SHLD"] = {SHLD, DIR, 5}, ["XRA"]  = {XRA, RIN, 2}, 
    ["ACI"] = {ACI, IMM, 2}, ["LDAX"] = {LDAX, RIN, 2}, ["XRI"]  = {XRI, IMM, 2},
    ["SUI"] = {SUI, IMM, 2}, ["XCHG"] = {XCHG, REG, 1}, ["CMP"]  = {CMP, REG, 1},
    ["SBB"] = {SBB, REG, 2}, ["XTHL"] = {XTHL, RIN, 5}, ["CPI"]  = {CPI, RIN, 2},
    ["SBI"] = {SBI, IMM, 2}, ["STAX"] = {STAX, RIN, 2}, ["INR"]  = {INR, REG, 1},
    ["INR"] = {INR, IMM, 1}, ["PCHL"] = {PCHL, REG, 1}, ["IN"]   = {IN , DIR, 3},
    ["INX"] = {INX, REG, 1}, ["RST"]  = {RST , RIN, 3}, ["POP"]  = {POP, RIN, 3},
    ["DCX"] = {DCX, REG, 1}, ["PUSH"] = {PUSH, RIN, 3}, ["EI"]   = {EI , NULL, 1}, 
    ["DAD"] = {DAD, REG, 3}, ["SPHL"] = {SPHL, REG, 1}, ["DI"]   = {DI , NULL, 1},
}; 



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