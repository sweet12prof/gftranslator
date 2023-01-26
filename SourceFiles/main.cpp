#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>
#include "../HeaderFiles/Assembler.hpp"

    
int main(){

//     std::string opCode{"addi"};
//     int  lineNum,Ra, Rb, func;
//    lineNum = 0;
//    Ra = 1;
//    Rb = 2;
//    func = 4;

//    Rinstr newInstr{opCode, lineNum, Ra, Rb, func};

//    Instruction *RinstrPtr{& newInstr};
//    std::cout << std::hex << std::bitset<16>(RinstrPtr->printInstruction()).to_ulong();

    Assembler ass{"sssss"};
    std::string someStr {"somelabel:                                           add $1 $2"};

   std::cout << ass.processString(someStr);
    
}