#include "Driver.hpp"
#include "Expression.hpp"
#include "CalculateVisitor.hpp"
#include "parser.parser.hh"
#include "location.hh"
#include <iostream>
#include <tclap/CmdLine.h>
#include <vector>
#include <fstream>
#include <set>


using namespace Calculator;

Expression* parsed_expr = nullptr;
Driver driver(&parsed_expr);
CalculateVisitor visitor;

const std::set<char> ops = {'+', '-', '*', '/'};


void print_error(Parser::syntax_error& err)
{
    std::cout << err.location << ": Error: " << err.what() << std::endl;
}

void print_error(CalculateVisitor::math_error& err)
{
    std::cout << "Error: " << err.what() << std::endl;
}

int interactive(double value = 0)
{
    std::string line;

    // TODO: Implement 'undo' and 'redo'
    while(std::getline(std::cin, line) && !line.empty())
    {
        if(ops.find(line[0]) != ops.end())
            line = to_string(value) + line;

        try
        {
            if(!driver.parse(line))
            {
                parsed_expr->Accept(visitor);
                value = visitor.Result();
            }
        }
        catch(Parser::syntax_error& err)
        {
            print_error(err);
        }
        catch(CalculateVisitor::math_error& err)
        {
            print_error(err);
        }

        delete(parsed_expr);
        std::cout << ": " << value << std::endl;

    }
    return 0;
}

int parse_string(std::string input, bool cont_interactive = false)
{
    double value = 0;
    int fail = 0;

    try
    {
        fail = driver.parse(input);

        if(!fail)
        {
            parsed_expr->Accept(visitor);
            value = visitor.Result();
        }

    }
    catch(Parser::syntax_error& err)
    {
        print_error(err);
    }
    catch(CalculateVisitor::math_error& err)
    {
        print_error(err);
    }

    delete(parsed_expr);
    std::cout << ": " << value << std::endl;

    if(cont_interactive)
        return interactive(value);
    else
        return fail;
}

int parse_file(std::string filename, bool cont_interactive = false)
{
    int fail = 0;
    double value = 0;
    std::ifstream ifs;

    ifs.open(filename, std::ifstream::in);
    if(!ifs.good())
    {
        std::cout << "Error: Failed to open file \'" << filename << "\'" << std::endl;
        ifs.close();
        if(!cont_interactive)
            return 1;
    }

    try
    {
        fail = driver.parse(&ifs, &filename);

        if(!fail)
        {
            parsed_expr->Accept(visitor);
            value = visitor.Result();
        }
    }
    catch(Parser::syntax_error& err)
    {
        print_error(err);
    }
    catch(CalculateVisitor::math_error& err)
    {
        print_error(err);
    }

    delete(parsed_expr);
    std::cout << ": " << value << std::endl;

    ifs.close();

    if(cont_interactive)
        return interactive(value);
    else
        return fail;
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        // Start interactive mode
        return interactive();
    }
    else
    {
        try
        {
            TCLAP::CmdLine cmd("A simple calculator", ' ', "0.1");

            TCLAP::ValueArg<string> fileArg("f", "file", "File to parse", false, "", "string");
            TCLAP::ValueArg<string> stringArg("s", "string", "String to parse", false, "", "string");
            TCLAP::UnlabeledValueArg<string> nfStringArg("nfString", "String to parse ( same as -s <string> )", false, "", "string");
            TCLAP::SwitchArg interactiveSwitch("i", "interactive", "Interactive mode", cmd);

            std::vector<TCLAP::Arg*> allArgs = {&fileArg, &stringArg, &nfStringArg};
            cmd.xorAdd(allArgs);

            cmd.parse(argc, argv);

            if(fileArg.isSet())
                return parse_file(fileArg.getValue(), interactiveSwitch.getValue());
            else if(stringArg.isSet())
                return parse_string(stringArg.getValue(), interactiveSwitch.getValue());
            else if(nfStringArg.isSet())
                return parse_string(nfStringArg.getValue(), interactiveSwitch.getValue());
            else if(interactiveSwitch.isSet() && interactiveSwitch.getValue())
                return interactive();
            else
            {
                // THIS SHOULD NOT HAPPEN
                std::cerr << "Something went wrong!" << std::endl;
                return 1;
            }
        }
        catch(TCLAP::ArgException &e)
        {
            std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
            return 1;
        }
    }
}
