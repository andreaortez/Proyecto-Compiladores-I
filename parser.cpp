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

  case 45: // TypeOpt: %empty
#line 234 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1496 "parser.cpp"
    break;

  case 46: // TypeOpt: COLON Type
#line 235 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1502 "parser.cpp"
    break;

  case 47: // InitOpt: %empty
#line 239 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1508 "parser.cpp"
    break;

  case 48: // InitOpt: ASSIGN Expr
#line 240 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1514 "parser.cpp"
    break;

  case 49: // ReturnStmt: RETURN ExprOpt SEMICOLON
#line 245 "parser.y"
    {
      auto s = std::make_unique<ast::Return>();
      s->value.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1524 "parser.cpp"
    break;

  case 50: // ExprOpt: %empty
#line 253 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1530 "parser.cpp"
    break;

  case 51: // ExprOpt: Expr
#line 254 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1536 "parser.cpp"
    break;

  case 52: // IfStmt: IF Expr Block
#line 259 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1547 "parser.cpp"
    break;

  case 53: // IfStmt: IF Expr Block ELSE IfStmt
#line 266 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[3].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[2].value.as < ast::Stmt* > ());
      s->elseS.reset(yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1559 "parser.cpp"
    break;

  case 54: // IfStmt: IF Expr Block ELSE Block
#line 274 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[3].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[2].value.as < ast::Stmt* > ());
      s->elseS.reset(yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1571 "parser.cpp"
    break;

  case 55: // WhileStmt: WHILE Expr Block
#line 285 "parser.y"
    {
      auto s = std::make_unique<ast::While>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->body.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1582 "parser.cpp"
    break;

  case 56: // ForStmt: FOR IDENT IN Expr RANGE Expr Block
#line 295 "parser.y"
    {
      auto s = std::make_unique<ast::ForIn>();
      s->var = std::move(yystack_[5].value.as < std::string > ());
      s->from.reset(yystack_[3].value.as < ast::Expr* > ());
      s->to.reset(yystack_[1].value.as < ast::Expr* > ());
      s->inclusive = false;
      s->body.reset(static_cast<ast::Block*>(yystack_[0].value.as < ast::Stmt* > ()));
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1596 "parser.cpp"
    break;

  case 57: // ForStmt: FOR IDENT IN Expr RANGE_EQ Expr Block
#line 305 "parser.y"
    {
      auto s = std::make_unique<ast::ForIn>();
      s->var = std::move(yystack_[5].value.as < std::string > ());
      s->from.reset(yystack_[3].value.as < ast::Expr* > ());
      s->to.reset(yystack_[1].value.as < ast::Expr* > ());
      s->inclusive = true;
      s->body.reset(static_cast<ast::Block*>(yystack_[0].value.as < ast::Stmt* > ()));
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1610 "parser.cpp"
    break;

  case 58: // ExprStmt: Expr SEMICOLON
#line 318 "parser.y"
    {
      auto s = std::make_unique<ast::ExprStmt>();
      s->expr.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1620 "parser.cpp"
    break;

  case 59: // Expr: IDENT ASSIGN Expr
#line 327 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Assign, std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1626 "parser.cpp"
    break;

  case 60: // Expr: OrExpr
#line 328 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1632 "parser.cpp"
    break;

  case 61: // OrExpr: OrExpr OR AndExpr
#line 332 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Or,  std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1638 "parser.cpp"
    break;

  case 62: // OrExpr: AndExpr
#line 333 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1644 "parser.cpp"
    break;

  case 63: // AndExpr: AndExpr AND EqExpr
#line 337 "parser.y"
                         { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::And, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1650 "parser.cpp"
    break;

  case 64: // AndExpr: EqExpr
#line 338 "parser.y"
                         { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1656 "parser.cpp"
    break;

  case 65: // EqExpr: RelExpr
#line 342 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1662 "parser.cpp"
    break;

  case 66: // EqExpr: RelExpr EQ RelExpr
#line 343 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Eq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1668 "parser.cpp"
    break;

  case 67: // EqExpr: RelExpr NE RelExpr
#line 344 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Ne, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1674 "parser.cpp"
    break;

  case 68: // RelExpr: AddExpr
#line 348 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1680 "parser.cpp"
    break;

  case 69: // RelExpr: AddExpr LT AddExpr
#line 349 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Lt, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1686 "parser.cpp"
    break;

  case 70: // RelExpr: AddExpr LE AddExpr
#line 350 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Le, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1692 "parser.cpp"
    break;

  case 71: // RelExpr: AddExpr GT AddExpr
#line 351 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Gt, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1698 "parser.cpp"
    break;

  case 72: // RelExpr: AddExpr GE AddExpr
#line 352 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Ge, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1704 "parser.cpp"
    break;

  case 73: // AddExpr: AddExpr PLUS MulExpr
#line 356 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Add, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1710 "parser.cpp"
    break;

  case 74: // AddExpr: AddExpr MINUS MulExpr
#line 357 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Sub, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1716 "parser.cpp"
    break;

  case 75: // AddExpr: MulExpr
#line 358 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1722 "parser.cpp"
    break;

  case 76: // MulExpr: MulExpr MULTIPLY Unary
#line 362 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Mul, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1728 "parser.cpp"
    break;

  case 77: // MulExpr: MulExpr DIVIDE Unary
#line 363 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Div, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1734 "parser.cpp"
    break;

  case 78: // MulExpr: MulExpr MOD Unary
#line 364 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Mod, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1740 "parser.cpp"
    break;

  case 79: // MulExpr: Unary
#line 365 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1746 "parser.cpp"
    break;

  case 80: // Unary: Unary AS Type
#line 369 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Cast(std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::move(yystack_[0].value.as < std::string > ())); }
#line 1752 "parser.cpp"
    break;

  case 81: // Unary: NOT Unary
#line 370 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Not, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1758 "parser.cpp"
    break;

  case 82: // Unary: PLUS Unary
#line 371 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Positive, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1764 "parser.cpp"
    break;

  case 83: // Unary: MINUS Unary
#line 372 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Negative, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1770 "parser.cpp"
    break;

  case 84: // Unary: Postfix
#line 373 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1776 "parser.cpp"
    break;

  case 85: // Postfix: Primary
#line 378 "parser.y"
    { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1782 "parser.cpp"
    break;

  case 86: // Postfix: Postfix LPAREN ArgListOpt RPAREN
#line 380 "parser.y"
    {
      auto call = new ast::Call();
      call->callee.reset(yystack_[3].value.as < ast::Expr* > ());
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()) { call->args = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
      yylhs.value.as < ast::Expr* > () = call;
    }
#line 1793 "parser.cpp"
    break;

  case 87: // Postfix: Postfix QMARK
#line 387 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Try( std::unique_ptr<ast::Expr>(yystack_[1].value.as < ast::Expr* > ()) );
    }
#line 1801 "parser.cpp"
    break;

  case 88: // Primary: IDENT
#line 393 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Ident(std::move(yystack_[0].value.as < std::string > ())); }
#line 1807 "parser.cpp"
    break;

  case 89: // Primary: INT_LIT
#line 394 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::IntLit(yystack_[0].value.as < long long > ()); }
#line 1813 "parser.cpp"
    break;

  case 90: // Primary: FLOAT_LIT
#line 395 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::FloatLit(yystack_[0].value.as < double > ()); }
#line 1819 "parser.cpp"
    break;

  case 91: // Primary: TRUE_LIT
#line 396 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(true); }
#line 1825 "parser.cpp"
    break;

  case 92: // Primary: FALSE_LIT
#line 397 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(false); }
#line 1831 "parser.cpp"
    break;

  case 93: // Primary: CHAR_LIT
#line 398 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::CharLit(yystack_[0].value.as < char > ()); }
#line 1837 "parser.cpp"
    break;

  case 94: // Primary: STR_LIT
#line 399 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::StringLit(std::move(yystack_[0].value.as < std::string > ())); }
#line 1843 "parser.cpp"
    break;

  case 95: // Primary: LPAREN Expr RPAREN
#line 400 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[1].value.as < ast::Expr* > (); }
#line 1849 "parser.cpp"
    break;

  case 96: // ArgListOpt: %empty
#line 405 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = nullptr; }
#line 1855 "parser.cpp"
    break;

  case 97: // ArgListOpt: ArgList
#line 406 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1861 "parser.cpp"
    break;

  case 98: // ArgList: Expr
#line 410 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = new std::vector<std::unique_ptr<ast::Expr>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); }
#line 1867 "parser.cpp"
    break;

  case 99: // ArgList: ArgList COMMA Expr
#line 411 "parser.y"
                          { yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1873 "parser.cpp"
    break;


#line 1877 "parser.cpp"

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









  const signed char parser::yypact_ninf_ = -112;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      72,     7,    -2,   122,   122,     1,   122,   -21,     0,     5,
    -112,  -112,  -112,  -112,  -112,  -112,   134,   134,   134,    12,
     122,    10,    58,    72,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,    21,    50,    60,  -112,   -24,    28,
      14,    38,   -28,  -112,    90,    61,    69,    10,    10,    62,
      66,  -112,  -112,  -112,   122,  -112,    38,    38,    38,    76,
      12,  -112,    75,  -112,  -112,  -112,  -112,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
      57,  -112,   122,    61,    57,    70,   101,   114,  -112,   122,
    -112,  -112,  -112,  -112,  -112,    60,  -112,  -112,  -112,    14,
      14,     9,     9,     9,     9,    38,    38,    38,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,    79,    77,    70,  -112,   122,
      78,    84,    83,  -112,  -112,  -112,  -112,  -112,    81,     3,
      33,  -112,   122,    86,  -112,  -112,    57,    85,   101,  -112,
    -112,   122,   122,  -112,  -112,  -112,    57,    10,    89,    10,
      10,  -112,  -112,   101,  -112,  -112,    91,   101,   102,   101,
    -112
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,    50,     0,     0,    88,
      94,    89,    90,    93,    91,    92,     0,     0,     0,    29,
       0,     0,     0,     3,     4,     6,    39,     7,    33,    34,
      35,    36,    37,    38,     0,    60,    62,    64,    65,    68,
      75,    79,    84,    85,     0,    45,     0,     0,     0,     0,
       0,    51,    40,    41,     0,    88,    81,    82,    83,     0,
      30,    31,     0,    42,     1,     5,    58,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    87,    96,    45,     0,    47,    11,    52,    55,     0,
      49,    59,    28,    32,    95,    61,    63,    66,    67,    73,
      74,    69,    71,    70,    72,    76,    77,    78,    23,    24,
      25,    26,    27,    80,    98,     0,    97,    47,    46,     0,
       0,     0,     0,    12,    13,    14,    15,    16,    17,     0,
       0,    86,     0,     0,    48,    43,     0,     9,     0,    54,
      53,     0,     0,    99,    44,    22,     0,     0,    18,     0,
       0,    10,     8,     0,    56,    57,    19,     0,    20,     0,
      21
  };

  const signed char
  parser::yypgoto_[] =
  {
    -112,  -112,  -112,   113,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -111,   -77,   -19,  -112,  -112,   -11,  -112,    64,
      42,  -112,  -112,    31,  -112,  -112,  -112,    -3,  -112,    98,
      99,    37,    29,    26,   -12,  -112,  -112,  -112,  -112
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    22,    23,    24,    25,   147,   122,   123,   124,   125,
     126,   127,   128,   113,    26,    59,    60,    27,    28,    85,
     120,    29,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   115,   116
  };

  const unsigned char
  parser::yytable_[] =
  {
      47,    48,    63,    51,    56,    57,    58,   118,    61,     3,
      81,    44,    69,    70,    82,     1,    46,    62,     3,    49,
       4,     5,     6,     7,     8,    45,    52,   148,    87,    88,
       9,    10,    11,    12,    13,    14,    15,    71,    72,    16,
      17,    18,   156,    19,    77,    78,   158,    53,   160,    93,
      19,    91,    19,    79,    20,    54,    71,    72,    64,   145,
      73,    74,    75,    76,    21,   105,   106,   107,    66,   151,
     108,   109,   110,   111,   112,     1,    67,     2,     3,   114,
       4,     5,     6,     7,     8,    68,   130,   141,   142,    80,
       9,    10,    11,    12,    13,    14,    15,    99,   100,    16,
      17,    18,   101,   102,   103,   104,    97,    98,    83,    84,
     139,    86,    19,    90,    20,    89,   134,    92,    94,   121,
     119,   129,   131,   132,    21,   135,   137,   138,   152,   143,
     154,   155,   136,   144,   146,   153,    65,   157,   149,   150,
       9,    10,    11,    12,    13,    14,    15,   117,   159,    16,
      17,    18,    55,    10,    11,    12,    13,    14,    15,   133,
     140,    16,    17,    18,    20,    95,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,    20
  };

  const short
  parser::yycheck_[] =
  {
       3,     4,    21,     6,    16,    17,    18,    84,    19,     6,
      38,     4,    36,    37,    42,     3,    18,    20,     6,    18,
       8,     9,    10,    11,    12,    18,    47,   138,    47,    48,
      18,    19,    20,    21,    22,    23,    24,    28,    29,    27,
      28,    29,   153,    40,    30,    31,   157,    47,   159,    60,
      40,    54,    40,    39,    42,    50,    28,    29,     0,   136,
      32,    33,    34,    35,    52,    77,    78,    79,    47,   146,
      13,    14,    15,    16,    17,     3,    26,     5,     6,    82,
       8,     9,    10,    11,    12,    25,    89,    54,    55,    51,
      18,    19,    20,    21,    22,    23,    24,    71,    72,    27,
      28,    29,    73,    74,    75,    76,    69,    70,    18,    48,
     129,    42,    40,    47,    42,    53,   119,    41,    43,    18,
      50,     7,    43,    46,    52,    47,    43,    46,   147,   132,
     149,   150,    48,    47,    49,    46,    23,    46,   141,   142,
      18,    19,    20,    21,    22,    23,    24,    83,    46,    27,
      28,    29,    18,    19,    20,    21,    22,    23,    24,   117,
     129,    27,    28,    29,    42,    67,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     5,     6,     8,     9,    10,    11,    12,    18,
      19,    20,    21,    22,    23,    24,    27,    28,    29,    40,
      42,    52,    58,    59,    60,    61,    71,    74,    75,    78,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     4,    18,    18,    84,    84,    18,
      79,    84,    47,    47,    50,    18,    91,    91,    91,    72,
      73,    74,    84,    71,     0,    60,    47,    26,    25,    36,
      37,    28,    29,    32,    33,    34,    35,    30,    31,    39,
      51,    38,    42,    18,    48,    76,    42,    71,    71,    53,
      47,    84,    41,    74,    43,    86,    87,    88,    88,    90,
      90,    89,    89,    89,    89,    91,    91,    91,    13,    14,
      15,    16,    17,    70,    84,    94,    95,    76,    70,    50,
      77,    18,    63,    64,    65,    66,    67,    68,    69,     7,
      84,    43,    46,    77,    84,    47,    48,    43,    46,    71,
      80,    54,    55,    84,    47,    70,    49,    62,    69,    84,
      84,    70,    71,    46,    71,    71,    69,    46,    69,    46,
      69
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    57,    58,    58,    59,    59,    60,    60,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    65,    66,
      67,    68,    69,    70,    70,    70,    70,    70,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      79,    79,    80,    80,    80,    81,    82,    82,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    87,    88,    88,
      88,    88,    88,    89,    89,    89,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    95,    95
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     1,     2,     1,     1,     7,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     3,     5,
       7,     9,     3,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     5,     6,     0,     2,     0,     2,     3,
       0,     1,     3,     5,     5,     3,     7,     7,     2,     3,
       1,     3,     1,     3,     1,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     2,     2,     2,     1,     1,     4,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "LET", "MUT", "FN",
  "IF", "ELSE", "WHILE", "FOR", "RETURN", "BREAK", "CONTINUE", "I32_T",
  "F64_T", "BOOL_T", "CHAR_T", "STR_T", "IDENT", "STR_LIT", "INT_LIT",
  "FLOAT_LIT", "CHAR_LIT", "TRUE_LIT", "FALSE_LIT", "AND", "OR", "NOT",
  "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "LT", "GT", "LE", "GE", "EQ",
  "NE", "QMARK", "MOD", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACK",
  "RBRACK", "COMMA", "SEMICOLON", "COLON", "ARROW", "ASSIGN", "AS", "LOOP",
  "IN", "RANGE", "RANGE_EQ", "IF_NO_ELSE", "$accept", "Program",
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
     202,   203,   204,   213,   222,   234,   235,   239,   240,   244,
     253,   254,   258,   265,   273,   284,   294,   304,   317,   327,
     328,   332,   333,   337,   338,   342,   343,   344,   348,   349,
     350,   351,   352,   356,   357,   358,   362,   363,   364,   365,
     369,   370,   371,   372,   373,   378,   379,   386,   393,   394,
     395,   396,   397,   398,   399,   400,   405,   406,   410,   411
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
#line 2306 "parser.cpp"

#line 414 "parser.y"

