#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>
#include <iterator>
#include "../HeaderFiles/Assembler.hpp"

    
int main(int argc, char *argv[]){
   std::string inputfilePath{argv[1]};
   std::string outputfilePath{argv[2]};
   outputfilePath += "someasm2.txt";
    Assembler ass{inputfilePath, outputfilePath};
    ass.Assemble();
}