#include "parser.hpp"
#include "ast.hpp"
#include "ast_print.hpp"
#include <memory>
#include <string>
#include <cstdio>

extern int yylexerrs;

int main(int argc, char **argv)
{
    bool print_ast = (argc > 1) && (std::string(argv[1]) == "-p" || std::string(argv[1]) == "--print-ast");

    std::unique_ptr<ast::Program> root;
    yy::parser p(root);
    int rc = p.parse();

    int failed = (rc != 0) || (yylexerrs != 0);

    if (!failed)
    {
        if (print_ast && root)
            ast::print(*root, std::cout, 0);
        else
            std::puts("COMPILADO REALIZADO EXITOSAMENTE");
    }
    else
    {
        std::puts("ERROR");
    }
    return failed ? 1 : 0;
}
