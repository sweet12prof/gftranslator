#include "./InstrIncludes.hpp"

Instruction::Instruction(const std::string & opCode, const int & lineNum ){
   Instruction::setInstruction(opCode, lineNum);
}

// --- Access and Mutators For Opcode 
void Instruction::setOpCode(const int & opcode)
{
    if((0 <= opcode) && (16 > opcode))
        this->opCode = opcode; 
    else 
        throw std::invalid_argument("opcode value cant be below/greater than 0/16");
}


int  Instruction::getOpCode() const{
    return this->opCode;
}


//-----Access and Mutators for InstrType
void Instruction::setType(const int & instrType){
    if((0 <= instrType) && (5> instrType))
        this->type = (instrTypes) (instrType);
}

instrTypes  Instruction::getType() const {
    return this->type;
}

void Instruction::setInstruction(const std::string & opcode_, const int & lineNum ){
    
    std::string opcode = opcode_; 
    std::transform(opcode.begin(), opcode.end(), opcode.begin(), 
    [](unsigned char c) {
        return ::tolower(c);
     });
    if(auto p = instMap.find(opcode); p == instMap.end())
    {
        std::cout << "Operation mnemonic " << opcode <<  "in " << lineNum << "doesnt exist" << std::endl;
        throw std::invalid_argument("Syntax Error");
    }
    else 
    {
        Instruction::setOpCode(p->second.second.first);
        Instruction::setType(p->second.first);
    }
}
 //sticp
std::string  Instruction::printInstruction() const{
    return std::bitset<::OPCODE_LENGTH>(Instruction::getOpCode()).to_string();
} 