#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "./InstrIncludes.hpp"

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

class Assembler {
    public: 
        Assembler (const std::string &);
        // parse a string removing labels and extra white space
        std::string processString(const std::string &);
        std::string replaceLabels(const std::string &, const int &);
        std::string translate(const std::string &, const int &);
        
        std::ofstream output;
        std::ifstream input;

        

    private:
        std::unordered_map<std::string, int> labelRefTable;
        std::streampos  fileByteCount;
        std::string     fileDir;
        int lineCount;
};


#endif