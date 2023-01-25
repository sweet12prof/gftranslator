#include "../HeaderFiles/Instruction.hpp"

Instruction::Instruction(const std::string & opCode, const int & lineNum ){
   Instruction::setInstruction(opCode, lineNum);
}

// --- Access and Mutators For Opcode 
void Instruction::setOpCode(const int & opcode)
{
    if((0 < opcode) && (16 > opcode))
        this->opCode = opcode; 
    else 
        throw std::invalid_argument("opcode value cant be below/greater than 0/16");
}


const int & Instruction::getOpCode() const{
    return this->opCode;
}


//-----Access and Mutators for InstrType
void Instruction::setType(const int & instrType){
    if((0 < instrType) && (5> instrType))
        this->type = (instrTypes) (instrType);
}

const instrTypes & Instruction::getType() const {
    return this->type;
}

void Instruction::setInstruction(const std::string & opcode, const int & lineNum ){
    if(auto p = instMap.find(opcode); p == instMap.end())
    {
        std::cout << "Operation mnemonic in" << lineNum << "doesnt exist" << std::endl;
        throw std::invalid_argument("Syntax Error");
    }
    else 
    {
        Instruction::setOpCode(p->second.second);
        Instruction::setType(p->second.first);
    }
}

std::string  Instruction::printInstruction() const{
    return std::bitset<::OPCODE_LENGTH>(Instruction::getOpCode()).to_string();
} 