#include "../HeaderFiles/Jinstr.hpp"

Jinstr::Jinstr(const std::string & opCode, const int & lineNum, const int & immediate, const int & funct)
    :Instruction(opCode, lineNum)
{
    Jinstr::setInstruction(immediate, funct);
}

void Jinstr::setInstruction(const int & immediate, const int & funct){
    Jinstr::setImmediate(immediate).Jinstr::setFunct(funct);
}

//mutators
Jinstr& Jinstr::setImmediate(const int & immediate){
      if((0 < immediate) && (256 > immediate))
        this->immediate = immediate;
    else{
            std::cout << "Syntax Error"; 
            throw std::invalid_argument("Source Operand cannot be greater/lesser than 256/0");
    }
    return *this;
}

Jinstr & Jinstr::setFunct(const int & funct){
     if((0 < funct) && (16 > funct))
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