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
//Might seriously need to come here and look at two types of implementations
//Will I come back? Haha idk

//Depending on the kind of operation, the processor interprets these as either 8-bits or 16-bits
__u8 A = 0x00; //8-bit accumulator
regPair B; //register reference for B-C pair
regPair D; //register reference for D-E pair
regPair H; //register reference for H-L pair
__u8 flags[8];

/*16-bit sections of the CPU
  Initializing them at 0*/
__u16 stackPointer = 0x00;
__u16 programCounter = 0x00;
__u16 addressBusLatch = 0x00;


//Function declarations


__u8 setFlags(bool Cval, bool Pval, bool Aval, bool Zval, bool Sval);
__u8 resetFlags(__u8* flags);
void getFlags(__u8* ret);
__u16 pswCombination(__u8 A, __u8 flags[8]);


/*Addressing modes
  Instructions are categorized into their method of addressing the hardware registers
  The 8085 has five instruction addressing modes
  Here we initialize all five of them*/
__u8 IMP(); //Indirect addressing mode
__u8 REG(); //Register addressing mode
__u8 IMM(); //Immediate addressing mode
__u8 DIR(); //Direct addressing mode
__u8 RIN(); //Register Indirect addressing mode
__u8 COM(); //Combined addressing mode

/*Intructions*/
//Will start with those that return 16-bit variables or those that could result in a carry
__u16 SUB(); void LXI();  __u8 DCX(); void EI();
__u16 ADD(); void MOV();  __u8 ANA(); void DI();
__u16 JMP(); void MVI();  __u8 ANI(); void HLT();
__u16 CNZ(); void LHLD(); __u8 ORA(); void NOP();
__u16 JNC(); void SHLD(); __u8 ORI(); void IN();
__u16 ACI(); void LDAX(); __u8 XRA(); void OUT();
__u16 SUI(); void XCHG(); __u8 XRI(); void POP();  
__u16 SBB(); void XTHL(); __u8 CMP(); void PUSH();
__u16 SBI(); void STAX(); __u8 CPI();
__u16 INX(); void PCHL(); __u8 INR();         
__u16 DAD(); void RST();   void SPHL();



