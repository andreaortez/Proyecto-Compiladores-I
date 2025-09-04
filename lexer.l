%option noyywrap nodefault
%option yylineno nounput noinput

%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include "parser.hpp"

#define YY_DECL int yylex( yy::parser::semantic_type* yylval )

using yy::parser;
using token = yy::parser::token;

static int cont_comments = 0;
%}

/* comentarios anidados */
%x C_COMMENT

SPACE     [ \t\r\f\v]+
ID        [A-Za-z_][A-Za-z0-9_]*
INT       [0-9]+
FLOAT     [0-9]+\.[0-9]+
CHAR      \'([^\\'\n]|\\.)\'
STRING    \"([^\\\"\n]|\\.)*\"
CTRL      [\x00-\x08\x0B\x0C\x0E-\x1F\x7F]

%%  

{SPACE}         ;
"//".*          ;
\n              ;

"/*"                 { cont_comments = 1; BEGIN(C_COMMENT); }
<C_COMMENT>"/*"      { ++cont_comments; }
<C_COMMENT>"*/"      { if (--cont_comments == 0) BEGIN(INITIAL); }
<C_COMMENT>\n        { ++yylineno; }
<C_COMMENT>.         { /* consumir */ }
<C_COMMENT><<EOF>>   {
                        std::fprintf(stderr,
                          "[lex] comentario de bloque sin cerrar (linea %d)\n",
                          yylineno);
                        return 0;
                      }

{CTRL}+        ;

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
"*"             { return token::MULTIPLY;  }
"/"             { return token::DIVIDE; }

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

{FLOAT} { 
    yylval->emplace<double>( atof(yytext) );                 
    return token::FLOAT_LIT; 
}

{INT} {
    yylval->emplace<long long>( atoll(yytext) );             
    return token::INT_LIT;   
}

{CHAR} {
  char val = 0;
  if (yytext[1] == '\\') {
    switch (yytext[2]) {
      case 'n':  val = '\n'; break;
      case 't':  val = '\t'; break;
      case 'r':  val = '\r'; break;
      case '\\': val = '\\'; break;
      case '\'': val = '\''; break;
      case '\"': val = '\"'; break;
      default:   val = yytext[2]; break;
    }
  } else {
    val = yytext[1];
  }
  yylval->emplace<char>(val);
  return token::CHAR_LIT;
}

{STRING} {
  std::string s(yytext + 1, yyleng - 2);
  yylval->emplace<std::string>(std::move(s));
  return token::STR_LIT;
}

{ID} { 
    yylval->emplace<std::string>( yytext );                  
    return token::IDENT;     
}

.               { std::fprintf(stderr,
                    "Error lexico (linea %d): '%s'\n", yylineno, yytext); }

%%  /* fin */
