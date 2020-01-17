#ifndef SCANNER_HPP_INCLUDED
#define SCANNER_HPP_INCLUDED

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

/**
* Scanner method signature is defined by this macro. Original yylex() returns int.
* Sinice Bison 3 uses symbol_type, we must change returned type. We also rename it
* to something sane, since you cannot overload return type.
**/
#undef YY_DECL
#define YY_DECL Calculator::Parser::symbol_type Calculator::Scanner::get_next_token()

#include "../parser.parser.hh"
#include "../location.hh"

namespace Calculator
{
    class Scanner : public yyFlexLexer
    {
    public:
        location loc;

        Scanner() {};
        virtual ~Scanner() {};
        virtual Parser::symbol_type get_next_token();
    };
}

#endif // SCANNER_HPP_INCLUDED
