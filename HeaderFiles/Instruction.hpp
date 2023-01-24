#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset> 
#include <Const.hpp>
#include <stdexcept>

#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

class Instruction
{
private:
    int opCode;
    instrTypes type;

public:
    Instruction() = default;
    Instruction( const std::string &, const int &);
    virtual ~Instruction() = default;

    //---public function to init a instruction Object
    void setInstruction(const std::string &, const int &);

    //---access and muttators for Opcode 
    void setOpCode(const int &);
    const int & getOpCode() const;

    //-----access and mutators forinstrTypes
    void setType(const int &);
    const instrTypes & getType() const;
    
    //-----Virtual Func to return machine 
    //---- representation of object - prints only opcode from base calss
    virtual const std::string & printInstruction() const; 
};


#endif
