#pragma once
#include <memory>
#include <string>
#include <vector>

namespace ast
{

    struct Node
    {
        virtual ~Node() = default;
    };

    /*** Expresiones ***/
    enum class BinOp
    {
        Add,
        Sub,
        Mul,
        Div,
        And,
        Or,
        Assign
    };

    enum class UnOp
    {
        Pos,
        Neg,
        Not
    };

    struct Expr : Node
    {
    };

    struct Ident : Expr
    {
        std::string name;
        explicit Ident(std::string s) : name(std::move(s)) {}
    };

    struct IntLit : Expr
    {
        long long v;
        explicit IntLit(long long x) : v(x) {}
    };

    struct FloatLit : Expr
    {
        double v;
        explicit FloatLit(double x) : v(x) {}
    };

    struct CharLit : Expr
    {
        char v;
        explicit CharLit(char c) : v(c) {}
    };

    struct StringLit : Expr
    {
        std::string v;
        explicit StringLit(std::string s) : v(std::move(s)) {}
    };

    struct BoolLit : Expr
    {
        bool v;
        explicit BoolLit(bool b) : v(b) {}
    };

    struct Unary : Expr
    {
        UnOp op;
        std::unique_ptr<Expr> rhs;
        Unary(UnOp o, std::unique_ptr<Expr> e) : op(o), rhs(std::move(e)) {}
    };

    struct Binary : Expr
    {
        BinOp op;
        std::unique_ptr<Expr> lhs, rhs;
        Binary(BinOp o, std::unique_ptr<Expr> a, std::unique_ptr<Expr> b) : op(o), lhs(std::move(a)), rhs(std::move(b)) {}
    };

    struct Call : Expr
    {
        std::unique_ptr<Expr> callee;
        std::vector<std::unique_ptr<Expr>> args;
    };

    /*** Sentencias ***/
    struct Stmt : Node
    {
    };

    struct Let : Stmt
    {
        std::string name, type;
        std::unique_ptr<Expr> init;
    };

    struct Return : Stmt
    {
        std::unique_ptr<Expr> value;
    };

    struct ExprStmt : Stmt
    {
        std::unique_ptr<Expr> expr;
    };

    struct Block : Stmt
    {
        std::vector<std::unique_ptr<Stmt>> stmts;
    };

    struct If : Stmt
    {
        std::unique_ptr<Expr> cond;
        std::unique_ptr<Block> thenB;
        std::unique_ptr<Stmt> elseS;
    };
    struct While : Stmt
    {
        std::unique_ptr<Expr> cond;
        std::unique_ptr<Block> body;
    };
    struct For : Stmt
    {
        std::unique_ptr<Expr> init, cond, post;
        std::unique_ptr<Block> body;
    };

    /*** Funciones y programa ***/
    struct Param : Node
    {
        std::string name, type;
    };

    struct Fn : Node
    {
        std::string name, retType;
        std::vector<Param> params;
        std::unique_ptr<Block> body;
    };

    struct Item : Node
    {
        virtual ~Item() = default;
    };

    struct FnItem : Item
    {
        std::unique_ptr<Fn> fn;
        explicit FnItem(std::unique_ptr<Fn> f) : fn(std::move(f)) {}
    };

    struct StmtItem : Item
    {
        std::unique_ptr<Stmt> stmt;
        explicit StmtItem(std::unique_ptr<Stmt> s) : stmt(std::move(s)) {}
    };

    struct Program : Node
    {
        std::vector<std::unique_ptr<Item>> items;
    };

}