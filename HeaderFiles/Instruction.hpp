#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset> 

class Instruction
{
private:
    /* data */
    int opCode;
public:
    Instruction( const std::string &);
    virtual ~Instruction() = default;
    void setOpCode(const std::string &);
    virtual std::bitset<4> printInstruction(); 
};

