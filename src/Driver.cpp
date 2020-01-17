#include "Driver.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace Calculator {

Driver::Driver()
    : scanner(), parser(scanner, result_ptr)
{
    //ctor
}

Driver::Driver(Expression** out_ptr)
    : result_ptr(out_ptr), scanner(), parser(scanner, result_ptr)
{
    //ctor
}

Driver::~Driver()
{
    //dtor
}

int Driver::parse()
{
    return parser.parse();
}

int Driver::parse(std::string input)
{
    scanner.loc = location();
    std::istringstream iss(input);
    switchInputStream(&iss);
    return parse();
}

int Driver::parse(std::ifstream *input)
{
    scanner.loc = location();
    switchInputStream(input);
    return parse();
}

int Driver::parse(std::ifstream *input, std::string* filename)
{
    scanner.loc = location(filename);
    switchInputStream(input);
    return parse();
}


void Driver::switchInputStream(std::istream* is)
{
    scanner.switch_streams(is, NULL);
}


} // namespace Calculator
