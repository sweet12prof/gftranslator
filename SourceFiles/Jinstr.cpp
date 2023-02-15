#include "./Jinstr.hpp"

Jinstr::Jinstr(const std::string & opCode, const int & lineNum, const int & immediate)
    :Instruction(opCode, lineNum)
{
    int funct = instMap.find(opCode)->second.second.second;
   // std::cout << "opcode is " << opCode << "funct is " << funct << " immediate is " << immediate << std::endl;
    Jinstr::setInstruction(immediate, funct);
   // std::cout << "jclass opcode is " << opCode << " immediat is " << immediate << std::endl; 
}

void Jinstr::setInstruction(const int & immediate, const int & funct){
    Jinstr::setImmediate(immediate).Jinstr::setFunct(funct);
}

//mutators
Jinstr& Jinstr::setImmediate(const int & immediate){
   // std::cout << "immediate is " << immediate;
      if((-129 < immediate) && (128 > immediate))
        this->immediate = immediate;
    else{
            std::cout << "Syntax Error"; 
            throw std::invalid_argument("Source Operand cannot be greater/lesser than 256/0");
    }
    return *this;
}

Jinstr & Jinstr::setFunct(const int & funct){
     if((-1 < funct) && (16 > funct))
        this->funct = funct;
     else {
         std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
     }
     return *this;
}

//accessors
const int & Jinstr::getImmediate() const {
    return this->immediate;
}

const int & Jinstr::getFunct() const{
    return this->funct;
}


//Override virtual function printInstruction 
std::string  Jinstr::printInstruction() const{
    std::stringstream output;

    output  << Instruction::printInstruction()
            << std::bitset<::I_T_IMM_LENGTH>(this->immediate).to_string()
            << std::bitset<::OPCODE_LENGTH>(this->funct).to_string();
    return output.str();
}