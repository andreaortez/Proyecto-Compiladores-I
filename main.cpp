#include "parser.hpp"
#include "ast.hpp"
#include <memory>
#include <cstdio>

int main() {
    std::unique_ptr<ast::Program> root;
    yy::parser p(root);
    int rc = p.parse();
    if (rc == 0) std::puts("OK");
    else         std::puts("ERROR");
    return rc;
}
