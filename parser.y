%require "3.2"
%language "c++"
%defines
%define api.namespace {Calculator}
%define api.parser.class {Parser}
%define api.token.constructor
%define api.value.type variant
%define parse.error verbose
%locations

%lex-param {Calculator::Scanner& scanner}
%parse-param  {Calculator::Scanner& scanner}
%parse-param {Calculator::Expression** result}


%code requires
{
    #include "ArithExpr.hpp"
    #include "CalculateVisitor.hpp"
    #include <iostream>

    namespace Calculator {
    class Scanner;
    class Driver;
    }

    using namespace std;
}

%code
{
    #include "Scanner.hpp"
    #include "parser.parser.hh"
    #include "Driver.hpp"
    #include "location.hh"


    static Calculator::Parser::symbol_type yylex(Calculator::Scanner &scanner) {
        return scanner.get_next_token();
    }

}


%token END 0 "end of file"
%token <int> INT "integer"
%token <double> FLOAT "floating point"
%token <string> ID "identifier"
%token ADD "addition operator"
%token SUB "subtraction operator"
%token MULT "multiplication operator"
%token DIV "division operator"
%token POW "power operator"
%token ROOT "root operator"
%token ASS "assignment operator"
%token LPAR "left parenthesis"
%token RPAR "right parenthesis"

%type <Expression*> Exp

%right ASS
%left ADD SUB
%left MULT DIV
%left POW ROOT
%right UMINUS
%left UROOT UPOW

%%

input
    : Exp                   { *result = $1;                 }

Exp
    : ID ASS Exp            { $$ = new AssExpr($1, $3);     }
    | ID                    { $$ = new NameExpr($1);        }
    | LPAR Exp RPAR         { $$ = new ParExpr($2);         }
    | Exp ADD Exp           { $$ = new AddExpr($1, $3);     }
    | Exp SUB Exp           { $$ = new SubExpr($1, $3);     }
    | Exp MULT Exp          { $$ = new MultExpr($1, $3);    }
    | Exp DIV Exp           { $$ = new DivExpr($1, $3);     }
    | Exp POW Exp           { $$ = new PowExpr($1, $3);     }
    | Exp POW               { $$ = new SquareExpr($1);      }
    | Exp ROOT Exp          { $$ = new RootExpr($1, $3);    }
    | Exp ROOT %prec UROOT  { $$ = new SqrtExpr($1);        }
    | INT                   { $$ = new NumExpr((double)$1); }
    | FLOAT                 { $$ = new NumExpr($1);         }


%%

// Bison expects us to provide implementation - otherwise linker complains
void Calculator::Parser::error(const location &loc , const std::string &message) {

    throw syntax_error(loc, message);
}
