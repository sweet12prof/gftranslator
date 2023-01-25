#include "./Instruction.hpp"

#ifndef JINSTR_H
#define JINSTR_H
    class Jinstr : public Instruction
    {
        private:
            int immediate, funct;
        
        public:
            Jinstr() = default;
            Jinstr(const std::string & ,const int &, const int &, const int &);

            //accessors 
            const int & getImmediate() const;
            const int & getFunct() const;

            //mutators
            Jinstr&     setImmediate(const int &);
            Jinstr&     setFunct(const int &);

            //setInstruction to call member functions
            void setInstruction(const int &, const int &);

            //Virtual printInstruction
            virtual std::string printInstruction() const;
           
    };
#endif