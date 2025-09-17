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
#line 88 "parser.y"
                           { yylhs.value.as < ast::Program* > () = new ast::Program(); out.reset(yylhs.value.as < ast::Program* > ()); }
#line 1200 "parser.cpp"
    break;

  case 3: // Program: ItemList
#line 89 "parser.y"
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
#line 99 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > () = new std::vector<std::unique_ptr<ast::Item>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > ()->emplace_back(yystack_[0].value.as < ast::Item* > ()); }
#line 1218 "parser.cpp"
    break;

  case 5: // ItemList: ItemList Item
#line 100 "parser.y"
                          { yystack_[1].value.as < std::vector<std::unique_ptr<ast::Item>>* > ()->emplace_back(yystack_[0].value.as < ast::Item* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > () = yystack_[1].value.as < std::vector<std::unique_ptr<ast::Item>>* > (); }
#line 1224 "parser.cpp"
    break;

  case 6: // Item: FnDecl
#line 104 "parser.y"
                          { yylhs.value.as < ast::Item* > () = new ast::FnItem( std::unique_ptr<ast::Fn>(yystack_[0].value.as < ast::Fn* > ()) ); }
#line 1230 "parser.cpp"
    break;

  case 7: // Item: Stmt
#line 105 "parser.y"
                          { yylhs.value.as < ast::Item* > () = new ast::StmtItem( std::unique_ptr<ast::Stmt>(yystack_[0].value.as < ast::Stmt* > ()) ); }
#line 1236 "parser.cpp"
    break;

  case 8: // FnDecl: FN IDENT LPAREN ParamListOpt RPAREN RetTypeOpt Block
#line 111 "parser.y"
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
#line 122 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1255 "parser.cpp"
    break;

  case 10: // RetTypeOpt: ARROW Type
#line 123 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1261 "parser.cpp"
    break;

  case 11: // ParamListOpt: %empty
#line 127 "parser.y"
                           { yylhs.value.as < std::vector<ast::Param>* > () = nullptr; }
#line 1267 "parser.cpp"
    break;

  case 12: // ParamListOpt: Param1
#line 128 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1273 "parser.cpp"
    break;

  case 13: // ParamListOpt: Param2
#line 129 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1279 "parser.cpp"
    break;

  case 14: // ParamListOpt: Param3
#line 130 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1285 "parser.cpp"
    break;

  case 15: // ParamListOpt: Param4
#line 131 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1291 "parser.cpp"
    break;

  case 16: // ParamListOpt: Param5
#line 132 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1297 "parser.cpp"
    break;

  case 17: // Param1: Param
#line 136 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[0].value.as < ast::Param > () }; }
#line 1303 "parser.cpp"
    break;

  case 18: // Param2: Param COMMA Param
#line 140 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1309 "parser.cpp"
    break;

  case 19: // Param3: Param COMMA Param COMMA Param
#line 145 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1315 "parser.cpp"
    break;

  case 20: // Param4: Param COMMA Param COMMA Param COMMA Param
#line 150 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[6].value.as < ast::Param > (), yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1321 "parser.cpp"
    break;

  case 21: // Param5: Param COMMA Param COMMA Param COMMA Param COMMA Param
#line 155 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[8].value.as < ast::Param > (), yystack_[6].value.as < ast::Param > (), yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1327 "parser.cpp"
    break;

  case 22: // Param: IDENT COLON Type
#line 160 "parser.y"
    {
      yylhs.value.as < ast::Param > ().name = std::move(yystack_[2].value.as < std::string > ());
      yylhs.value.as < ast::Param > ().type   = std::move(yystack_[0].value.as < std::string > ());
    }
#line 1336 "parser.cpp"
    break;

  case 23: // Type: I32_T
#line 167 "parser.y"
                          { yylhs.value.as < std::string > () = "i32"; }
#line 1342 "parser.cpp"
    break;

  case 24: // Type: F64_T
#line 168 "parser.y"
                          { yylhs.value.as < std::string > () = "f64"; }
#line 1348 "parser.cpp"
    break;

  case 25: // Type: BOOL_T
#line 169 "parser.y"
                          { yylhs.value.as < std::string > () = "bool"; }
#line 1354 "parser.cpp"
    break;

  case 26: // Type: CHAR_T
#line 170 "parser.y"
                          { yylhs.value.as < std::string > () = "char"; }
#line 1360 "parser.cpp"
    break;

  case 27: // Type: STR_T
#line 171 "parser.y"
                          { yylhs.value.as < std::string > () = "str"; }
#line 1366 "parser.cpp"
    break;

  case 28: // Block: LBRACE StmtListOpt RBRACE
#line 177 "parser.y"
    {
      auto b = std::make_unique<ast::Block>();
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()) { b->stmts = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
      yylhs.value.as < ast::Stmt* > () = b.release();
    }
#line 1376 "parser.cpp"
    break;

  case 29: // StmtListOpt: %empty
#line 185 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = nullptr; }
#line 1382 "parser.cpp"
    break;

  case 30: // StmtListOpt: StmtList
#line 186 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
#line 1388 "parser.cpp"
    break;

  case 31: // StmtList: Stmt
#line 190 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = new std::vector<std::unique_ptr<ast::Stmt>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()->emplace_back(yystack_[0].value.as < ast::Stmt* > ()); }
#line 1394 "parser.cpp"
    break;

  case 32: // StmtList: StmtList Stmt
#line 191 "parser.y"
                          { yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()->emplace_back(yystack_[0].value.as < ast::Stmt* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
#line 1400 "parser.cpp"
    break;

  case 33: // Stmt: LetStmt
#line 196 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1406 "parser.cpp"
    break;

  case 34: // Stmt: ReturnStmt
#line 197 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1412 "parser.cpp"
    break;

  case 35: // Stmt: IfStmt
#line 198 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1418 "parser.cpp"
    break;

  case 36: // Stmt: WhileStmt
#line 199 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1424 "parser.cpp"
    break;

  case 37: // Stmt: ForStmt
#line 200 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1430 "parser.cpp"
    break;

  case 38: // Stmt: ExprStmt
#line 201 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1436 "parser.cpp"
    break;

  case 39: // Stmt: Block
#line 202 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1442 "parser.cpp"
    break;

  case 40: // Stmt: BREAK SEMICOLON
#line 203 "parser.y"
                             { yylhs.value.as < ast::Stmt* > () = new ast::Break(); }
#line 1448 "parser.cpp"
    break;

  case 41: // Stmt: CONTINUE SEMICOLON
#line 204 "parser.y"
                             { yylhs.value.as < ast::Stmt* > () = new ast::Continue(); }
#line 1454 "parser.cpp"
    break;

  case 42: // Stmt: LOOP Block
#line 206 "parser.y"
    { 
      auto s = std::make_unique<ast::Loop>();
      s->body.reset(static_cast<ast::Block*>(yystack_[0].value.as < ast::Stmt* > ())); 
      yylhs.value.as < ast::Stmt* > () = s.release(); 
    }
#line 1464 "parser.cpp"
    break;

  case 43: // LetStmt: LET IDENT TypeOpt InitOpt SEMICOLON
#line 215 "parser.y"
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
#line 224 "parser.y"
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
#line 233 "parser.y"
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
#line 244 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1509 "parser.cpp"
    break;

  case 47: // TypeOpt: COLON Type
#line 245 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1515 "parser.cpp"
    break;

  case 48: // InitOpt: %empty
#line 249 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1521 "parser.cpp"
    break;

  case 49: // InitOpt: ASSIGN Expr
#line 250 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1527 "parser.cpp"
    break;

  case 50: // ReturnStmt: RETURN ExprOpt SEMICOLON
#line 255 "parser.y"
    {
      auto s = std::make_unique<ast::Return>();
      s->value.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1537 "parser.cpp"
    break;

  case 51: // ExprOpt: %empty
#line 263 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1543 "parser.cpp"
    break;

  case 52: // ExprOpt: Expr
#line 264 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1549 "parser.cpp"
    break;

  case 53: // IfStmt: IF Expr Block
#line 269 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1560 "parser.cpp"
    break;

  case 54: // IfStmt: IF Expr Block ELSE IfStmt
#line 276 "parser.y"
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
#line 284 "parser.y"
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
#line 295 "parser.y"
    {
      auto s = std::make_unique<ast::While>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->body.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1595 "parser.cpp"
    break;

  case 57: // ForStmt: FOR IDENT IN Expr RANGE Expr Block
#line 305 "parser.y"
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
#line 315 "parser.y"
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
#line 328 "parser.y"
    {
      auto s = std::make_unique<ast::ExprStmt>();
      s->expr.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1633 "parser.cpp"
    break;

  case 60: // Expr: IDENT ASSIGN Expr
#line 338 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Binary(
        ast::BinOp::Assign,
        std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())),
        std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())
      );
    }
#line 1645 "parser.cpp"
    break;

  case 61: // Expr: IDENT PLUSEQ Expr
#line 346 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Binary(
        ast::BinOp::AddAssign,
        std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())),
        std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())
      );
    }
#line 1657 "parser.cpp"
    break;

  case 62: // Expr: IDENT MINEQ Expr
#line 354 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Binary(
        ast::BinOp::SubAssign,
        std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())),
        std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())
      );
    }
#line 1669 "parser.cpp"
    break;

  case 63: // Expr: IDENT MULEQ Expr
#line 362 "parser.y"
  {
    yylhs.value.as < ast::Expr* > () = new ast::Binary(
      ast::BinOp::MulAssign,
      std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())),
      std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())
    );
  }
#line 1681 "parser.cpp"
    break;

  case 64: // Expr: IDENT DIVEQ Expr
#line 370 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Binary(
        ast::BinOp::DivAssign,
        std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())),
        std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())
      );
    }
#line 1693 "parser.cpp"
    break;

  case 65: // Expr: IDENT MODEQ Expr
#line 378 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Binary(
        ast::BinOp::ModAssign,
        std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())),
        std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())
      );
    }
#line 1705 "parser.cpp"
    break;

  case 66: // Expr: OrExpr
#line 385 "parser.y"
              { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1711 "parser.cpp"
    break;

  case 67: // OrExpr: OrExpr OR AndExpr
#line 389 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Or,  std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1717 "parser.cpp"
    break;

  case 68: // OrExpr: AndExpr
#line 390 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1723 "parser.cpp"
    break;

  case 69: // AndExpr: AndExpr AND EqExpr
#line 394 "parser.y"
                         { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::And, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1729 "parser.cpp"
    break;

  case 70: // AndExpr: EqExpr
#line 395 "parser.y"
                         { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1735 "parser.cpp"
    break;

  case 71: // EqExpr: RelExpr
#line 399 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1741 "parser.cpp"
    break;

  case 72: // EqExpr: RelExpr EQ RelExpr
#line 400 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Eq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1747 "parser.cpp"
    break;

  case 73: // EqExpr: RelExpr NEQ RelExpr
#line 401 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Neq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1753 "parser.cpp"
    break;

  case 74: // RelExpr: AddExpr
#line 405 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1759 "parser.cpp"
    break;

  case 75: // RelExpr: AddExpr LT AddExpr
#line 406 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Lt, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1765 "parser.cpp"
    break;

  case 76: // RelExpr: AddExpr LEQ AddExpr
#line 407 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Leq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1771 "parser.cpp"
    break;

  case 77: // RelExpr: AddExpr GT AddExpr
#line 408 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Gt, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1777 "parser.cpp"
    break;

  case 78: // RelExpr: AddExpr GEQ AddExpr
#line 409 "parser.y"
                            { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Geq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1783 "parser.cpp"
    break;

  case 79: // AddExpr: AddExpr PLUS MulExpr
#line 413 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Add, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1789 "parser.cpp"
    break;

  case 80: // AddExpr: AddExpr MINUS MulExpr
#line 414 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Sub, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1795 "parser.cpp"
    break;

  case 81: // AddExpr: MulExpr
#line 415 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1801 "parser.cpp"
    break;

  case 82: // MulExpr: MulExpr MULTIPLY Unary
#line 419 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Mul, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1807 "parser.cpp"
    break;

  case 83: // MulExpr: MulExpr DIVIDE Unary
#line 420 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Div, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1813 "parser.cpp"
    break;

  case 84: // MulExpr: MulExpr MOD Unary
#line 421 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Mod, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1819 "parser.cpp"
    break;

  case 85: // MulExpr: Unary
#line 422 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1825 "parser.cpp"
    break;

  case 86: // Unary: Unary AS Type
#line 426 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Cast(std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::move(yystack_[0].value.as < std::string > ())); }
#line 1831 "parser.cpp"
    break;

  case 87: // Unary: NOT Unary
#line 427 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Not, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1837 "parser.cpp"
    break;

  case 88: // Unary: PLUS Unary
#line 428 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Positive, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1843 "parser.cpp"
    break;

  case 89: // Unary: MINUS Unary
#line 429 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Negative, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1849 "parser.cpp"
    break;

  case 90: // Unary: Postfix
#line 430 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1855 "parser.cpp"
    break;

  case 91: // Postfix: Primary
#line 435 "parser.y"
    { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1861 "parser.cpp"
    break;

  case 92: // Postfix: Postfix LPAREN ArgListOpt RPAREN
#line 437 "parser.y"
    {
      auto call = new ast::Call();
      call->callee.reset(yystack_[3].value.as < ast::Expr* > ());
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()) { call->args = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
      yylhs.value.as < ast::Expr* > () = call;
    }
#line 1872 "parser.cpp"
    break;

  case 93: // Postfix: Postfix QUESTION
#line 444 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Try( std::unique_ptr<ast::Expr>(yystack_[1].value.as < ast::Expr* > ()) );
    }
#line 1880 "parser.cpp"
    break;

  case 94: // Primary: IDENT
#line 450 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Ident(std::move(yystack_[0].value.as < std::string > ())); }
#line 1886 "parser.cpp"
    break;

  case 95: // Primary: INT_LIT
#line 451 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::IntLit(yystack_[0].value.as < long long > ()); }
#line 1892 "parser.cpp"
    break;

  case 96: // Primary: FLOAT_LIT
#line 452 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::FloatLit(yystack_[0].value.as < double > ()); }
#line 1898 "parser.cpp"
    break;

  case 97: // Primary: TRUE_LIT
#line 453 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(true); }
#line 1904 "parser.cpp"
    break;

  case 98: // Primary: FALSE_LIT
#line 454 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(false); }
#line 1910 "parser.cpp"
    break;

  case 99: // Primary: CHAR_LIT
#line 455 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::CharLit(yystack_[0].value.as < char > ()); }
#line 1916 "parser.cpp"
    break;

  case 100: // Primary: STR_LIT
#line 456 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::StringLit(std::move(yystack_[0].value.as < std::string > ())); }
#line 1922 "parser.cpp"
    break;

  case 101: // Primary: LPAREN Expr RPAREN
#line 457 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[1].value.as < ast::Expr* > (); }
#line 1928 "parser.cpp"
    break;

  case 102: // ArgListOpt: %empty
#line 462 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = nullptr; }
#line 1934 "parser.cpp"
    break;

  case 103: // ArgListOpt: ArgList
#line 463 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1940 "parser.cpp"
    break;

  case 104: // ArgList: Expr
#line 467 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = new std::vector<std::unique_ptr<ast::Expr>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); }
#line 1946 "parser.cpp"
    break;

  case 105: // ArgList: ArgList COMMA Expr
#line 468 "parser.y"
                          { yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1952 "parser.cpp"
    break;


#line 1956 "parser.cpp"

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









  const signed char parser::yypact_ninf_ = -105;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      15,    -3,   -13,     4,   135,   135,    14,   135,   -39,   -33,
      60,  -105,  -105,  -105,  -105,  -105,  -105,   147,   147,   147,
      85,   135,     0,    48,    15,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,     7,    42,    45,  -105,    -8,
      88,    19,    17,   -35,  -105,    56,    36,    37,    63,     0,
       0,    53,    67,  -105,  -105,  -105,   135,   135,   135,   135,
     135,   135,  -105,    17,    17,    17,    72,    85,  -105,    77,
    -105,  -105,  -105,  -105,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,    66,  -105,   135,
      36,    66,    71,    66,   110,   122,  -105,   135,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    45,  -105,
    -105,  -105,    19,    19,    12,    12,    12,    12,    17,    17,
      17,  -105,  -105,  -105,  -105,  -105,  -105,  -105,    83,    86,
      71,  -105,   135,    87,    93,    90,    92,  -105,  -105,  -105,
    -105,  -105,    98,     1,    -2,  -105,   135,   108,  -105,  -105,
     135,    66,    84,   110,  -105,  -105,   135,   135,  -105,  -105,
     109,  -105,    66,     0,    99,     0,     0,  -105,  -105,  -105,
     110,  -105,  -105,   121,   110,   126,   110,  -105
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,     0,    51,     0,     0,
      94,   100,    95,    96,    99,    97,    98,     0,     0,     0,
      29,     0,     0,     0,     3,     4,     6,    39,     7,    33,
      34,    35,    36,    37,    38,     0,    66,    68,    70,    71,
      74,    81,    85,    90,    91,     0,    46,     0,     0,     0,
       0,     0,     0,    52,    40,    41,     0,     0,     0,     0,
       0,     0,    94,    87,    88,    89,     0,    30,    31,     0,
      42,     1,     5,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,   102,
      46,     0,    48,     0,    11,    53,    56,     0,    50,    63,
      64,    61,    62,    65,    60,    28,    32,   101,    67,    69,
      72,    73,    79,    80,    75,    77,    76,    78,    82,    83,
      84,    23,    24,    25,    26,    27,    86,   104,     0,   103,
      48,    47,     0,     0,     0,     0,     0,    12,    13,    14,
      15,    16,    17,     0,     0,    92,     0,     0,    49,    43,
       0,     0,     9,     0,    55,    54,     0,     0,   105,    44,
       0,    22,     0,     0,    18,     0,     0,    45,    10,     8,
       0,    57,    58,    19,     0,    20,     0,    21
  };

  const short
  parser::yypgoto_[] =
  {
    -105,  -105,  -105,   150,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -104,   -86,   -18,  -105,  -105,    -5,  -105,    89,
      50,  -105,  -105,    38,  -105,  -105,  -105,    -4,  -105,   111,
     107,    -9,    54,     8,    -7,  -105,  -105,  -105,  -105
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    23,    24,    25,    26,   163,   136,   137,   138,   139,
     140,   141,   142,   126,    27,    66,    67,    28,    29,    92,
     133,    30,    52,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,   128,   129
  };

  const unsigned char
  parser::yytable_[] =
  {
      49,    50,    45,    53,    70,   131,    47,   134,     4,    88,
      63,    64,    65,    89,    54,    68,    46,    69,     1,     2,
      55,     3,     4,    48,     5,     6,     7,     8,     9,    76,
      77,    95,    96,    51,    10,    11,    12,    13,    14,    15,
      16,    78,    79,    17,    18,    19,    20,    20,    71,   164,
      84,    85,    99,   100,   101,   102,   103,   104,   156,   157,
      73,    20,   106,    21,    86,   161,   173,   110,   111,    74,
     175,    75,   177,    22,    87,    90,   168,   118,   119,   120,
     121,   122,   123,   124,   125,   127,   112,   113,     1,     2,
      91,    93,     4,   144,     5,     6,     7,     8,     9,    56,
      57,    58,    59,    60,    10,    11,    12,    13,    14,    15,
      16,    94,    97,    17,    18,    19,    61,    78,    79,   105,
      98,    80,    81,    82,    83,   154,   107,   132,   148,   135,
     143,    20,   145,    21,   114,   115,   116,   117,   146,   162,
     149,   152,   158,    22,   151,   169,   160,   171,   172,   150,
     153,   170,   165,   166,    10,    11,    12,    13,    14,    15,
      16,   159,   167,    17,    18,    19,    62,    11,    12,    13,
      14,    15,    16,   174,    72,    17,    18,    19,   176,   130,
     147,   155,   109,    21,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21
  };

  const short
  parser::yycheck_[] =
  {
       4,     5,     5,     7,    22,    91,    19,    93,     7,    44,
      17,    18,    19,    48,    53,    20,    19,    21,     3,     4,
      53,     6,     7,    19,     9,    10,    11,    12,    13,    37,
      38,    49,    50,    19,    19,    20,    21,    22,    23,    24,
      25,    29,    30,    28,    29,    30,    46,    46,     0,   153,
      31,    32,    56,    57,    58,    59,    60,    61,    60,    61,
      53,    46,    67,    48,    45,   151,   170,    76,    77,    27,
     174,    26,   176,    58,    57,    19,   162,    84,    85,    86,
      14,    15,    16,    17,    18,    89,    78,    79,     3,     4,
      54,    54,     7,    97,     9,    10,    11,    12,    13,    39,
      40,    41,    42,    43,    19,    20,    21,    22,    23,    24,
      25,    48,    59,    28,    29,    30,    56,    29,    30,    47,
      53,    33,    34,    35,    36,   143,    49,    56,   132,    19,
       8,    46,    49,    48,    80,    81,    82,    83,    52,    55,
      53,    49,   146,    58,    54,   163,   150,   165,   166,    56,
      52,    52,   156,   157,    19,    20,    21,    22,    23,    24,
      25,    53,    53,    28,    29,    30,    19,    20,    21,    22,
      23,    24,    25,    52,    24,    28,    29,    30,    52,    90,
     130,   143,    75,    48,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     6,     7,     9,    10,    11,    12,    13,
      19,    20,    21,    22,    23,    24,    25,    28,    29,    30,
      46,    48,    58,    64,    65,    66,    67,    77,    80,    81,
      84,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     5,    19,    19,    19,    90,
      90,    19,    85,    90,    53,    53,    39,    40,    41,    42,
      43,    56,    19,    97,    97,    97,    78,    79,    80,    90,
      77,     0,    66,    53,    27,    26,    37,    38,    29,    30,
      33,    34,    35,    36,    31,    32,    45,    57,    44,    48,
      19,    54,    82,    54,    48,    77,    77,    59,    53,    90,
      90,    90,    90,    90,    90,    47,    80,    49,    92,    93,
      94,    94,    96,    96,    95,    95,    95,    95,    97,    97,
      97,    14,    15,    16,    17,    18,    76,    90,   100,   101,
      82,    76,    56,    83,    76,    19,    69,    70,    71,    72,
      73,    74,    75,     8,    90,    49,    52,    83,    90,    53,
      56,    54,    49,    52,    77,    86,    60,    61,    90,    53,
      90,    76,    55,    68,    75,    90,    90,    53,    76,    77,
      52,    77,    77,    75,    52,    75,    52,    75
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    63,    64,    64,    65,    65,    66,    66,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    70,    71,    72,
      73,    74,    75,    76,    76,    76,    76,    76,    77,    78,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    81,    82,    82,    83,    83,
      84,    85,    85,    86,    86,    86,    87,    88,    88,    89,
      90,    90,    90,    90,    90,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    94,    94,    94,    94,    94,    95,
      95,    95,    96,    96,    96,    96,    97,    97,    97,    97,
      97,    98,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   101,   101
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
       3,     3,     3,     3,     3,     3,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     2,     2,     2,
       1,     1,     4,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     3
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
  "EQ", "NEQ", "MULEQ", "DIVEQ", "PLUSEQ", "MINEQ", "MODEQ", "QUESTION",
  "MOD", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "COMMA", "SEMICOLON", "COLON", "ARROW", "ASSIGN", "AS", "LOOP", "IN",
  "RANGE", "RANGE_EQ", "IF_NO_ELSE", "$accept", "Program", "ItemList",
  "Item", "FnDecl", "RetTypeOpt", "ParamListOpt", "Param1", "Param2",
  "Param3", "Param4", "Param5", "Param", "Type", "Block", "StmtListOpt",
  "StmtList", "Stmt", "LetStmt", "TypeOpt", "InitOpt", "ReturnStmt",
  "ExprOpt", "IfStmt", "WhileStmt", "ForStmt", "ExprStmt", "Expr",
  "OrExpr", "AndExpr", "EqExpr", "RelExpr", "AddExpr", "MulExpr", "Unary",
  "Postfix", "Primary", "ArgListOpt", "ArgList", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    88,    88,    89,    99,   100,   104,   105,   110,   122,
     123,   127,   128,   129,   130,   131,   132,   136,   140,   144,
     149,   154,   159,   167,   168,   169,   170,   171,   176,   185,
     186,   190,   191,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   214,   223,   232,   244,   245,   249,   250,
     254,   263,   264,   268,   275,   283,   294,   304,   314,   327,
     337,   345,   353,   361,   369,   377,   385,   389,   390,   394,
     395,   399,   400,   401,   405,   406,   407,   408,   409,   413,
     414,   415,   419,   420,   421,   422,   426,   427,   428,   429,
     430,   435,   436,   443,   450,   451,   452,   453,   454,   455,
     456,   457,   462,   463,   467,   468
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
#line 2396 "parser.cpp"

#line 471 "parser.y"

