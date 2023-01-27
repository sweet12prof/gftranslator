cmake_minimum_required(VERSION 3.25)
project (
            GfTranslator
            VERSION 0.0
            DESCRIPTION "Translator for Galois Field ASIP"
            LANGUAGES CXX
)

add_executable(
    GfTranslator 
    main.cpp
    SourceFiles/Assembler.cpp  
    SourceFiles/Binstr.cpp  
    SourceFiles/Iinstr.cpp  
    SourceFiles/Instruction.cpp  
    SourceFiles/Jinstr.cpp  
    SourceFiles/Minstr.cpp  
    SourceFiles/rInstr.cpp
)

target_compile_features(GfTranslator PRIVATE cxx_std_20)

target_include_directories(GfTranslator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/HeaderFiles)
