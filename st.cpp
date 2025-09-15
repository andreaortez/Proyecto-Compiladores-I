#include "parser.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

extern int yylex(yy::parser::semantic_type *yylval);
extern FILE *yyin;
extern int yylineno;
extern char *yytext;
extern int yyleng;

static string tok_name(int token)
{
    using tk = yy::parser::token;
    switch (token)
    {
    // palabras clave
    case tk::LET:
        return "LET";
    case tk::CONST:
        return "CONST";
    case tk::MUT:
        return "MUT";
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
    case tk::BREAK:
        return "BREAK";
    case tk::CONTINUE:
        return "CONTINUE";
    case tk::IN:
        return "IN";
    case tk::AS:
        return "AS";
    case tk::LOOP:
        return "LOOP";
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
        return "MULTIPLY";
    case tk::DIVIDE:
        return "DIVIDE";
    case tk::MULEQ:
        return "MULEQ";
    case tk::DIVEQ:
        return "DIVEQ";
    case tk::PLUSEQ:
        return "PLUSEQ";
    case tk::MINEQ:
        return "MINEQ";
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
    case tk::RANGE:
        return "RANGE";
    case tk::RANGE_EQ:
        return "RANGE_EQ";
    // comparadores
    case tk::LT:
        return "LT";
    case tk::LEQ:
        return "LEQ";
    case tk::GT:
        return "GT";
    case tk::GEQ:
        return "GEQ";
    case tk::EQ:
        return "EQ";
    case tk::NEQ:
        return "NEQ";

    default:
        return "tok#" + to_string(token); // fallback
    }
}

int main(int argc, char **argv)
{
    if (argc > 1 && strcmp(argv[1], "-") != 0)
    {
        yyin = fopen(argv[1], "rb");
        if (!yyin)
        {
            perror("fopen");
            return 1;
        }
    }

    cout << left
         << setw(6) << "LINE"
         << setw(15) << "TOKEN"
         << setw(24) << "LEXEME"
         << "VALUE\n";
    cout << string(6 + 15 + 24 + 5, '-') << "\n";

    yy::parser::semantic_type yylval;
    while (true)
    {
        int token = yylex(&yylval);
        if (token == 0) // EOF
            break;

        string name = tok_name(token);
        string lex = yytext ? string(yytext, yyleng) : "";
        string val;

        using tk = yy::parser::token;
        switch (token)
        {
        case tk::IDENT:
        case tk::STR_LIT:
            val = yylval.as<string>();
            break;
        case tk::INT_LIT:
            val = to_string(yylval.as<long long>());
            break;
        case tk::FLOAT_LIT:
        {
            ostringstream oss;
            oss << yylval.as<double>();
            val = oss.str();
            break;
        }
        case tk::CHAR_LIT:
            val = string(1, yylval.as<char>());
            break;
        default:
            break;
        }

        cout << left
             << setw(6) << yylineno
             << setw(15) << name
             << setw(24) << lex
             << val << "\n";
    }

    if (yyin && yyin != stdin)
        fclose(yyin);
    return 0;
}