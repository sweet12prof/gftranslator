#include "../HeaderFiles/Assembler.hpp"

Assembler::Assembler(const std::string & filedir)
{
    this->fileDir = filedir;
}

std::string Assembler::processString(const std::string & lineIn){
    std::string token = "";
    std::stringstream output;
     
    for (auto item : lineIn)
        {
            switch(item){
                case ':' :
                    this->labelRefTable.insert(std::make_pair(token, this->lineCount));
                    token = "";
                break;

                case ' ' :
                    output << token.append(" ");
                    token = "";
                break;

                case '(' :
                    output << token.append(" ");
                    token = "";
                break;

                case ')' :
                    output << token.append(" ");
                    token = "";
                break;

                case '$' :
                break;

                case '.' :
                break;

                case ',' :
                break;


                default: {
                        token += item; 
                        if(item ==  lineIn.back())
                            output << token;
                }

            }
        }

        bool empty = true;
         for (auto item : output.str())
            if(item != ' ')
                empty = false;

        if (!empty) 
           this->lineCount++;

    return output.str();
}


std::string Assembler::replaceLabels(const std::string& label, const int & lineNum){
    if(auto p = this->labelRefTable.find(label); p == this->labelRefTable.end())
        {
            std::cout << "Undefined label:  " << label << "at line: " << lineNum;
            throw std::invalid_argument("Syntax Error");
        }
}


std::string Assembler::translate(const std::string & instr, const int & LineNum){
    std::stringstream ss; 
    ss << instr;
    std::string opCode;
    ss >> opCode;
    Instruction *basePtr = new Instruction{opCode, LineNum};
    Instruction *basePtr2; 
    std::string op; 
    int ra, rb, funct, immediate;
    ss.clear();
    ss << instr;
    switch(basePtr->getType())
        {
            case instrTypes::R_TYPE:
                ss >> op >> ra >> rb >> funct;
                basePtr2 = new Rinstr{op, LineNum, ra, rb, funct};
                std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;

            case instrTypes::I_TYPE:
                ss >> op >> ra >> immediate;
                basePtr2 = new Iinstr{op, LineNum, ra, immediate};
                std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;

            case instrTypes::B_TYPE:
                ss >> op >> ra >> immediate >> funct;
                basePtr2 = new Binstr {op, LineNum, ra, immediate, funct };
                std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;


            case instrTypes::M_TYPE:
                ss >> op >> ra >> rb >> immediate;
                basePtr2 =  new Minstr{op, LineNum, ra, rb, immediate};
                std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;

            case instrTypes::J_TYPE:
                ss >> op >> immediate >> funct;
                basePtr2 = new Jinstr {op, LineNum, immediate, funct};
                std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;

            default: {
                    throw std::invalid_argument ("Invalid Instruction");
                  //  return "Syntax Error";
            }

        }

}


