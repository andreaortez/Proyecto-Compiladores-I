// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 21 "parser.y"

  #include <cstdio>
  #include <string>
  namespace yy {
    void parser::error(const std::string& m) {
      std::fprintf(stderr, "[parse] %s\n", m.c_str());
    }
  }

#line 56 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 2 "parser.y"
namespace yy {
#line 130 "parser.cpp"

  /// Build a parser object.
  parser::parser (std::unique_ptr<ast::Program>& out_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      out (out_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_InitOpt: // InitOpt
      case symbol_kind::S_ExprOpt: // ExprOpt
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_OrExpr: // OrExpr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_EqExpr: // EqExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MulExpr: // MulExpr
      case symbol_kind::S_Unary: // Unary
      case symbol_kind::S_Postfix: // Postfix
      case symbol_kind::S_Primary: // Primary
        value.copy< ast::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FnDecl: // FnDecl
        value.copy< ast::Fn* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Item: // Item
        value.copy< ast::Item* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Param: // Param
        value.copy< ast::Param > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Program: // Program
        value.copy< ast::Program* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Block: // Block
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_LetStmt: // LetStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_WhileStmt: // WhileStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
        value.copy< ast::Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LIT: // CHAR_LIT
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LIT: // FLOAT_LIT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_LIT: // INT_LIT
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_RetTypeOpt: // RetTypeOpt
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_TypeOpt: // TypeOpt
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParamListOpt: // ParamListOpt
      case symbol_kind::S_Param1: // Param1
      case symbol_kind::S_Param2: // Param2
      case symbol_kind::S_Param3: // Param3
      case symbol_kind::S_Param4: // Param4
      case symbol_kind::S_Param5: // Param5
        value.copy< std::vector<ast::Param>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ArgListOpt: // ArgListOpt
      case symbol_kind::S_ArgList: // ArgList
        value.copy< std::vector<std::unique_ptr<ast::Expr>>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ItemList: // ItemList
        value.copy< std::vector<std::unique_ptr<ast::Item>>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_StmtListOpt: // StmtListOpt
      case symbol_kind::S_StmtList: // StmtList
        value.copy< std::vector<std::unique_ptr<ast::Stmt>>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_InitOpt: // InitOpt
      case symbol_kind::S_ExprOpt: // ExprOpt
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_OrExpr: // OrExpr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_EqExpr: // EqExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MulExpr: // MulExpr
      case symbol_kind::S_Unary: // Unary
      case symbol_kind::S_Postfix: // Postfix
      case symbol_kind::S_Primary: // Primary
        value.move< ast::Expr* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FnDecl: // FnDecl
        value.move< ast::Fn* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Item: // Item
        value.move< ast::Item* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Param: // Param
        value.move< ast::Param > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Program: // Program
        value.move< ast::Program* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_Block: // Block
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_LetStmt: // LetStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_WhileStmt: // WhileStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
        value.move< ast::Stmt* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_CHAR_LIT: // CHAR_LIT
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT_LIT: // FLOAT_LIT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT_LIT: // INT_LIT
        value.move< long long > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_RetTypeOpt: // RetTypeOpt
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_TypeOpt: // TypeOpt
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ParamListOpt: // ParamListOpt
      case symbol_kind::S_Param1: // Param1
      case symbol_kind::S_Param2: // Param2
      case symbol_kind::S_Param3: // Param3
      case symbol_kind::S_Param4: // Param4
      case symbol_kind::S_Param5: // Param5
        value.move< std::vector<ast::Param>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ArgListOpt: // ArgListOpt
      case symbol_kind::S_ArgList: // ArgList
        value.move< std::vector<std::unique_ptr<ast::Expr>>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ItemList: // ItemList
        value.move< std::vector<std::unique_ptr<ast::Item>>* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_StmtListOpt: // StmtListOpt
      case symbol_kind::S_StmtList: // StmtList
        value.move< std::vector<std::unique_ptr<ast::Stmt>>* > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_InitOpt: // InitOpt
      case symbol_kind::S_ExprOpt: // ExprOpt
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_OrExpr: // OrExpr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_EqExpr: // EqExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MulExpr: // MulExpr
      case symbol_kind::S_Unary: // Unary
      case symbol_kind::S_Postfix: // Postfix
      case symbol_kind::S_Primary: // Primary
        value.YY_MOVE_OR_COPY< ast::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FnDecl: // FnDecl
        value.YY_MOVE_OR_COPY< ast::Fn* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Item: // Item
        value.YY_MOVE_OR_COPY< ast::Item* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Param: // Param
        value.YY_MOVE_OR_COPY< ast::Param > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Program: // Program
        value.YY_MOVE_OR_COPY< ast::Program* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Block: // Block
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_LetStmt: // LetStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_WhileStmt: // WhileStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
        value.YY_MOVE_OR_COPY< ast::Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LIT: // CHAR_LIT
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LIT: // FLOAT_LIT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_LIT: // INT_LIT
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_RetTypeOpt: // RetTypeOpt
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_TypeOpt: // TypeOpt
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParamListOpt: // ParamListOpt
      case symbol_kind::S_Param1: // Param1
      case symbol_kind::S_Param2: // Param2
      case symbol_kind::S_Param3: // Param3
      case symbol_kind::S_Param4: // Param4
      case symbol_kind::S_Param5: // Param5
        value.YY_MOVE_OR_COPY< std::vector<ast::Param>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ArgListOpt: // ArgListOpt
      case symbol_kind::S_ArgList: // ArgList
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<ast::Expr>>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ItemList: // ItemList
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<ast::Item>>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_StmtListOpt: // StmtListOpt
      case symbol_kind::S_StmtList: // StmtList
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<ast::Stmt>>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_InitOpt: // InitOpt
      case symbol_kind::S_ExprOpt: // ExprOpt
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_OrExpr: // OrExpr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_EqExpr: // EqExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MulExpr: // MulExpr
      case symbol_kind::S_Unary: // Unary
      case symbol_kind::S_Postfix: // Postfix
      case symbol_kind::S_Primary: // Primary
        value.move< ast::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FnDecl: // FnDecl
        value.move< ast::Fn* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Item: // Item
        value.move< ast::Item* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Param: // Param
        value.move< ast::Param > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Program: // Program
        value.move< ast::Program* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_Block: // Block
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_LetStmt: // LetStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_WhileStmt: // WhileStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
        value.move< ast::Stmt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_CHAR_LIT: // CHAR_LIT
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT_LIT: // FLOAT_LIT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT_LIT: // INT_LIT
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_RetTypeOpt: // RetTypeOpt
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_TypeOpt: // TypeOpt
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ParamListOpt: // ParamListOpt
      case symbol_kind::S_Param1: // Param1
      case symbol_kind::S_Param2: // Param2
      case symbol_kind::S_Param3: // Param3
      case symbol_kind::S_Param4: // Param4
      case symbol_kind::S_Param5: // Param5
        value.move< std::vector<ast::Param>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ArgListOpt: // ArgListOpt
      case symbol_kind::S_ArgList: // ArgList
        value.move< std::vector<std::unique_ptr<ast::Expr>>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ItemList: // ItemList
        value.move< std::vector<std::unique_ptr<ast::Item>>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_StmtListOpt: // StmtListOpt
      case symbol_kind::S_StmtList: // StmtList
        value.move< std::vector<std::unique_ptr<ast::Stmt>>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_InitOpt: // InitOpt
      case symbol_kind::S_ExprOpt: // ExprOpt
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_OrExpr: // OrExpr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_EqExpr: // EqExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MulExpr: // MulExpr
      case symbol_kind::S_Unary: // Unary
      case symbol_kind::S_Postfix: // Postfix
      case symbol_kind::S_Primary: // Primary
        value.copy< ast::Expr* > (that.value);
        break;

      case symbol_kind::S_FnDecl: // FnDecl
        value.copy< ast::Fn* > (that.value);
        break;

      case symbol_kind::S_Item: // Item
        value.copy< ast::Item* > (that.value);
        break;

      case symbol_kind::S_Param: // Param
        value.copy< ast::Param > (that.value);
        break;

      case symbol_kind::S_Program: // Program
        value.copy< ast::Program* > (that.value);
        break;

      case symbol_kind::S_Block: // Block
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_LetStmt: // LetStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_WhileStmt: // WhileStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
        value.copy< ast::Stmt* > (that.value);
        break;

      case symbol_kind::S_CHAR_LIT: // CHAR_LIT
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_FLOAT_LIT: // FLOAT_LIT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT_LIT: // INT_LIT
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_RetTypeOpt: // RetTypeOpt
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_TypeOpt: // TypeOpt
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_ParamListOpt: // ParamListOpt
      case symbol_kind::S_Param1: // Param1
      case symbol_kind::S_Param2: // Param2
      case symbol_kind::S_Param3: // Param3
      case symbol_kind::S_Param4: // Param4
      case symbol_kind::S_Param5: // Param5
        value.copy< std::vector<ast::Param>* > (that.value);
        break;

      case symbol_kind::S_ArgListOpt: // ArgListOpt
      case symbol_kind::S_ArgList: // ArgList
        value.copy< std::vector<std::unique_ptr<ast::Expr>>* > (that.value);
        break;

      case symbol_kind::S_ItemList: // ItemList
        value.copy< std::vector<std::unique_ptr<ast::Item>>* > (that.value);
        break;

      case symbol_kind::S_StmtListOpt: // StmtListOpt
      case symbol_kind::S_StmtList: // StmtList
        value.copy< std::vector<std::unique_ptr<ast::Stmt>>* > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_InitOpt: // InitOpt
      case symbol_kind::S_ExprOpt: // ExprOpt
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_OrExpr: // OrExpr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_EqExpr: // EqExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MulExpr: // MulExpr
      case symbol_kind::S_Unary: // Unary
      case symbol_kind::S_Postfix: // Postfix
      case symbol_kind::S_Primary: // Primary
        value.move< ast::Expr* > (that.value);
        break;

      case symbol_kind::S_FnDecl: // FnDecl
        value.move< ast::Fn* > (that.value);
        break;

      case symbol_kind::S_Item: // Item
        value.move< ast::Item* > (that.value);
        break;

      case symbol_kind::S_Param: // Param
        value.move< ast::Param > (that.value);
        break;

      case symbol_kind::S_Program: // Program
        value.move< ast::Program* > (that.value);
        break;

      case symbol_kind::S_Block: // Block
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_LetStmt: // LetStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_WhileStmt: // WhileStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
        value.move< ast::Stmt* > (that.value);
        break;

      case symbol_kind::S_CHAR_LIT: // CHAR_LIT
        value.move< char > (that.value);
        break;

      case symbol_kind::S_FLOAT_LIT: // FLOAT_LIT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT_LIT: // INT_LIT
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_RetTypeOpt: // RetTypeOpt
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_TypeOpt: // TypeOpt
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_ParamListOpt: // ParamListOpt
      case symbol_kind::S_Param1: // Param1
      case symbol_kind::S_Param2: // Param2
      case symbol_kind::S_Param3: // Param3
      case symbol_kind::S_Param4: // Param4
      case symbol_kind::S_Param5: // Param5
        value.move< std::vector<ast::Param>* > (that.value);
        break;

      case symbol_kind::S_ArgListOpt: // ArgListOpt
      case symbol_kind::S_ArgList: // ArgList
        value.move< std::vector<std::unique_ptr<ast::Expr>>* > (that.value);
        break;

      case symbol_kind::S_ItemList: // ItemList
        value.move< std::vector<std::unique_ptr<ast::Item>>* > (that.value);
        break;

      case symbol_kind::S_StmtListOpt: // StmtListOpt
      case symbol_kind::S_StmtList: // StmtList
        value.move< std::vector<std::unique_ptr<ast::Stmt>>* > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_InitOpt: // InitOpt
      case symbol_kind::S_ExprOpt: // ExprOpt
      case symbol_kind::S_Expr: // Expr
      case symbol_kind::S_OrExpr: // OrExpr
      case symbol_kind::S_AndExpr: // AndExpr
      case symbol_kind::S_EqExpr: // EqExpr
      case symbol_kind::S_RelExpr: // RelExpr
      case symbol_kind::S_AddExpr: // AddExpr
      case symbol_kind::S_MulExpr: // MulExpr
      case symbol_kind::S_Unary: // Unary
      case symbol_kind::S_Postfix: // Postfix
      case symbol_kind::S_Primary: // Primary
        yylhs.value.emplace< ast::Expr* > ();
        break;

      case symbol_kind::S_FnDecl: // FnDecl
        yylhs.value.emplace< ast::Fn* > ();
        break;

      case symbol_kind::S_Item: // Item
        yylhs.value.emplace< ast::Item* > ();
        break;

      case symbol_kind::S_Param: // Param
        yylhs.value.emplace< ast::Param > ();
        break;

      case symbol_kind::S_Program: // Program
        yylhs.value.emplace< ast::Program* > ();
        break;

      case symbol_kind::S_Block: // Block
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_LetStmt: // LetStmt
      case symbol_kind::S_ReturnStmt: // ReturnStmt
      case symbol_kind::S_IfStmt: // IfStmt
      case symbol_kind::S_WhileStmt: // WhileStmt
      case symbol_kind::S_ForStmt: // ForStmt
      case symbol_kind::S_ExprStmt: // ExprStmt
        yylhs.value.emplace< ast::Stmt* > ();
        break;

      case symbol_kind::S_CHAR_LIT: // CHAR_LIT
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_FLOAT_LIT: // FLOAT_LIT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT_LIT: // INT_LIT
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STR_LIT: // STR_LIT
      case symbol_kind::S_RetTypeOpt: // RetTypeOpt
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_TypeOpt: // TypeOpt
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_ParamListOpt: // ParamListOpt
      case symbol_kind::S_Param1: // Param1
      case symbol_kind::S_Param2: // Param2
      case symbol_kind::S_Param3: // Param3
      case symbol_kind::S_Param4: // Param4
      case symbol_kind::S_Param5: // Param5
        yylhs.value.emplace< std::vector<ast::Param>* > ();
        break;

      case symbol_kind::S_ArgListOpt: // ArgListOpt
      case symbol_kind::S_ArgList: // ArgList
        yylhs.value.emplace< std::vector<std::unique_ptr<ast::Expr>>* > ();
        break;

      case symbol_kind::S_ItemList: // ItemList
        yylhs.value.emplace< std::vector<std::unique_ptr<ast::Item>>* > ();
        break;

      case symbol_kind::S_StmtListOpt: // StmtListOpt
      case symbol_kind::S_StmtList: // StmtList
        yylhs.value.emplace< std::vector<std::unique_ptr<ast::Stmt>>* > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // Program: %empty
#line 87 "parser.y"
                           { yylhs.value.as < ast::Program* > () = new ast::Program(); out.reset(yylhs.value.as < ast::Program* > ()); }
#line 1200 "parser.cpp"
    break;

  case 3: // Program: ItemList
#line 88 "parser.y"
             { 
      auto p = new ast::Program(); //creo el nodo Program
      p->items = std::move(*yystack_[0].value.as < std::vector<std::unique_ptr<ast::Item>>* > ()); 
      delete yystack_[0].value.as < std::vector<std::unique_ptr<ast::Item>>* > (); 
      yylhs.value.as < ast::Program* > () = p; 
      out.reset(p); 
    }
#line 1212 "parser.cpp"
    break;

  case 4: // ItemList: Item
#line 98 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > () = new std::vector<std::unique_ptr<ast::Item>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > ()->emplace_back(yystack_[0].value.as < ast::Item* > ()); }
#line 1218 "parser.cpp"
    break;

  case 5: // ItemList: ItemList Item
#line 99 "parser.y"
                          { yystack_[1].value.as < std::vector<std::unique_ptr<ast::Item>>* > ()->emplace_back(yystack_[0].value.as < ast::Item* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > () = yystack_[1].value.as < std::vector<std::unique_ptr<ast::Item>>* > (); }
#line 1224 "parser.cpp"
    break;

  case 6: // Item: FnDecl
#line 103 "parser.y"
                          { yylhs.value.as < ast::Item* > () = new ast::FnItem( std::unique_ptr<ast::Fn>(yystack_[0].value.as < ast::Fn* > ()) ); }
#line 1230 "parser.cpp"
    break;

  case 7: // Item: Stmt
#line 104 "parser.y"
                          { yylhs.value.as < ast::Item* > () = new ast::StmtItem( std::unique_ptr<ast::Stmt>(yystack_[0].value.as < ast::Stmt* > ()) ); }
#line 1236 "parser.cpp"
    break;

  case 8: // FnDecl: FN IDENT LPAREN ParamListOpt RPAREN RetTypeOpt Block
#line 110 "parser.y"
    {
      auto fn = std::make_unique<ast::Fn>();
      fn->name = std::move(yystack_[5].value.as < std::string > ());
      if (yystack_[3].value.as < std::vector<ast::Param>* > ()) { fn->params = std::move(*yystack_[3].value.as < std::vector<ast::Param>* > ()); delete yystack_[3].value.as < std::vector<ast::Param>* > (); }
      fn->retType = std::move(yystack_[1].value.as < std::string > ());                
      fn->body.reset( (ast::Block*)yystack_[0].value.as < ast::Stmt* > () );//si body tenia algo lo borra
      yylhs.value.as < ast::Fn* > () = fn.release();
    }
#line 1249 "parser.cpp"
    break;

  case 9: // RetTypeOpt: %empty
#line 121 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1255 "parser.cpp"
    break;

  case 10: // RetTypeOpt: ARROW Type
#line 122 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1261 "parser.cpp"
    break;

  case 11: // ParamListOpt: %empty
#line 126 "parser.y"
                           { yylhs.value.as < std::vector<ast::Param>* > () = nullptr; }
#line 1267 "parser.cpp"
    break;

  case 12: // ParamListOpt: Param1
#line 127 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1273 "parser.cpp"
    break;

  case 13: // ParamListOpt: Param2
#line 128 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1279 "parser.cpp"
    break;

  case 14: // ParamListOpt: Param3
#line 129 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1285 "parser.cpp"
    break;

  case 15: // ParamListOpt: Param4
#line 130 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1291 "parser.cpp"
    break;

  case 16: // ParamListOpt: Param5
#line 131 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1297 "parser.cpp"
    break;

  case 17: // Param1: Param
#line 135 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[0].value.as < ast::Param > () }; }
#line 1303 "parser.cpp"
    break;

  case 18: // Param2: Param COMMA Param
#line 139 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1309 "parser.cpp"
    break;

  case 19: // Param3: Param COMMA Param COMMA Param
#line 144 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1315 "parser.cpp"
    break;

  case 20: // Param4: Param COMMA Param COMMA Param COMMA Param
#line 149 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[6].value.as < ast::Param > (), yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1321 "parser.cpp"
    break;

  case 21: // Param5: Param COMMA Param COMMA Param COMMA Param COMMA Param
#line 154 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[8].value.as < ast::Param > (), yystack_[6].value.as < ast::Param > (), yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1327 "parser.cpp"
    break;

  case 22: // Param: IDENT COLON Type
#line 159 "parser.y"
    {
      yylhs.value.as < ast::Param > ().name = std::move(yystack_[2].value.as < std::string > ());
      yylhs.value.as < ast::Param > ().type   = std::move(yystack_[0].value.as < std::string > ());
    }
#line 1336 "parser.cpp"
    break;

  case 23: // Type: I32_T
#line 166 "parser.y"
                          { yylhs.value.as < std::string > () = "i32"; }
#line 1342 "parser.cpp"
    break;

  case 24: // Type: F64_T
#line 167 "parser.y"
                          { yylhs.value.as < std::string > () = "f64"; }
#line 1348 "parser.cpp"
    break;

  case 25: // Type: BOOL_T
#line 168 "parser.y"
                          { yylhs.value.as < std::string > () = "bool"; }
#line 1354 "parser.cpp"
    break;

  case 26: // Type: CHAR_T
#line 169 "parser.y"
                          { yylhs.value.as < std::string > () = "char"; }
#line 1360 "parser.cpp"
    break;

  case 27: // Type: STR_T
#line 170 "parser.y"
                          { yylhs.value.as < std::string > () = "str"; }
#line 1366 "parser.cpp"
    break;

  case 28: // Block: LBRACE StmtListOpt RBRACE
#line 176 "parser.y"
    {
      auto b = std::make_unique<ast::Block>();
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()) { b->stmts = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
      yylhs.value.as < ast::Stmt* > () = b.release();
    }
#line 1376 "parser.cpp"
    break;

  case 29: // StmtListOpt: %empty
#line 184 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = nullptr; }
#line 1382 "parser.cpp"
    break;

  case 30: // StmtListOpt: StmtList
#line 185 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
#line 1388 "parser.cpp"
    break;

  case 31: // StmtList: Stmt
#line 189 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = new std::vector<std::unique_ptr<ast::Stmt>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()->emplace_back(yystack_[0].value.as < ast::Stmt* > ()); }
#line 1394 "parser.cpp"
    break;

  case 32: // StmtList: StmtList Stmt
#line 190 "parser.y"
                          { yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()->emplace_back(yystack_[0].value.as < ast::Stmt* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
#line 1400 "parser.cpp"
    break;

  case 33: // Stmt: LetStmt
#line 195 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1406 "parser.cpp"
    break;

  case 34: // Stmt: ReturnStmt
#line 196 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1412 "parser.cpp"
    break;

  case 35: // Stmt: IfStmt
#line 197 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1418 "parser.cpp"
    break;

  case 36: // Stmt: WhileStmt
#line 198 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1424 "parser.cpp"
    break;

  case 37: // Stmt: ForStmt
#line 199 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1430 "parser.cpp"
    break;

  case 38: // Stmt: ExprStmt
#line 200 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1436 "parser.cpp"
    break;

  case 39: // Stmt: Block
#line 201 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1442 "parser.cpp"
    break;

  case 40: // Stmt: BREAK SEMICOLON
#line 202 "parser.y"
                             { yylhs.value.as < ast::Stmt* > () = new ast::Break(); }
#line 1448 "parser.cpp"
    break;

  case 41: // Stmt: CONTINUE SEMICOLON
#line 203 "parser.y"
                             { yylhs.value.as < ast::Stmt* > () = new ast::Continue(); }
#line 1454 "parser.cpp"
    break;

  case 42: // Stmt: LOOP Block
#line 205 "parser.y"
    { 
      auto s = std::make_unique<ast::Loop>();
      s->body.reset(static_cast<ast::Block*>(yystack_[0].value.as < ast::Stmt* > ())); 
      yylhs.value.as < ast::Stmt* > () = s.release(); 
    }
#line 1464 "parser.cpp"
    break;

  case 43: // LetStmt: LET IDENT TypeOpt InitOpt SEMICOLON
#line 214 "parser.y"
    {
      auto s = std::make_unique<ast::Let>();
      s->isMut = false;
      s->name = std::move(yystack_[3].value.as < std::string > ());
      s->type = std::move(yystack_[2].value.as < std::string > ());
      s->init.reset( (ast::Expr*)yystack_[1].value.as < ast::Expr* > () );// si tenia algo, lo borra
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1477 "parser.cpp"
    break;

  case 44: // LetStmt: LET MUT IDENT TypeOpt InitOpt SEMICOLON
#line 223 "parser.y"
    {
      auto s = std::make_unique<ast::Let>();
      s->isMut = true;
      s->name = std::move(yystack_[3].value.as < std::string > ());
      s->type = std::move(yystack_[2].value.as < std::string > ());
      s->init.reset( (ast::Expr*)yystack_[1].value.as < ast::Expr* > () );
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1490 "parser.cpp"
    break;

  case 45: // LetStmt: CONST IDENT COLON Type ASSIGN Expr SEMICOLON
#line 232 "parser.y"
    {
      auto s = std::make_unique<ast::Let>();
      s->isConst = true;                              
      s->name = std::move(yystack_[5].value.as < std::string > ());
      s->type = std::move(yystack_[3].value.as < std::string > ());                       
      s->init.reset(yystack_[1].value.as < ast::Expr* > ());                              
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1503 "parser.cpp"
    break;

  case 46: // TypeOpt: %empty
#line 243 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1509 "parser.cpp"
    break;

  case 47: // TypeOpt: COLON Type
#line 244 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1515 "parser.cpp"
    break;

  case 48: // InitOpt: %empty
#line 248 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1521 "parser.cpp"
    break;

  case 49: // InitOpt: ASSIGN Expr
#line 249 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1527 "parser.cpp"
    break;

  case 50: // ReturnStmt: RETURN ExprOpt SEMICOLON
#line 254 "parser.y"
    {
      auto s = std::make_unique<ast::Return>();
      s->value.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1537 "parser.cpp"
    break;

  case 51: // ExprOpt: %empty
#line 262 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1543 "parser.cpp"
    break;

  case 52: // ExprOpt: Expr
#line 263 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1549 "parser.cpp"
    break;

  case 53: // IfStmt: IF Expr Block
#line 268 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1560 "parser.cpp"
    break;

  case 54: // IfStmt: IF Expr Block ELSE IfStmt
#line 275 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[3].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[2].value.as < ast::Stmt* > ());
      s->elseS.reset(yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1572 "parser.cpp"
    break;

  case 55: // IfStmt: IF Expr Block ELSE Block
#line 283 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[3].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[2].value.as < ast::Stmt* > ());
      s->elseS.reset(yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1584 "parser.cpp"
    break;

  case 56: // WhileStmt: WHILE Expr Block
#line 294 "parser.y"
    {
      auto s = std::make_unique<ast::While>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->body.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1595 "parser.cpp"
    break;

  case 57: // ForStmt: FOR IDENT IN Expr RANGE Expr Block
#line 304 "parser.y"
    {
      auto s = std::make_unique<ast::ForIn>();
      s->var = std::move(yystack_[5].value.as < std::string > ());
      s->from.reset(yystack_[3].value.as < ast::Expr* > ());
      s->to.reset(yystack_[1].value.as < ast::Expr* > ());
      s->inclusive = false;
      s->body.reset(static_cast<ast::Block*>(yystack_[0].value.as < ast::Stmt* > ()));
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1609 "parser.cpp"
    break;

  case 58: // ForStmt: FOR IDENT IN Expr RANGE_EQ Expr Block
#line 314 "parser.y"
    {
      auto s = std::make_unique<ast::ForIn>();
      s->var = std::move(yystack_[5].value.as < std::string > ());
      s->from.reset(yystack_[3].value.as < ast::Expr* > ());
      s->to.reset(yystack_[1].value.as < ast::Expr* > ());
      s->inclusive = true;
      s->body.reset(static_cast<ast::Block*>(yystack_[0].value.as < ast::Stmt* > ()));
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1623 "parser.cpp"
    break;

  case 59: // ExprStmt: Expr SEMICOLON
#line 327 "parser.y"
    {
      auto s = std::make_unique<ast::ExprStmt>();
      s->expr.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1633 "parser.cpp"
    break;

  case 60: // Expr: IDENT ASSIGN Expr
#line 336 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Assign, std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1639 "parser.cpp"
    break;

  case 61: // Expr: OrExpr
#line 337 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1645 "parser.cpp"
    break;

  case 62: // OrExpr: OrExpr OR AndExpr
#line 341 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Or,  std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1651 "parser.cpp"
    break;

  case 63: // OrExpr: AndExpr
#line 342 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1657 "parser.cpp"
    break;

  case 64: // AndExpr: AndExpr AND EqExpr
#line 346 "parser.y"
                         { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::And, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1663 "parser.cpp"
    break;

  case 65: // AndExpr: EqExpr
#line 347 "parser.y"
                         { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1669 "parser.cpp"
    break;

  case 66: // EqExpr: RelExpr
#line 351 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1675 "parser.cpp"
    break;

  case 67: // EqExpr: RelExpr EQ RelExpr
#line 352 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Eq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1681 "parser.cpp"
    break;

  case 68: // EqExpr: RelExpr NEQ RelExpr
#line 353 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Neq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1687 "parser.cpp"
    break;

  case 69: // RelExpr: AddExpr
#line 357 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1693 "parser.cpp"
    break;

  case 70: // RelExpr: AddExpr LT AddExpr
#line 358 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Lt, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1699 "parser.cpp"
    break;

  case 71: // RelExpr: AddExpr LEQ AddExpr
#line 359 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Leq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1705 "parser.cpp"
    break;

  case 72: // RelExpr: AddExpr GT AddExpr
#line 360 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Gt, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1711 "parser.cpp"
    break;

  case 73: // RelExpr: AddExpr GEQ AddExpr
#line 361 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Geq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1717 "parser.cpp"
    break;

  case 74: // RelExpr: AddExpr MULEQ AddExpr
#line 362 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::MulEq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1723 "parser.cpp"
    break;

  case 75: // RelExpr: AddExpr DIVEQ AddExpr
#line 363 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::DivEq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1729 "parser.cpp"
    break;

  case 76: // RelExpr: AddExpr PLUSEQ AddExpr
#line 364 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::PlusEq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1735 "parser.cpp"
    break;

  case 77: // RelExpr: AddExpr MINEQ AddExpr
#line 365 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::MinEq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1741 "parser.cpp"
    break;

  case 78: // AddExpr: AddExpr PLUS MulExpr
#line 369 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Add, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1747 "parser.cpp"
    break;

  case 79: // AddExpr: AddExpr MINUS MulExpr
#line 370 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Sub, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1753 "parser.cpp"
    break;

  case 80: // AddExpr: MulExpr
#line 371 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1759 "parser.cpp"
    break;

  case 81: // MulExpr: MulExpr MULTIPLY Unary
#line 375 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Mul, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1765 "parser.cpp"
    break;

  case 82: // MulExpr: MulExpr DIVIDE Unary
#line 376 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Div, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1771 "parser.cpp"
    break;

  case 83: // MulExpr: MulExpr MOD Unary
#line 377 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Mod, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1777 "parser.cpp"
    break;

  case 84: // MulExpr: Unary
#line 378 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1783 "parser.cpp"
    break;

  case 85: // Unary: Unary AS Type
#line 382 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Cast(std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::move(yystack_[0].value.as < std::string > ())); }
#line 1789 "parser.cpp"
    break;

  case 86: // Unary: NOT Unary
#line 383 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Not, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1795 "parser.cpp"
    break;

  case 87: // Unary: PLUS Unary
#line 384 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Positive, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1801 "parser.cpp"
    break;

  case 88: // Unary: MINUS Unary
#line 385 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Negative, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1807 "parser.cpp"
    break;

  case 89: // Unary: Postfix
#line 386 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1813 "parser.cpp"
    break;

  case 90: // Postfix: Primary
#line 391 "parser.y"
    { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1819 "parser.cpp"
    break;

  case 91: // Postfix: Postfix LPAREN ArgListOpt RPAREN
#line 393 "parser.y"
    {
      auto call = new ast::Call();
      call->callee.reset(yystack_[3].value.as < ast::Expr* > ());
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()) { call->args = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
      yylhs.value.as < ast::Expr* > () = call;
    }
#line 1830 "parser.cpp"
    break;

  case 92: // Postfix: Postfix QUESTION
#line 400 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Try( std::unique_ptr<ast::Expr>(yystack_[1].value.as < ast::Expr* > ()) );
    }
#line 1838 "parser.cpp"
    break;

  case 93: // Primary: IDENT
#line 406 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Ident(std::move(yystack_[0].value.as < std::string > ())); }
#line 1844 "parser.cpp"
    break;

  case 94: // Primary: INT_LIT
#line 407 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::IntLit(yystack_[0].value.as < long long > ()); }
#line 1850 "parser.cpp"
    break;

  case 95: // Primary: FLOAT_LIT
#line 408 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::FloatLit(yystack_[0].value.as < double > ()); }
#line 1856 "parser.cpp"
    break;

  case 96: // Primary: TRUE_LIT
#line 409 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(true); }
#line 1862 "parser.cpp"
    break;

  case 97: // Primary: FALSE_LIT
#line 410 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(false); }
#line 1868 "parser.cpp"
    break;

  case 98: // Primary: CHAR_LIT
#line 411 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::CharLit(yystack_[0].value.as < char > ()); }
#line 1874 "parser.cpp"
    break;

  case 99: // Primary: STR_LIT
#line 412 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::StringLit(std::move(yystack_[0].value.as < std::string > ())); }
#line 1880 "parser.cpp"
    break;

  case 100: // Primary: LPAREN Expr RPAREN
#line 413 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[1].value.as < ast::Expr* > (); }
#line 1886 "parser.cpp"
    break;

  case 101: // ArgListOpt: %empty
#line 418 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = nullptr; }
#line 1892 "parser.cpp"
    break;

  case 102: // ArgListOpt: ArgList
#line 419 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1898 "parser.cpp"
    break;

  case 103: // ArgList: Expr
#line 423 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = new std::vector<std::unique_ptr<ast::Expr>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); }
#line 1904 "parser.cpp"
    break;

  case 104: // ArgList: ArgList COMMA Expr
#line 424 "parser.y"
                          { yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1910 "parser.cpp"
    break;


#line 1914 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -122;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      15,    -3,     4,    14,   133,   133,    42,   133,   -32,    11,
     -26,  -122,  -122,  -122,  -122,  -122,  -122,   145,   145,   145,
      84,   133,    26,    73,    15,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,    22,    52,    54,  -122,   -23,
     148,    10,    25,   -34,  -122,    63,    30,    32,    39,    26,
      26,    31,    38,  -122,  -122,  -122,   133,  -122,    25,    25,
      25,    53,    84,  -122,    50,  -122,  -122,  -122,  -122,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,    41,  -122,   133,    30,
      41,    45,    41,    82,    94,  -122,   133,  -122,  -122,  -122,
    -122,  -122,    54,  -122,  -122,  -122,    10,    10,    20,    20,
      20,    20,    20,    20,    20,    20,    25,    25,    25,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,    62,    60,    45,  -122,
     133,    72,    70,    74,    80,  -122,  -122,  -122,  -122,  -122,
      79,     1,     6,  -122,   133,    81,  -122,  -122,   133,    41,
      78,    82,  -122,  -122,   133,   133,  -122,  -122,    83,  -122,
      41,    26,    85,    26,    26,  -122,  -122,  -122,    82,  -122,
    -122,    86,    82,    87,    82,  -122
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      93,    99,    94,    95,    98,    96,    97,     0,     0,     0,
      29,     0,     0,     0,     3,     4,     6,    39,     7,    33,
      34,    35,    36,    37,    38,     0,    61,    63,    65,    66,
      69,    80,    84,    89,    90,     0,    46,     0,     0,     0,
       0,     0,     0,    52,    40,    41,     0,    93,    86,    87,
      88,     0,    30,    31,     0,    42,     1,     5,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,   101,    46,
       0,    48,     0,    11,    53,    56,     0,    50,    60,    28,
      32,   100,    62,    64,    67,    68,    78,    79,    70,    72,
      71,    73,    74,    75,    76,    77,    81,    82,    83,    23,
      24,    25,    26,    27,    85,   103,     0,   102,    48,    47,
       0,     0,     0,     0,     0,    12,    13,    14,    15,    16,
      17,     0,     0,    91,     0,     0,    49,    43,     0,     0,
       9,     0,    55,    54,     0,     0,   104,    44,     0,    22,
       0,     0,    18,     0,     0,    45,    10,     8,     0,    57,
      58,    19,     0,    20,     0,    21
  };

  const signed char
  parser::yypgoto_[] =
  {
    -122,  -122,  -122,   110,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -121,   -85,   -18,  -122,  -122,   -14,  -122,    58,
      21,  -122,  -122,     7,  -122,  -122,  -122,    -4,  -122,    90,
      69,    -2,    40,    -6,    -7,  -122,  -122,  -122,  -122
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    23,    24,    25,    26,   161,   134,   135,   136,   137,
     138,   139,   140,   124,    27,    61,    62,    28,    29,    91,
     131,    30,    52,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   126,   127
  };

  const unsigned char
  parser::yytable_[] =
  {
      49,    50,    45,    53,    65,   129,    63,   132,     4,    87,
      58,    59,    60,    88,    71,    72,    46,    64,     1,     2,
      54,     3,     4,    47,     5,     6,     7,     8,     9,    56,
     162,    94,    95,    48,    10,    11,    12,    13,    14,    15,
      16,    83,    84,    17,    18,    19,    20,   171,   100,    73,
      74,   173,    98,   175,    85,   119,   120,   121,   122,   123,
      20,    51,    21,    55,   159,   154,   155,   106,   107,   104,
     105,    20,    22,    66,    68,   166,   116,   117,   118,    69,
      70,    86,    89,    90,   125,    92,    93,     1,     2,    96,
      97,     4,   142,     5,     6,     7,     8,     9,   101,    99,
     130,   133,   141,    10,    11,    12,    13,    14,    15,    16,
     143,   144,    17,    18,    19,   108,   109,   110,   111,   112,
     113,   114,   115,   152,   147,   148,   146,   149,   150,    20,
     151,    21,   160,   157,    67,   165,   168,   172,   174,   103,
     156,    22,     0,   167,   158,   169,   170,   128,   153,   145,
     163,   164,    10,    11,    12,    13,    14,    15,    16,   102,
       0,    17,    18,    19,    57,    11,    12,    13,    14,    15,
      16,     0,     0,    17,    18,    19,     0,    73,    74,     0,
      21,    75,    76,    77,    78,     0,     0,    79,    80,    81,
      82,     0,    21
  };

  const short
  parser::yycheck_[] =
  {
       4,     5,     5,     7,    22,    90,    20,    92,     7,    43,
      17,    18,    19,    47,    37,    38,    19,    21,     3,     4,
      52,     6,     7,    19,     9,    10,    11,    12,    13,    55,
     151,    49,    50,    19,    19,    20,    21,    22,    23,    24,
      25,    31,    32,    28,    29,    30,    45,   168,    62,    29,
      30,   172,    56,   174,    44,    14,    15,    16,    17,    18,
      45,    19,    47,    52,   149,    59,    60,    73,    74,    71,
      72,    45,    57,     0,    52,   160,    83,    84,    85,    27,
      26,    56,    19,    53,    88,    53,    47,     3,     4,    58,
      52,     7,    96,     9,    10,    11,    12,    13,    48,    46,
      55,    19,     8,    19,    20,    21,    22,    23,    24,    25,
      48,    51,    28,    29,    30,    75,    76,    77,    78,    79,
      80,    81,    82,   141,    52,    55,   130,    53,    48,    45,
      51,    47,    54,    52,    24,    52,    51,    51,    51,    70,
     144,    57,    -1,   161,   148,   163,   164,    89,   141,   128,
     154,   155,    19,    20,    21,    22,    23,    24,    25,    69,
      -1,    28,    29,    30,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    -1,    29,    30,    -1,
      47,    33,    34,    35,    36,    -1,    -1,    39,    40,    41,
      42,    -1,    47
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     6,     7,     9,    10,    11,    12,    13,
      19,    20,    21,    22,    23,    24,    25,    28,    29,    30,
      45,    47,    57,    66,    67,    68,    69,    79,    82,    83,
      86,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,     5,    19,    19,    19,    92,
      92,    19,    87,    92,    52,    52,    55,    19,    99,    99,
      99,    80,    81,    82,    92,    79,     0,    68,    52,    27,
      26,    37,    38,    29,    30,    33,    34,    35,    36,    39,
      40,    41,    42,    31,    32,    44,    56,    43,    47,    19,
      53,    84,    53,    47,    79,    79,    58,    52,    92,    46,
      82,    48,    94,    95,    96,    96,    98,    98,    97,    97,
      97,    97,    97,    97,    97,    97,    99,    99,    99,    14,
      15,    16,    17,    18,    78,    92,   102,   103,    84,    78,
      55,    85,    78,    19,    71,    72,    73,    74,    75,    76,
      77,     8,    92,    48,    51,    85,    92,    52,    55,    53,
      48,    51,    79,    88,    59,    60,    92,    52,    92,    78,
      54,    70,    77,    92,    92,    52,    78,    79,    51,    79,
      79,    77,    51,    77,    51,    77
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    72,    73,    74,
      75,    76,    77,    78,    78,    78,    78,    78,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    84,    84,    85,    85,
      86,    87,    87,    88,    88,    88,    89,    90,    90,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      97,    98,    98,    98,    98,    99,    99,    99,    99,    99,
     100,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   102,   102,   103,   103
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     1,     2,     1,     1,     7,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     3,     5,
       7,     9,     3,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     5,     6,     7,     0,     2,     0,     2,
       3,     0,     1,     3,     5,     5,     3,     7,     7,     2,
       3,     1,     3,     1,     3,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     3,     2,     2,     2,     1,
       1,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "LET", "CONST", "MUT",
  "FN", "IF", "ELSE", "WHILE", "FOR", "RETURN", "BREAK", "CONTINUE",
  "I32_T", "F64_T", "BOOL_T", "CHAR_T", "STR_T", "IDENT", "STR_LIT",
  "INT_LIT", "FLOAT_LIT", "CHAR_LIT", "TRUE_LIT", "FALSE_LIT", "AND", "OR",
  "NOT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "LT", "GT", "LEQ", "GEQ",
  "EQ", "NEQ", "MULEQ", "DIVEQ", "PLUSEQ", "MINEQ", "QUESTION", "MOD",
  "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "COMMA",
  "SEMICOLON", "COLON", "ARROW", "ASSIGN", "AS", "LOOP", "IN", "RANGE",
  "RANGE_EQ", "LE", "GE", "NE", "IF_NO_ELSE", "$accept", "Program",
  "ItemList", "Item", "FnDecl", "RetTypeOpt", "ParamListOpt", "Param1",
  "Param2", "Param3", "Param4", "Param5", "Param", "Type", "Block",
  "StmtListOpt", "StmtList", "Stmt", "LetStmt", "TypeOpt", "InitOpt",
  "ReturnStmt", "ExprOpt", "IfStmt", "WhileStmt", "ForStmt", "ExprStmt",
  "Expr", "OrExpr", "AndExpr", "EqExpr", "RelExpr", "AddExpr", "MulExpr",
  "Unary", "Postfix", "Primary", "ArgListOpt", "ArgList", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    87,    87,    88,    98,    99,   103,   104,   109,   121,
     122,   126,   127,   128,   129,   130,   131,   135,   139,   143,
     148,   153,   158,   166,   167,   168,   169,   170,   175,   184,
     185,   189,   190,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   213,   222,   231,   243,   244,   248,   249,
     253,   262,   263,   267,   274,   282,   293,   303,   313,   326,
     336,   337,   341,   342,   346,   347,   351,   352,   353,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   369,   370,
     371,   375,   376,   377,   378,   382,   383,   384,   385,   386,
     391,   392,   399,   406,   407,   408,   409,   410,   411,   412,
     413,   418,   419,   423,   424
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

#line 2 "parser.y"
} // yy
#line 2354 "parser.cpp"

#line 427 "parser.y"

