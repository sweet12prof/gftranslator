#include "./Instruction.hpp"

#ifndef IINSTR_H
#define IINSTR_H
    class Iinstr : public Instruction
    {
        private:
            int Ra, Immediate; 
        public:
        //Constructors
            Iinstr() = default;
            Iinstr(const std::string &, const int, const int &, const int &);

        //accessors 
            const int & getRa () const;
            const int & getImmediate() const;

        //mutators
            void setRa(const int &);
            void setImmediate(const int &);

        //Virtual Function to return binary representation
            virtual std::string  printInstruction() const;

        //cUSTOM Function to call set memberFunctions
            void setInstruction (const int &, const int &);
    
    };
#endif