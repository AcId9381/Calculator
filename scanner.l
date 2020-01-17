%{
    #include <iostream>
    #include <string>
    #include "Scanner.hpp"
    #include "parser.parser.hh"
    #include "Driver.hpp"
    #include "location.hh"

    using namespace Calculator;
    using namespace std;


    // Original yyterminate() macro returns int. Since we're using Bison 3 variants
    // as tokens, we must redefine it to change type from `int` to `Parser::semantic_type
    #define yyterminate() Parser::make_END(loc);


	// This will update location before the action for matched rule is executed.
	// Action is called when length of the token is known.
    #define YY_USER_ACTION loc.step(); loc.columns(yyleng);
%}

%option c++
%option nodefault
%option batch
%option noyywrap
%option yyclass="Scanner"

%%

    /* INTEGER */
[0-9]+ { return Parser::make_INT( stoi(yytext), loc ); }

    /* FLOAT */
[0-9]+"."[0-9]* {  return Parser::make_FLOAT( stof(yytext), loc ); }

    /* IDENTIFIER */
[[:alpha:]]+[[:alnum:]]* {  return Parser::make_ID( string(yytext), loc ); }

    /* ADDITION */
"+" { return Parser::make_ADD( loc ); }

    /* SUBTRACTION */
"-" { return Parser::make_SUB( loc ); }

    /* MULTIPLICATION */
"*" {  return Parser::make_MULT( loc ); }

    /* DIVISION */
"/" {  return Parser::make_DIV( loc ); }

    /* POWER */
"^"|"**" {  return Parser::make_POW( loc ); }

    /* ROOT */
"//" { return Parser::make_ROOT( loc ); }

    /* ASSIGNMENT */
"=" { return Parser::make_ASS( loc ); }

    /* LEFT PARENTHESIS */
"(" {  return Parser::make_LPAR( loc ); }

    /* RIGHT PARENTHESIS */
")" {  return Parser::make_RPAR( loc ); }

    /* WHITESPACE CHAR */
[ \t\r] { }

    /* NEWLINE */
(\r\n|\n) { loc.lines(); }

    /* END OF FILE */
<<EOF>> { return yyterminate(); }

    /* UNMATHCED */
. { std::cout << loc << ": Unrecognized symbol: " << string(yytext) << endl; }
