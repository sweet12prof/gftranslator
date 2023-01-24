#include "Instruction.hpp"

#ifndef RINSTR_H
#define RINSTR_H

class Rinstr : public Instruction{
    private:
        int Ra, Rb, funct;
    public:
        //Constructor
        Rinstr() = default;
        Rinstr(const std::string &, const int &, const int &, const int &, const int &);
        
        //---access and mutators for Ra
        void setRa(const int &);
        const int & getRa() const;

        //----access and mutators for Rb
        void setRb(const int &);
        const int & getRb() const;

        //----access and mutators for type
        void setFunct(const int &);
        const int & getFunct() const;

        //---setInstruction
        void setInstruction(const int &, const int &, const int &);

        ///--VirtualOVerride of print Function
        virtual const std::string & printInstruction() const ; 
         
};

#endif