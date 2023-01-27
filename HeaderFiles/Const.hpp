#include <map>
#include <string>


#ifndef CONST_HPP
#define CONST_HPP
  const std::map < std::string, std::pair<int, std::pair<int, int>>> instMap{
        {"ands",       {0, {0, 2}}}, 
        {"andv",       {0, {0, 3}}},
        {"nop",        {0, {0, 0}}},
        {"ors",        {0, {0, 4}}}, 
        {"orv",        {0, {0, 5}}}, 
        {"xors",       {0, {0, 6}}}, 
        {"xorv",       {0, {0, 7}}}, 
        {"muls",       {0, {0, 8}}}, 
        {"mulv",       {0, {0, 9}}}, 
        {"divs",       {0, {0, 10}}}, 
        {"divv",       {0, {0, 11}}}, 
        {"srs",        {0, {0, 12}}}, 
        {"srv",        {0, {0, 13}}}, 
        {"mvs",        {0, {0, 14}}}, 
        {"mvv",        {0, {0, 15}}}, 
        {"addi",       {1, {1, -1}}}, 
        {"addiu",      {1, {2, -1}}}, 
        {"jr",         {1, {3, -1}}},
        {"dupis",      {1, {4, -1}}},
        {"dupiv",      {1, {5, -1}}},
        {"lbI",        {1, {6, -1}}},
        {"beq",        {2, {7, 2} }}, 
        {"beqdec",     {2, {7, 3} }},
        {"bne",        {2, {7, 0} }}, 
        {"bnedec",     {2, {7, 1} }},
        {"lds",        {3, {8, -1}}}, 
        {"stos",       {3, {9, -1}}},
        {"ldv",       {3, {10, -1}}}, 
        {"stov",      {3, {11, -1}}},  
        {"setfx",     {4, {12, 0}}}, 
        {"j",         {4, {12, 2}}},
        {"jal",       {4, {12, 3}}},
        {"setstride", {4, {12, 4}}}, 
        {"setmvtype", {4, {12, 5}}}, 
        {"setsrtype", {4, {12, 1}}}
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
    const unsigned int B_T_FUNCT_LENGTH = 2;
#endif