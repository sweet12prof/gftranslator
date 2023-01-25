#include <iostream>
#include <bitset>
#include <string>
#include "../HeaderFiles/Rinstr.hpp"

    
int main(){

    std::string opCode{"addi"};
    int  lineNum,Ra, Rb, func;
   lineNum = 0;
   Ra = 1;
   Rb = 2;
   func = 4;

   Rinstr newInstr{opCode, lineNum, Ra, Rb, func};

   Instruction *RinstrPtr{& newInstr};
std::cout << RinstrPtr->printInstruction();

}