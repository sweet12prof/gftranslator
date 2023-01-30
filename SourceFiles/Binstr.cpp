#include "Binstr.hpp"

Binstr::Binstr(const std::string & opcode, const int & lineNum, const int & Ra, const int & immediate)
    :Instruction::Instruction(opcode, lineNum)
{
    int funct = instMap.find(opcode)->second.second.second;
    Binstr::setInstruction( Ra,  immediate,  funct);
}

// set Instruction to call memmber mutator Functions
void Binstr::setInstruction(const int & Ra, const int & immediate, const int & funct){
    Binstr::setRa(Ra);
    Binstr::setImmediate(immediate);
    Binstr::setFunct(funct);
}

//mutators
void Binstr::setRa(const int & Ra){
       if((-1 < Ra) && (16 > Ra))
            this->Ra = Ra;
       else{
            std::cout << "Syntax Error"; 
            throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
       } 
}


void Binstr::setImmediate(const int & immediate){
       if((-33 < immediate && (32 > immediate)))
            this->Immediate  = immediate;
       else{
            std::cout << "Syntax Error"; 
            throw std::invalid_argument("Source Operand cannot be greater/lesser than 0/256");
       } 
}


void Binstr::setFunct(const int & funct){
    if((-1 < funct) && (4 > funct))
        this->funct = funct;
    else 
        {
            std::cout << "Syntax Error"; 
            throw std::invalid_argument("Source Operand cannot be greater/lesser than 4/0");
        }
}

//accessors
const int & Binstr::getRa() const{
    return this->Ra;
}

const int & Binstr::getImmediate() const{
    return this->Immediate;
}

const int & Binstr::getFunct() const{
    return this->funct;
}


//OverridePrintInstruction 
std::string  Binstr::printInstruction() const{
    std::stringstream output; 
    output << Instruction::printInstruction()
           << std::bitset<::OPCODE_LENGTH>(this->Ra).to_string()
           << std::bitset<::B_T_IMM_LENGTH>(this->Immediate).to_string()
           << std::bitset<::B_T_FUNCT_LENGTH>(this->funct).to_string();
    return output.str();

}