#include "Assembler.hpp"

Assembler::Assembler(const std::string & filedir)
    :lineCount{0}, fileByteCount{0}, outputDir{"/home/cnutsukpui/Desktop/Work-Thesis-/GF_ASIP/GF_ASIP.sim/someasm2.txt"}, fileDir{filedir}
{
    Assembler::input.open(filedir);
    if(!Assembler::input)
        {
            std::cerr << "File doesnot exist at specified directory/Is Invalid/noRead Permissions";
            exit(EXIT_FAILURE);
        }
    Assembler::input.close();
    Assembler::output.open(this->outputDir);
    Assembler::output.close();

    // std::cout << int(this->eof_of_file) <<  std::endl << int (this->fileByteCount);
}

std::string Assembler::processString(const std::string & lineIn){
    std::string token = "";
    std::stringstream output;
    int i{0};
    for (auto item : lineIn)
        {
            switch(item){
                case ':' :
                        std::transform(token.begin(), token.end(), token.begin(), 
                        [](unsigned char c) {
                            return std::tolower(c);
                        });
                   // std::cout << "token is: " << token << std::endl;
                    this->labelRefTable.insert(std::make_pair(token, this->lineCount));
                    token = "";
                break;

                case ' ' :
                    std::transform(token.begin(), token.end(), token.begin(), 
                        [](unsigned char c) {
                            return std::tolower(c);
                        });
                    output << token.append(" ");
                    token = "";
                break;

                case '(' :
                    std::transform(token.begin(), token.end(), token.begin(), 
                        [](unsigned char c) {
                            return std::tolower(c);
                        });
                    output << token.append(" ");
                    token = "";
                break;

                case ')' :
                    std::transform(token.begin(), token.end(), token.begin(), 
                        [](unsigned char c) {
                            return std::tolower(c);
                        });
                    output << token.append(" ");
                    token = "";
                break;

                case '$' :
                break;

                case '.' :
                break;

                case ',' :
                break;

                case '_':
                break;


                default: {
                        token += item; 
                        if(i == lineIn.size() - 1)
                           { 
                            std::transform(token.begin(), token.end(), token.begin(), [](unsigned char c) {
                                return std::tolower(c);
                            });
                         output << token;    
                        }
                }

            }
            i++;
        }

        bool empty = true;
        // if (output.str() == "") empty 
         for (auto item : output.str())
            if(item != ' ')
                empty = false;

        if (!empty) 
           this->lineCount++;

   // std::cout << "Output of process string is " << output.str() << std::endl; 
    return output.str();
}
  

int Assembler::replaceLabels(const std::string& label_, const int & lineNum){

    std::string label{label_};

    std::transform(label.begin(), label.end(), label.begin(), 
                        [](unsigned char c) {
                            return ::tolower(c);
                        });
    if(auto p = this->labelRefTable.find(label); p == this->labelRefTable.end())
        {
            std::cout << "Undefined label:  " << label << "at line: " << lineNum << std::endl;
            throw std::invalid_argument("Syntax Error");
        }
    else 
       {   //std::cout << "p->second is " << p->second << " linenum is " << lineNum; 
       
       return p->second - lineNum;
       
       }
}


std::string Assembler::translate(const std::string & instr, const int & LineNum){
    std::stringstream ss; 
    
    ss.str(instr);
    std::string opCode;
    ss >> opCode;

    std::transform(opCode.begin(), opCode.end(), opCode.begin(), 
                        [](unsigned char c) {
                            return ::tolower(c);
                        });

    Instruction *basePtr = new Instruction{opCode, LineNum};
    Instruction *basePtr2; 
    std::string op, immediateLabel; 
    int ra, rb, funct, immediate;
    ss.str("");
    ss.str(instr);
    
    switch(basePtr->getType())
        {
            case instrTypes::R_TYPE:
                ss >> op >> ra >> rb ;
                basePtr2 = new Rinstr{op, LineNum, ra, rb};
                //std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;

            case instrTypes::I_TYPE:
                ss >> op >> ra >> immediate;
                basePtr2 = new Iinstr{op, LineNum, ra, immediate};
              //  std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;

            case instrTypes::B_TYPE:
                ss >> op >> ra >> immediateLabel;
                immediate = Assembler::replaceLabels(immediateLabel, LineNum-1);
                basePtr2 = new Binstr {op, LineNum, ra, immediate};
                //std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;


            case instrTypes::M_TYPE:
                ss >> op >> ra >>  immediate >> rb;
                basePtr2 =  new Minstr{op, LineNum, ra, rb, immediate};
               // std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;

            case instrTypes::J_TYPE:
                if(opCode == "j" || opCode == "jal")
                    {
                        ss >> op >> immediateLabel;
                        immediate = Assembler::replaceLabels(immediateLabel, LineNum-1);
                    }
                else 
                    {ss >> op >> immediate; //std::cout << "op is " << op << "immediate: " << immediate << std::endl;
                    }

                basePtr2 = new Jinstr {op, LineNum, immediate};
               // std::cout << basePtr2->printInstruction();
                return basePtr2->printInstruction();
            break;

            default: {
                    throw std::invalid_argument ("Invalid Instruction");
                  //  return "Syntax Error";
            }
        }
}


void Assembler::processInstrucQueue(std::vector<std::string> & Queue){
    int i{1};

    for (auto & p : Queue)
            p = Assembler::processString(p);

    // for (auto & p : Queue)
    //     std::cout << p << std::endl;

    for(auto & p : Queue){
        p = Assembler::translate(p, i);
        ++i;
    }
}


std::vector <std::string> Assembler::readASMFile() {
    std::string instrucLine;
    std::vector<std::string> instrucQueue;

    Assembler::input.open(this->fileDir);
    Assembler::input.seekg(this->fileByteCount);
    int maxLinestoRead{0};
   
   while ( maxLinestoRead <20 && std::getline(Assembler::input, instrucLine))
     {  
            this->i_streameofbit =  Assembler::input.eof();
                if(instrucLine != "")
                    {
                        instrucQueue.push_back(instrucLine);
                        ++maxLinestoRead; 
                    }

    }
    this->fileByteCount = Assembler::input.tellg();
    input.close();
    return instrucQueue;
}


void Assembler::processAsmFile(std::vector<std::string> & queue){
    Assembler::processInstrucQueue(queue);
    Assembler::output.open(this->outputDir, std::ios::app); 
    for(auto p : queue)
        Assembler::output << std::setw(4) << std::setfill('0') << std::hex  << std::bitset<16>(p).to_ulong() << std::endl;
    //Assembler::output << std::setw(4) << std::setfill('0')  << std::bitset<16>(p) << std::setfill(' ') << "\t\t\t\t"  << "0x" << std::setfill('0') << std::setw(4) << std::hex << std::bitset<16>(p).to_ulong()  << std::endl;
    Assembler::output.close();
}


void Assembler::Assemble(){
   std::vector <std::string>instrucQ, buff;
   while(!this->i_streameofbit){
        buff = Assembler::readASMFile();
        instrucQ.insert(instrucQ.end(), buff.begin(), buff.end());
   }
    Assembler::processAsmFile(instrucQ);
}
