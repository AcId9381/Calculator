#ifndef DRIVER_HPP_INCLUDED
#define DRIVER_HPP_INCLUDED
#include <fstream>
#include <string>
#include "../parser.parser.hh"
#include "Scanner.hpp"


namespace Calculator {

class Expression;

class Driver
{
    public:
        Driver();
        Driver(Expression** out_ptr);
        virtual ~Driver();
        int parse();
        int parse(std::string input);
        int parse(std::ifstream* input);
        int parse(std::ifstream* input, std::string* filename);
        void switchInputStream(std::istream* is);

        friend class Parser;
        friend class Scanner;

    private:
        Expression** result_ptr;
        Scanner scanner;
        Parser parser;
};

} // namespace Calculator

#endif // DRIVER_HPP_INCLUDED
