#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED
#include <string>
#include <fstream>
#include "Expression.hpp"
#include "Driver.hpp"

namespace Calculator
{

class Calculator
{
    public:
        Calculator();
        virtual ~Calculator();
        int calc(std::string input, bool cont_interactive = false);
        int calc(std::ifstream input, bool cont_interactive = false);
        int calc(double start_value);

    protected:

    private:
        Expression* expr;
        Driver driver;
        CalculateVisitor visitor;

        void printError();

};

} // namespace Calculator

#endif // CALCULATOR_HPP_INCLUDED
