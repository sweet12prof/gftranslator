#include <map>
#include <string>


#ifndef CONST_HPP
#define CONST_HPP
  const std::map < std::string, std::pair<int, int>> instMap{
        {"and",       {0, 0} }, 
        {"nop",       {0, 0} },
        {"or",        {0, 0} }, 
        {"xor",       {0, 0} }, 
        {"mul",       {0, 0} }, 
        {"div",       {0, 0} }, 
        {"sr",        {0, 0} }, 
        {"mv",        {0, 0} }, 
        {"addi",      {1, 1} }, 
        {"addiu",     {1, 2} }, 
        {"jr",        {1, 3} },
        {"dupis",     {1, 4} },
        {"dupiv",     {1, 5} },
        {"lbI",       {1, 6} },
        {"beq",       {2, 7} }, 
        {"beqdec",    {2, 7} },
        {"bne",       {2, 7} }, 
        {"bnedec",    {2, 7} },
        {"lds",       {3, 8} }, 
        {"stos",      {3, 9} },
        {"ldv",       {3, 10}}, 
        {"stov",      {3, 11}},  
        {"setfx",     {4, 12}}, 
        {"setstride", {4, 12}}, 
        {"setmvtype", {4, 12}}, 
        {"setsrtype", {4, 12}}
    };

    enum class instrTypes {
        R_TYPE = 0,
        I_TYPE, 
        B_TYPE, 
        M_TYPE, 
        J_TYPE 
    };

    const unsigned int OPCODE_LENGTH =4;
    const unsigned int INSTRUCTION_LENGTH=16;
    const unsigned int I_T_IMM_LENGTH = 8;
    const unsigned int B_T_IMM_LENGTH = 6;
    const unsigned int B_T_FUNCT_LENGTH = 6;
#endif