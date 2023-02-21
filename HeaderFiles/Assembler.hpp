#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "./InstrIncludes.hpp"

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

class Assembler {
    public: 
        Assembler (const std::string &, const std::string &);

        // parse a string removing labels and extra white space
        std::string processString(const std::string &);
        int replaceLabels(const std::string &, const int &);
        std::string translate(const std::string &, const int &);
        void processInstrucQueue(std::vector<std::string> &);

        //ReadFile
        std::vector<std::string> readASMFile();
        void processAsmFile(std::vector<std::string> &); 
        void Assemble();
        
        std::ofstream output;
        std::ifstream input;
        bool          i_streameofbit;

        

    private:
        std::unordered_map<std::string, int> labelRefTable;
        std::streampos  fileByteCount;
        std::streampos  eof_of_file;
        std::string     fileDir;
        std::string     outputDir;
        int lineCount;
};


#endif