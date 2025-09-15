#pragma once
#include <memory>
#include <string>
#include <vector>

using namespace std;

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
        Mod,
        And,
        Or,
        Assign,
        Eq,
        Ne,
        Lt,
        Le,
        Gt,
        Ge
    };

    enum class UnOp
    {
        Positive,
        Negative,
        Not
    };

    // base para todas las expresiones
    struct Expr : Node
    {
    };

    struct Ident : Expr
    {
        string name;
        explicit Ident(string str) : name(move(str)) {}
    };

    struct IntLit : Expr
    {
        long long var;
        explicit IntLit(long long x) : var(x) {}
    };

    struct FloatLit : Expr
    {
        double var;
        explicit FloatLit(double x) : var(x) {}
    };

    struct CharLit : Expr
    {
        char var;
        explicit CharLit(char c) : var(c) {}
    };

    struct StringLit : Expr
    {
        string var;
        explicit StringLit(string str) : var(move(str)) {}
    };

    struct BoolLit : Expr
    {
        bool var;
        explicit BoolLit(bool boolean) : var(boolean) {}
    };

    struct Unary : Expr
    {
        UnOp op;
        unique_ptr<Expr> rightSide;
        Unary(UnOp o, unique_ptr<Expr> expr) : op(o), rightSide(move(expr)) {}
    };

    struct Binary : Expr
    {
        BinOp op;
        unique_ptr<Expr> leftSide, rightSide;
        Binary(BinOp o, unique_ptr<Expr> a, unique_ptr<Expr> b) : op(o), leftSide(move(a)), rightSide(move(b)) {}
    };

    struct Call : Expr
    {
        unique_ptr<Expr> callee;
        vector<unique_ptr<Expr>> args;
    };

    struct Cast : Expr
    {
        std::unique_ptr<Expr> expr;
        std::string toType;
        Cast(std::unique_ptr<Expr> e, std::string str)
            : expr(std::move(e)), toType(std::move(str)) {}
    };

    struct Try : Expr // para ?
    {
        unique_ptr<Expr> inner;
        explicit Try(unique_ptr<Expr> expr) : inner(move(expr)) {} // constructor
    };

    /* Sentencias */
    struct Stmt : Node // base
    {
    };

    struct Let : Stmt
    {
        bool isMut = false;
        std::string name, type;
        std::unique_ptr<Expr> init;
    };

    struct Return : Stmt
    {
        unique_ptr<Expr> value;
    };

    struct ExprStmt : Stmt
    {
        unique_ptr<Expr> expr;
    };

    struct Block : Stmt
    {
        vector<unique_ptr<Stmt>> stmts;
    };

    struct If : Stmt
    {
        unique_ptr<Expr> cond;
        unique_ptr<Block> thenB;
        unique_ptr<Stmt> elseS;
    };
    struct While : Stmt
    {
        unique_ptr<Expr> cond;
        unique_ptr<Block> body;
    };

    struct Break : Stmt
    {
    };

    struct Continue : Stmt
    {
    };

    struct ForIn : Stmt
    {
        std::string var;
        std::unique_ptr<Expr> from, to;
        bool inclusive = false;
        std::unique_ptr<Block> body;
    };

    struct Loop : Stmt
    {
        std::unique_ptr<Block> body;
    };

    /* Funciones y programa */
    struct Param : Node
    {
        string name, type;
    };

    struct Fn : Node
    {
        string name, retType;
        vector<Param> params;
        unique_ptr<Block> body;
    };

    struct Item : Node
    {
        virtual ~Item() = default;
    };

    struct FnItem : Item
    {
        unique_ptr<Fn> fn;
        explicit FnItem(unique_ptr<Fn> f) : fn(move(f)) {}
    };

    struct StmtItem : Item
    {
        unique_ptr<Stmt> stmt;
        explicit StmtItem(unique_ptr<Stmt> s) : stmt(move(s)) {}
    };

    struct Program : Node
    {
        vector<unique_ptr<Item>> items;
    };

}