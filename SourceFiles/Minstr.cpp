#include "Minstr.hpp"

Minstr::Minstr(const std::string & opocde, const int & lineNum, const int & Ra, const int & Rb, const int & immediate)
    :Instruction::Instruction(opocde, lineNum)
{
    Minstr::setInstruction(Ra, Rb, immediate);
}

void Minstr::setInstruction(const int & Ra, const int & Rb, const int & immediate){
    Minstr::setRa(Ra).Minstr::setRb(Rb).Minstr::setImmediate(immediate);
}

//mutators
Minstr & Minstr::setRa(const int & Ra){
     if((-1 < Ra) && (16 > Ra))
        this->Ra = Ra;
    else {
        std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
    }
    return *this;
}

Minstr & Minstr::setRb(const int & Rb){
     if((-1 < Rb) && (16 > Rb))
        this->Rb = Rb;
    else {
        std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
    }
    return *this;
}


Minstr & Minstr::setImmediate(const int & immediate){
     if((0 <= immediate ) && (16 > immediate))
        this->Immediate = immediate;
    else {
        std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
    }
    return *this;
}

//accessors 

const int& Minstr::getRa() const {
    return this->Ra;
}


const int& Minstr::getRb() const{
    return this->Rb;
}

const int& Minstr::getImmediate() const{
    return this->Immediate;
}


//Override Virtual print Instruction
 std::string  Minstr::printInstruction() const{
    std::stringstream output;

    output  <<  Instruction::printInstruction()
            <<  std::bitset<::OPCODE_LENGTH>(this->Ra).to_string()
            <<  std::bitset<::OPCODE_LENGTH>(this->Rb).to_string()
            <<  std::bitset<::OPCODE_LENGTH>(this->Immediate).to_string();
    
    return output.str();
}