#include "parser.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

extern int yylex(yy::parser::semantic_type *yylval);
extern FILE *yyin;
extern int yylineno;
extern char *yytext;
extern int yyleng;

static std::string tok_name(int t)
{
    using tk = yy::parser::token;
    switch (t)
    {
    // palabras clave
    case tk::LET:
        return "LET";
    case tk::FN:
        return "FN";
    case tk::IF:
        return "IF";
    case tk::ELSE:
        return "ELSE";
    case tk::WHILE:
        return "WHILE";
    case tk::FOR:
        return "FOR";
    case tk::RETURN:
        return "RETURN";
    // tipos
    case tk::I32_T:
        return "I32_T";
    case tk::F64_T:
        return "F64_T";
    case tk::BOOL_T:
        return "BOOL_T";
    case tk::CHAR_T:
        return "CHAR_T";
    case tk::STR_T:
        return "STR_T";
    // literales e identificadores
    case tk::IDENT:
        return "IDENT";
    case tk::INT_LIT:
        return "INT_LIT";
    case tk::FLOAT_LIT:
        return "FLOAT_LIT";
    case tk::CHAR_LIT:
        return "CHAR_LIT";
    case tk::STR_LIT:
        return "STR_LIT";
    case tk::TRUE_LIT:
        return "TRUE_LIT";
    case tk::FALSE_LIT:
        return "FALSE_LIT";
    // lógicos/arimetica/símbolos
    case tk::AND:
        return "AND";
    case tk::OR:
        return "OR";
    case tk::NOT:
        return "NOT";
    case tk::PLUS:
        return "PLUS";
    case tk::MINUS:
        return "MINUS";
    case tk::MULTIPLY:
        return "STAR";
    case tk::DIVIDE:
        return "SLASH";
    case tk::LBRACE:
        return "LBRACE";
    case tk::RBRACE:
        return "RBRACE";
    case tk::LPAREN:
        return "LPAREN";
    case tk::RPAREN:
        return "RPAREN";
    case tk::LBRACK:
        return "LBRACK";
    case tk::RBRACK:
        return "RBRACK";
    case tk::COMMA:
        return "COMMA";
    case tk::SEMICOLON:
        return "SEMICOLON";
    case tk::COLON:
        return "COLON";
    case tk::ARROW:
        return "ARROW";
    case tk::ASSIGN:
        return "ASSIGN";
    // comparadores
    case tk::LT:
        return "LT";
    case tk::LE:
        return "LE";
    case tk::GT:
        return "GT";
    case tk::GE:
        return "GE";
    case tk::EQ:
        return "EQ";
    case tk::NE:
        return "NE";
    default:
        return "tok#" + std::to_string(t); // fallback
    }
}

int main(int argc, char **argv)
{
    if (argc > 1 && std::strcmp(argv[1], "-") != 0)
    {
        yyin = std::fopen(argv[1], "rb");
        if (!yyin)
        {
            std::perror("fopen");
            return 1;
        }
    }

    std::cout << std::left
              << std::setw(6) << "LINE"
              << std::setw(15) << "TOKEN"
              << std::setw(24) << "LEXEME"
              << "VALUE\n";
    std::cout << std::string(6 + 15 + 24 + 5, '-') << "\n";

    yy::parser::semantic_type yylval;
    while (true)
    {
        int t = yylex(&yylval);
        if (t == 0)
            break;

        std::string name = tok_name(t);
        std::string lex = yytext ? std::string(yytext, yyleng) : "";
        std::string val;

        using tk = yy::parser::token;
        switch (t)
        {
        case tk::IDENT:
        case tk::STR_LIT:
            val = yylval.as<std::string>();
            break;
        case tk::INT_LIT:
            val = std::to_string(yylval.as<long long>());
            break;
        case tk::FLOAT_LIT:
        {
            std::ostringstream oss;
            oss << yylval.as<double>();
            val = oss.str();
            break;
        }
        case tk::CHAR_LIT:
            val = std::string(1, yylval.as<char>());
            break;
        default:
            break;
        }

        std::cout << std::left
                  << std::setw(6) << yylineno
                  << std::setw(15) << name
                  << std::setw(24) << lex
                  << val << "\n";
    }

    if (yyin && yyin != stdin)
        std::fclose(yyin);
    return 0;
}