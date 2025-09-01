%option noyywrap nodefault
%option yylineno nounput noinput

%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include "parser.hpp"

#define YY_DECL int yylex(int* yylval)

using yy::parser;
using token = yy::parser::token;
%}

WS      [ \t\r\f\v]+
ID      [A-Za-z_][A-Za-z0-9_]*
INT     [0-9]+
FLOAT   [0-9]+\.[0-9]+
CHAR    \'([^\\'\n]|\\.)\'
STRING  \"([^\\\"\n]|\\.)*\"

%%

{WS}            ;
"//".*          ;
\n              ;

"let"           { return token::LET; }
"fn"            { return token::FN; }
"if"            { return token::IF; }
"else"          { return token::ELSE; }
"while"         { return token::WHILE; }
"for"           { return token::FOR; }
"return"        { return token::RETURN; }

"i32"           { return token::I32_T; }
"f64"           { return token::F64_T; }
"bool"          { return token::BOOL_T; }
"char"          { return token::CHAR_T; }
"str"           { return token::STR_T; }

"true"          { return token::TRUE_LIT; }
"false"         { return token::FALSE_LIT; }

"&&"            { return token::AND; }
"||"            { return token::OR;  }
"!"             { return token::NOT; }
"+"             { return token::PLUS;  }
"-"             { return token::MINUS; }
"*"             { return token::STAR;  }
"/"             { return token::SLASH; }

"{"             { return token::LBRACE; }
"}"             { return token::RBRACE; }
"("             { return token::LPAREN; }
")"             { return token::RPAREN; }
"["             { return token::LBRACK; }
"]"             { return token::RBRACK; }
","             { return token::COMMA; }
";"             { return token::SEMICOLON; }

":"             { return token::COLON; }
"->"            { return token::ARROW; }
"="             { return token::ASSIGN; }

{FLOAT}         { return token::FLOAT_LIT; }
{INT}           { return token::INT_LIT;   }
{CHAR}          { return token::CHAR_LIT;  }
{STRING}        { return token::STR_LIT;   }

{ID}            { return token::IDENT; }

.               { std::fprintf(stderr, "Error léxico (línea %d): '%s'\n", yylineno, yytext); }

%%
