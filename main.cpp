#include <iostream>
#include <bitset>
#include <string>
#include "./HeaderFiles/Const.hpp"


int main(){
    std::bitset<::OPCODE_LENGTH> someNum(12);
    std::cout << someNum.to_string();
}