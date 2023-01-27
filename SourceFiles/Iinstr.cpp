#include "./Iinstr.hpp"

Iinstr::Iinstr(const std::string & opcode, const int lineNum, const int & Ra, const int & Immediate)
    :Instruction::Instruction(opcode, lineNum)
{
    Iinstr::setInstruction(Ra, Immediate);
}

 void Iinstr::setInstruction(const int & Ra, const int & Immediate ){
    Iinstr::setRa(Ra);
    Iinstr::setImmediate(Immediate);
 }


//mutators fOR Ra and Immmediate
void Iinstr::setRa(const int & Ra){
    if((-1 < Ra) && (16 > Ra))
        this->Ra = Ra;
    else {
        std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
    }
}

void Iinstr::setImmediate(const int & immediate){
    if((-1 < immediate) && (256 > immediate))
        this->Immediate = immediate;
    else {
        std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 0/256");
    }
}

//accesors for Ra and Immediate

const int & Iinstr::getRa() const{
    return this->Ra;
}

const int & Iinstr::getImmediate() const{
    return this->Immediate;
}

//virtual Func Override 
std::string  Iinstr::printInstruction() const {
    std::stringstream output;

    output  << Instruction::printInstruction()
            << std::bitset<::OPCODE_LENGTH>(this->Ra).to_string()
            << std::bitset<::I_T_IMM_LENGTH>(this->Immediate).to_string();
    return output.str();
}