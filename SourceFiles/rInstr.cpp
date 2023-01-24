#include "../HeaderFiles/rInstr.hpp"

Rinstr::Rinstr(const std::string & opcode, const int & lineNum , const int & Ra, const int & Rb, const int & funct)
    :Instruction::Instruction(opcode, lineNum)
{
    Rinstr::setInstruction(Ra, Rb, funct);
}

//----SetInstruction
void Rinstr::setInstruction(const int & Ra, const int & Rb, const int & funct){
    Rinstr::setRa(Ra);
    Rinstr::setRb(Rb);
    Rinstr::setFunct(funct);
}

//mutators for Ra, Rb and funct 
void Rinstr::setRa(const int & Ra){
     if((0 < Ra) && (16 > Ra))
        this->Ra = Ra;
    else {
        std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
    }
}

void Rinstr::setRb(const int & Rb){
     if((0 < Rb) && (16 > Rb))
        this->Rb = Rb;
    else {
        std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
    }
}


void Rinstr::setFunct(const int & funct){
     if((0 < funct) && (16 > funct))
        this->funct = funct;
    else {
        std::cout << "Syntax Error"; 
        throw std::invalid_argument("Source Operand cannot be greater/lesser than 16/0");
    }
}


//----accessors for Ra, Rb and funct

const int & Rinstr::getRa() const{
    return this->Ra;
}

const int & Rinstr::getRb() const{
    return this->Rb;
}

const int & Rinstr::getFunct() const{
    return this->funct;
}

 const std::string & Rinstr::printInstruction() const {
    std::stringstream output; 
    output << Instruction::printInstruction << std::bitset<::OPCODE_LENGTH>(Rinstr::getRa()).to_string() 
                                            << std::bitset<::OPCODE_LENGTH>(Rinstr::getRb()).to_string() 
                                            << std::bitset<::OPCODE_LENGTH>(Rinstr::getFunct()).to_string();
    return output.str();
 }
