#include "Calculator.hpp"

namespace Calculator {

Calculator::Calculator()
{
    //ctor
}

Calculator::~Calculator()
{
    //dtor
}

int Calculator::calc(std::string input, bool cont_interactive)
{
    double value = 0;
    int fail = 0;

    try
    {
        fail = driver.parse(input);

        if(!fail)
        {
            expr->Accept(visitor);
            value = visitor.Result();
        }

    }
    catch(Parser::syntax_error& err)
    {
//        printError(err);
    }
    catch(CalculateVisitor::math_error& err)
    {
        //printError(err);
    }

    delete(expr);
    std::cout << ": " << value << std::endl;

    if(cont_interactive)
        return calc(value);
    else
        return fail;
}

int Calculator::calc(std::ifstream input, bool cont_interactive)
{
    int fail = 0;
    double value = 0;
    std::ifstream ifs;

//    ifs.open(filename, std::ifstream::in);
    if(!ifs.good())
    {
//        std::cout << "Error: Failed to open file \'" << filename << "\'" << std::endl;
        ifs.close();
        if(!cont_interactive)
            return 1;
    }

    try
    {
//        fail = driver.parse(&ifs, &filename);

        if(!fail)
        {
            expr->Accept(visitor);
            value = visitor.Result();
        }
    }
    catch(Parser::syntax_error& err)
    {
//        print_error(err);
    }
    catch(CalculateVisitor::math_error& err)
    {
//        print_error(err);
    }

    delete(expr);
    std::cout << ": " << value << std::endl;

    ifs.close();

    if(cont_interactive)
        return calc(value);
    else
        return fail;
}

int Calculator::calc(double start_value)
{

}

} // namespace Calculator
