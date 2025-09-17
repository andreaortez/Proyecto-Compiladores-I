#pragma once
#include "ast.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace ast
{
    inline const char *binop_symbol(BinOp op)
    {
        switch (op)
        {
        case BinOp::Add:
            return "+";
        case BinOp::Sub:
            return "-";
        case BinOp::Mul:
            return "*";
        case BinOp::Div:
            return "/";
        case BinOp::Mod:
            return "%";
        case BinOp::And:
            return "&&";
        case BinOp::Or:
            return "||";
        case BinOp::Assign:
            return "=";
        case BinOp::Eq:
            return "==";
        case BinOp::Neq:
            return "!=";
        case BinOp::Lt:
            return "<";
        case BinOp::Leq:
            return "<=";
        case BinOp::Gt:
            return ">";
        case BinOp::Geq:
            return ">=";
        case BinOp::AddAssign:
            return "+=";
        case BinOp::SubAssign:
            return "-=";
        case BinOp::MulAssign:
            return "*=";
        case BinOp::DivAssign:
            return "/=";
        case BinOp::ModAssign:
            return "%=";
        }
        return "?";
    }

    inline const char *unop_symbol(UnOp op)
    {
        switch (op)
        {
        case UnOp::Positive:
            return "+";
        case UnOp::Negative:
            return "-";
        case UnOp::Not:
            return "!";
        }
        return "?";
    }

    inline void padding(std::ostream &os, int n)
    {
        for (int i = 0; i < n; ++i)
            os << ' ';
    }

    inline void print(const Expr &expr, std::ostream &os, int indent);
    inline void print(const Stmt &s, std::ostream &os, int indent);
    inline void print(const Item &it, std::ostream &os, int indent);
    inline void print(const Block &b, std::ostream &os, int indent);
    inline void print(const Program &p, std::ostream &os, int indent);

    // EXPRESIONES
    inline void print(const Expr &expr, std::ostream &os, int indent)
    {
        if (auto v = dynamic_cast<const Ident *>(&expr))
        {
            padding(os, indent);
            os << "Ident(" << v->name << ")\n";
            return;
        }
        if (auto v = dynamic_cast<const IntLit *>(&expr))
        {
            padding(os, indent);
            os << "Int(" << v->var << ")\n";
            return;
        }
        if (auto v = dynamic_cast<const FloatLit *>(&expr))
        {
            padding(os, indent);
            os << "Float(" << v->var << ")\n";
            return;
        }
        if (auto v = dynamic_cast<const CharLit *>(&expr))
        {
            padding(os, indent);
            char c = v->var;
            os << "Char('";
            switch (c)
            {
            case '\n':
                os << "\\n";
                break;
            case '\t':
                os << "\\t";
                break;
            case '\r':
                os << "\\r";
                break;
            case '\\':
                os << "\\\\";
                break;
            case '\'':
                os << "\\'";
                break;
            case '\"':
                os << "\\\"";
                break;
            default:
                os << c;
            }
            os << "')\n";
            return;
        }
        if (auto v = dynamic_cast<const StringLit *>(&expr))
        {
            padding(os, indent);
            os << "String(\"" << v->var << "\")\n";
            return;
        }
        if (auto v = dynamic_cast<const BoolLit *>(&expr))
        {
            padding(os, indent);
            os << "Bool(" << (v->var ? "true" : "false") << ")\n";
            return;
        }
        if (auto v = dynamic_cast<const Unary *>(&expr))
        {
            padding(os, indent);
            os << "Unary(" << unop_symbol(v->op) << ")\n";
            if (v->rightSide)
                print(*v->rightSide, os, indent + 2);
            return;
        }
        if (auto v = dynamic_cast<const Binary *>(&expr))
        {
            padding(os, indent);
            os << "Binary(" << binop_symbol(v->op) << ")\n";
            if (v->leftSide)
                print(*v->leftSide, os, indent + 2);
            if (v->rightSide)
                print(*v->rightSide, os, indent + 2);
            return;
        }

        //  Llamados a funciones
        if (auto v = dynamic_cast<const Call *>(&expr))
        {
            padding(os, indent);
            os << "Call\n";
            padding(os, indent + 2);
            os << "Callee:\n";
            if (v->callee)
                print(*v->callee, os, indent + 4);
            if (!v->args.empty())
            {
                padding(os, indent + 2);
                os << "Args:\n";
                for (auto &a : v->args)
                    print(*a, os, indent + 4);
            }
            return;
        }

        if (auto v = dynamic_cast<const Cast *>(&expr))
        {
            padding(os, indent);
            os << "Cast to " << v->toType << "\n";
            padding(os, indent + 2);
            os << "Expr:\n";
            print(*v->expr, os, indent + 4);
            return;
        }

        if (auto v = dynamic_cast<const Try *>(&expr))
        {
            padding(os, indent);
            os << "Try\n";
            padding(os, indent + 2);
            os << "Expr:\n";
            if (v->inner)
                print(*v->inner, os, indent + 4);
            return;
        }

        padding(os, indent);
        os << "Expr(?)\n";
    }

    // bloques
    inline void print(const Block &b, std::ostream &os, int indent)
    {
        padding(os, indent);
        os << "Block\n";
        for (auto &s : b.stmts)
        {
            if (s)
                print(*s, os, indent + 2);
        }
    }

    // SENTENCIAS
    inline void print(const Stmt &s, std::ostream &os, int indent)
    {
        //  LetStmt
        if (auto v = dynamic_cast<const Let *>(&s))
        {
            padding(os, indent);
            os << "Let(";
            if (v->isConst)
                os << "const ";
            else if (v->isMut)
                os << "mut ";
            os << "name=" << v->name;
            if (!v->type.empty())
                os << ", type=" << v->type;
            os << ")\n";

            if (v->init)
            {
                padding(os, indent + 2);
                os << "Init:\n";
                print(*v->init, os, indent + 4);
            }
            return;
        }
        //  return
        if (auto v = dynamic_cast<const Return *>(&s))
        {
            padding(os, indent);
            os << "Return\n";
            if (v->value)
                print(*v->value, os, indent + 2);
            return;
        }
        //  break
        if (dynamic_cast<const Break *>(&s))
        {
            padding(os, indent);
            os << "Break\n";
            return;
        }
        //  continue
        if (dynamic_cast<const Continue *>(&s))
        {
            padding(os, indent);
            os << "Continue\n";
            return;
        }
        //  ExprStmt
        if (auto v = dynamic_cast<const ExprStmt *>(&s))
        {
            padding(os, indent);
            os << "ExprStmt\n";
            if (v->expr)
                print(*v->expr, os, indent + 2);
            return;
        }
        // Block
        if (auto v = dynamic_cast<const Block *>(&s))
        {
            print(*v, os, indent);
            return;
        }
        // IfStmt
        if (auto v = dynamic_cast<const If *>(&s))
        {
            padding(os, indent);
            os << "If\n";
            padding(os, indent + 2);
            os << "Cond:\n";
            if (v->cond)
                print(*v->cond, os, indent + 4);
            padding(os, indent + 2);
            os << "Then:\n";
            if (v->thenB)
                print(*v->thenB, os, indent + 4);
            if (v->elseS)
            {
                padding(os, indent + 2);
                os << "Else:\n";
                print(*v->elseS, os, indent + 4); // puede ser otro If o un Block
            }
            return;
        }
        //  WhileStmt
        if (auto v = dynamic_cast<const While *>(&s))
        {
            padding(os, indent);
            os << "While\n";
            padding(os, indent + 2);
            os << "Cond:\n";
            if (v->cond)
                print(*v->cond, os, indent + 4);
            padding(os, indent + 2);
            os << "Body:\n";
            if (v->body)
                print(*v->body, os, indent + 4);
            return;
        }

        //  ForIn
        if (auto v = dynamic_cast<const ForIn *>(&s))
        {
            padding(os, indent);
            os << "ForIn\n";

            // variable
            padding(os, indent + 2);
            os << "Var: " << v->var << "\n";

            // rango
            padding(os, indent + 2);
            os << "Range: " << (v->inclusive ? "..=" : "..") << "\n";

            if (v->from)
            {
                padding(os, indent + 4);
                os << "From:\n";
                print(*v->from, os, indent + 6);
            }
            if (v->to)
            {
                padding(os, indent + 4);
                os << "To:\n";
                print(*v->to, os, indent + 6);
            }

            // cuerpo
            padding(os, indent + 2);
            os << "Body:\n";
            if (v->body)
            {
                print(*v->body, os, indent + 4);
            }
            return;
        }

        // loops
        if (auto v = dynamic_cast<const Loop *>(&s))
        {
            padding(os, indent);
            os << "Loop\n";
            padding(os, indent + 2);
            os << "Body:\n";
            if (v->body)
                print(*v->body, os, indent + 4);
            return;
        }

        padding(os, indent);
        os << "Stmt(?)\n";
    }

    // ITEMS
    inline void print(const Item &item, std::ostream &os, int indent)
    {
        //  FnItem
        if (auto v = dynamic_cast<const FnItem *>(&item))
        {
            padding(os, indent);
            os << "Fn\n";

            if (v->fn)
            {
                // Nombre
                padding(os, indent + 2);
                os << "Name:\n";
                padding(os, indent + 4);
                os << v->fn->name << "\n";

                // Parámetros
                if (!v->fn->params.empty())
                {
                    padding(os, indent + 2);
                    os << "Params:\n";
                    for (const auto &p : v->fn->params)
                    {
                        padding(os, indent + 4);
                        os << "Ident(" << p.name << ")\n";
                        padding(os, indent + 6);
                        os << "Type: " << p.type << "\n";
                    }
                }
                else
                {
                    padding(os, indent + 2);
                    os << "Params: (none)\n";
                }

                // return
                if (!v->fn->retType.empty())
                {
                    padding(os, indent + 2);
                    os << "Return:\n";
                    padding(os, indent + 4);
                    os << v->fn->retType << "\n";
                }

                // body
                if (v->fn->body)
                {
                    padding(os, indent + 2);
                    os << "Body:\n";
                    print(*v->fn->body, os, indent + 4);
                }
            }
            else
            {
                padding(os, indent + 2);
                os << "(null)\n";
            }
            return;
        }

        //  StmtItem
        if (auto v = dynamic_cast<const StmtItem *>(&item))
        {
            padding(os, indent);
            os << "TopStmt\n";
            if (v->stmt)
                print(*v->stmt, os, indent + 2);
            return;
        }

        // Desconocido
        padding(os, indent);
        os << "Item(?)\n";
    }

    inline void print(const Program &p, std::ostream &os, int indent)
    {
        padding(os, indent);
        os << "Program\n";
        for (auto &item : p.items)
        {
            if (item)
                print(*item, os, indent + 2);
        }
    }

}
