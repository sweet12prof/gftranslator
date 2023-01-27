#include "./Instruction.hpp"

#ifndef BINSTR_H
#define BINSTR_H
    class Binstr : public Instruction
    {
        public:
            Binstr() = default;
            Binstr(const std::string &, const int &, const int &, const int &);
        
        //---accessors
            const int & getRa() const;
            const int & getImmediate() const;
            const int & getFunct() const;

        //---mutators
            void setRa(const int &);
            void setImmediate(const int &);
            void setFunct(const int &);

        //---setInstruction Function
            void setInstruction( const int &, const int &, const int &);

        //---VirtualFunction Oveeride
            virtual  std::string  printInstruction() const; 
 
        private: 
            int Ra, Immediate, funct;
        
    };
#endif