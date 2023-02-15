#include "./Instruction.hpp"

#ifndef MINSTR_H
#define MINSTR_H
    class Minstr : public Instruction
    {
        private:
            int Ra, Rb, Immediate;
        
        public:
            Minstr() = default;
            Minstr(const std::string &, const int &, const int &, const int &, const int &);

            //accessors
            const int & getRa() const;
            const int & getRb() const;
            const int & getImmediate() const;

            //mutators
            Minstr & setRa(const int &);
            Minstr & setRb(const int &);
            Minstr & setImmediate(const int &);

            //SetInstruction to call memberFunctions
            void setInstruction( const int &, const int &, const int &);

            //printInstruction Virtual Function
            virtual  std::string  printInstruction() const;
    };
#endif