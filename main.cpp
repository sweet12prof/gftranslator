#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>
#include <iterator>
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
    std::string someStr {"/home/cnutsukpui/Desktop/gftranslator/someasm.asm"};
    Assembler ass{someStr};

    // std::string someStr {"something: j something"};
    // int line = 0;
    // std::bitset <16> someNum{ass.translate(ass.processString(someStr), line)};

    // std::ostream_iterator <std::string> output {std::cout, "\n"};

    // std::vector<std::string> InstrQueue {
    //     "sum2: addi $1, 12      ", 
    //     "beq $1, sum2           ",
    //     "additp: j sum2         ", 
    //     "srs $1, $0             ",
    //     "jr $4, 12              ", 
    //     "mvv $2, $1             "
    // };

    // ass.processInstrucQueue(InstrQueue);

    // std::copy(InstrQueue.begin(), InstrQueue.end(), output);


    // std::cout << std::hex  << std::setw(4) << std::setfill('0') << someNum.to_ulong() << std::endl;
    
    // std::stringstream ss("some bouys mum");
    // std::string val;
    // while( ss >> val)
    // std::cout << val << std::endl; 
    ass.Assemble();
}