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
      case symbol_kind::S_ForInitOpt: // ForInitOpt
      case symbol_kind::S_ForCondOpt: // ForCondOpt
      case symbol_kind::S_ForPostOpt: // ForPostOpt
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
      case symbol_kind::S_ForInitOpt: // ForInitOpt
      case symbol_kind::S_ForCondOpt: // ForCondOpt
      case symbol_kind::S_ForPostOpt: // ForPostOpt
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
      case symbol_kind::S_ForInitOpt: // ForInitOpt
      case symbol_kind::S_ForCondOpt: // ForCondOpt
      case symbol_kind::S_ForPostOpt: // ForPostOpt
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
      case symbol_kind::S_ForInitOpt: // ForInitOpt
      case symbol_kind::S_ForCondOpt: // ForCondOpt
      case symbol_kind::S_ForPostOpt: // ForPostOpt
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
      case symbol_kind::S_ForInitOpt: // ForInitOpt
      case symbol_kind::S_ForCondOpt: // ForCondOpt
      case symbol_kind::S_ForPostOpt: // ForPostOpt
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
      case symbol_kind::S_ForInitOpt: // ForInitOpt
      case symbol_kind::S_ForCondOpt: // ForCondOpt
      case symbol_kind::S_ForPostOpt: // ForPostOpt
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
      case symbol_kind::S_ForInitOpt: // ForInitOpt
      case symbol_kind::S_ForCondOpt: // ForCondOpt
      case symbol_kind::S_ForPostOpt: // ForPostOpt
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
#line 84 "parser.y"
                           { yylhs.value.as < ast::Program* > () = new ast::Program(); out.reset(yylhs.value.as < ast::Program* > ()); }
#line 1221 "parser.cpp"
    break;

  case 3: // Program: ItemList
#line 85 "parser.y"
                          { auto p = new ast::Program(); p->items = std::move(*yystack_[0].value.as < std::vector<std::unique_ptr<ast::Item>>* > ()); delete yystack_[0].value.as < std::vector<std::unique_ptr<ast::Item>>* > (); yylhs.value.as < ast::Program* > () = p; out.reset(p); }
#line 1227 "parser.cpp"
    break;

  case 4: // ItemList: Item
#line 89 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > () = new std::vector<std::unique_ptr<ast::Item>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > ()->emplace_back(yystack_[0].value.as < ast::Item* > ()); }
#line 1233 "parser.cpp"
    break;

  case 5: // ItemList: ItemList Item
#line 90 "parser.y"
                          { yystack_[1].value.as < std::vector<std::unique_ptr<ast::Item>>* > ()->emplace_back(yystack_[0].value.as < ast::Item* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > () = yystack_[1].value.as < std::vector<std::unique_ptr<ast::Item>>* > (); }
#line 1239 "parser.cpp"
    break;

  case 6: // Item: FnDecl
#line 94 "parser.y"
                          { yylhs.value.as < ast::Item* > () = new ast::FnItem( std::unique_ptr<ast::Fn>(yystack_[0].value.as < ast::Fn* > ()) ); }
#line 1245 "parser.cpp"
    break;

  case 7: // Item: Stmt
#line 95 "parser.y"
                          { yylhs.value.as < ast::Item* > () = new ast::StmtItem( std::unique_ptr<ast::Stmt>(yystack_[0].value.as < ast::Stmt* > ()) ); }
#line 1251 "parser.cpp"
    break;

  case 8: // FnDecl: FN IDENT LPAREN ParamListOpt RPAREN RetTypeOpt Block
#line 101 "parser.y"
    {
      auto fn = std::make_unique<ast::Fn>();
      fn->name = std::move(yystack_[5].value.as < std::string > ());
      if (yystack_[3].value.as < std::vector<ast::Param>* > ()) { fn->params = std::move(*yystack_[3].value.as < std::vector<ast::Param>* > ()); delete yystack_[3].value.as < std::vector<ast::Param>* > (); }
      fn->retType = std::move(yystack_[1].value.as < std::string > ());                
      fn->body.reset( (ast::Block*)yystack_[0].value.as < ast::Stmt* > () );
      yylhs.value.as < ast::Fn* > () = fn.release();
    }
#line 1264 "parser.cpp"
    break;

  case 9: // RetTypeOpt: %empty
#line 112 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1270 "parser.cpp"
    break;

  case 10: // RetTypeOpt: ARROW Type
#line 113 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1276 "parser.cpp"
    break;

  case 11: // ParamListOpt: %empty
#line 117 "parser.y"
                           { yylhs.value.as < std::vector<ast::Param>* > () = nullptr; }
#line 1282 "parser.cpp"
    break;

  case 12: // ParamListOpt: Param1
#line 118 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1288 "parser.cpp"
    break;

  case 13: // ParamListOpt: Param2
#line 119 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1294 "parser.cpp"
    break;

  case 14: // ParamListOpt: Param3
#line 120 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1300 "parser.cpp"
    break;

  case 15: // ParamListOpt: Param4
#line 121 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1306 "parser.cpp"
    break;

  case 16: // ParamListOpt: Param5
#line 122 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1312 "parser.cpp"
    break;

  case 17: // Param1: Param
#line 126 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[0].value.as < ast::Param > () }; }
#line 1318 "parser.cpp"
    break;

  case 18: // Param2: Param COMMA Param
#line 130 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1324 "parser.cpp"
    break;

  case 19: // Param3: Param COMMA Param COMMA Param
#line 135 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1330 "parser.cpp"
    break;

  case 20: // Param4: Param COMMA Param COMMA Param COMMA Param
#line 140 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[6].value.as < ast::Param > (), yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1336 "parser.cpp"
    break;

  case 21: // Param5: Param COMMA Param COMMA Param COMMA Param COMMA Param
#line 145 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[8].value.as < ast::Param > (), yystack_[6].value.as < ast::Param > (), yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1342 "parser.cpp"
    break;

  case 22: // Param: IDENT COLON Type
#line 150 "parser.y"
    {
      yylhs.value.as < ast::Param > ().name = std::move(yystack_[2].value.as < std::string > ());
      yylhs.value.as < ast::Param > ().type   = std::move(yystack_[0].value.as < std::string > ());
    }
#line 1351 "parser.cpp"
    break;

  case 23: // Type: I32_T
#line 157 "parser.y"
                          { yylhs.value.as < std::string > () = "i32"; }
#line 1357 "parser.cpp"
    break;

  case 24: // Type: F64_T
#line 158 "parser.y"
                          { yylhs.value.as < std::string > () = "f64"; }
#line 1363 "parser.cpp"
    break;

  case 25: // Type: BOOL_T
#line 159 "parser.y"
                          { yylhs.value.as < std::string > () = "bool"; }
#line 1369 "parser.cpp"
    break;

  case 26: // Type: CHAR_T
#line 160 "parser.y"
                          { yylhs.value.as < std::string > () = "char"; }
#line 1375 "parser.cpp"
    break;

  case 27: // Type: STR_T
#line 161 "parser.y"
                          { yylhs.value.as < std::string > () = "str"; }
#line 1381 "parser.cpp"
    break;

  case 28: // Block: LBRACE StmtListOpt RBRACE
#line 167 "parser.y"
    {
      auto b = std::make_unique<ast::Block>();
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()) { b->stmts = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
      yylhs.value.as < ast::Stmt* > () = b.release();
    }
#line 1391 "parser.cpp"
    break;

  case 29: // StmtListOpt: %empty
#line 175 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = nullptr; }
#line 1397 "parser.cpp"
    break;

  case 30: // StmtListOpt: StmtList
#line 176 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
#line 1403 "parser.cpp"
    break;

  case 31: // StmtList: Stmt
#line 180 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = new std::vector<std::unique_ptr<ast::Stmt>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()->emplace_back(yystack_[0].value.as < ast::Stmt* > ()); }
#line 1409 "parser.cpp"
    break;

  case 32: // StmtList: StmtList Stmt
#line 181 "parser.y"
                          { yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()->emplace_back(yystack_[0].value.as < ast::Stmt* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
#line 1415 "parser.cpp"
    break;

  case 33: // Stmt: LetStmt
#line 186 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1421 "parser.cpp"
    break;

  case 34: // Stmt: ReturnStmt
#line 187 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1427 "parser.cpp"
    break;

  case 35: // Stmt: IfStmt
#line 188 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1433 "parser.cpp"
    break;

  case 36: // Stmt: WhileStmt
#line 189 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1439 "parser.cpp"
    break;

  case 37: // Stmt: ForStmt
#line 190 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1445 "parser.cpp"
    break;

  case 38: // Stmt: ExprStmt
#line 191 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1451 "parser.cpp"
    break;

  case 39: // Stmt: Block
#line 192 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1457 "parser.cpp"
    break;

  case 40: // LetStmt: LET IDENT TypeOpt InitOpt SEMICOLON
#line 197 "parser.y"
    {
      auto s = std::make_unique<ast::Let>();
      s->name = std::move(yystack_[3].value.as < std::string > ());
      s->type   = std::move(yystack_[2].value.as < std::string > ());
      s->init.reset( (ast::Expr*)yystack_[1].value.as < ast::Expr* > () );
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1469 "parser.cpp"
    break;

  case 41: // TypeOpt: %empty
#line 207 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1475 "parser.cpp"
    break;

  case 42: // TypeOpt: COLON Type
#line 208 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1481 "parser.cpp"
    break;

  case 43: // InitOpt: %empty
#line 212 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1487 "parser.cpp"
    break;

  case 44: // InitOpt: ASSIGN Expr
#line 213 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1493 "parser.cpp"
    break;

  case 45: // ReturnStmt: RETURN ExprOpt SEMICOLON
#line 218 "parser.y"
    {
      auto s = std::make_unique<ast::Return>();
      s->value.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1503 "parser.cpp"
    break;

  case 46: // ExprOpt: %empty
#line 226 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1509 "parser.cpp"
    break;

  case 47: // ExprOpt: Expr
#line 227 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1515 "parser.cpp"
    break;

  case 48: // IfStmt: IF Expr Block
#line 232 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1526 "parser.cpp"
    break;

  case 49: // IfStmt: IF Expr Block ELSE IfStmt
#line 239 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[3].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[2].value.as < ast::Stmt* > ());
      s->elseS.reset(yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1538 "parser.cpp"
    break;

  case 50: // IfStmt: IF Expr Block ELSE Block
#line 247 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[3].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[2].value.as < ast::Stmt* > ());
      s->elseS.reset(yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1550 "parser.cpp"
    break;

  case 51: // WhileStmt: WHILE Expr Block
#line 258 "parser.y"
    {
      auto s = std::make_unique<ast::While>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->body.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1561 "parser.cpp"
    break;

  case 52: // ForStmt: FOR LPAREN ForInitOpt SEMICOLON ForCondOpt SEMICOLON ForPostOpt RPAREN Block
#line 268 "parser.y"
    {
      auto s = std::make_unique<ast::For>();
      s->init.reset(yystack_[6].value.as < ast::Expr* > ());
      s->cond.reset(yystack_[4].value.as < ast::Expr* > ());
      s->post.reset(yystack_[2].value.as < ast::Expr* > ());
      s->body.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1574 "parser.cpp"
    break;

  case 53: // ForInitOpt: %empty
#line 279 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1580 "parser.cpp"
    break;

  case 54: // ForInitOpt: Expr
#line 280 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1586 "parser.cpp"
    break;

  case 55: // ForCondOpt: %empty
#line 283 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1592 "parser.cpp"
    break;

  case 56: // ForCondOpt: Expr
#line 284 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1598 "parser.cpp"
    break;

  case 57: // ForPostOpt: %empty
#line 287 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1604 "parser.cpp"
    break;

  case 58: // ForPostOpt: Expr
#line 288 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1610 "parser.cpp"
    break;

  case 59: // ExprStmt: Expr SEMICOLON
#line 293 "parser.y"
    {
      auto s = std::make_unique<ast::ExprStmt>();
      s->expr.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1620 "parser.cpp"
    break;

  case 60: // Expr: IDENT ASSIGN Expr
#line 302 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Assign, std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1626 "parser.cpp"
    break;

  case 61: // Expr: OrExpr
#line 303 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1632 "parser.cpp"
    break;

  case 62: // OrExpr: OrExpr OR AndExpr
#line 307 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Or,  std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1638 "parser.cpp"
    break;

  case 63: // OrExpr: AndExpr
#line 308 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1644 "parser.cpp"
    break;

  case 64: // AndExpr: AndExpr AND EqExpr
#line 312 "parser.y"
                         { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::And, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1650 "parser.cpp"
    break;

  case 65: // AndExpr: EqExpr
#line 313 "parser.y"
                         { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1656 "parser.cpp"
    break;

  case 66: // EqExpr: RelExpr
#line 317 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1662 "parser.cpp"
    break;

  case 67: // EqExpr: RelExpr EQ RelExpr
#line 318 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Eq, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1668 "parser.cpp"
    break;

  case 68: // EqExpr: RelExpr NE RelExpr
#line 319 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Ne, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1674 "parser.cpp"
    break;

  case 69: // RelExpr: AddExpr
#line 323 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1680 "parser.cpp"
    break;

  case 70: // RelExpr: AddExpr LT AddExpr
#line 324 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Lt, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1686 "parser.cpp"
    break;

  case 71: // RelExpr: AddExpr LE AddExpr
#line 325 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Le, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1692 "parser.cpp"
    break;

  case 72: // RelExpr: AddExpr GT AddExpr
#line 326 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Gt, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1698 "parser.cpp"
    break;

  case 73: // RelExpr: AddExpr GE AddExpr
#line 327 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Ge, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1704 "parser.cpp"
    break;

  case 74: // AddExpr: AddExpr PLUS MulExpr
#line 331 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Add, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1710 "parser.cpp"
    break;

  case 75: // AddExpr: AddExpr MINUS MulExpr
#line 332 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Sub, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1716 "parser.cpp"
    break;

  case 76: // AddExpr: MulExpr
#line 333 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1722 "parser.cpp"
    break;

  case 77: // MulExpr: MulExpr MULTIPLY Unary
#line 337 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Mul, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1728 "parser.cpp"
    break;

  case 78: // MulExpr: MulExpr DIVIDE Unary
#line 338 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Div, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1734 "parser.cpp"
    break;

  case 79: // MulExpr: Unary
#line 339 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1740 "parser.cpp"
    break;

  case 80: // Unary: NOT Unary
#line 343 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Not, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1746 "parser.cpp"
    break;

  case 81: // Unary: PLUS Unary
#line 344 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Positive, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1752 "parser.cpp"
    break;

  case 82: // Unary: MINUS Unary
#line 345 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Negative, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1758 "parser.cpp"
    break;

  case 83: // Unary: Postfix
#line 346 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1764 "parser.cpp"
    break;

  case 84: // Postfix: Primary
#line 350 "parser.y"
    { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1770 "parser.cpp"
    break;

  case 85: // Postfix: Postfix LPAREN ArgListOpt RPAREN
#line 352 "parser.y"
    {
      auto call = new ast::Call();
      call->callee.reset(yystack_[3].value.as < ast::Expr* > ());
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()) { call->args = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
      yylhs.value.as < ast::Expr* > () = call;
    }
#line 1781 "parser.cpp"
    break;

  case 86: // Postfix: Postfix QMARK
#line 359 "parser.y"
    {
      yylhs.value.as < ast::Expr* > () = new ast::Try( std::unique_ptr<ast::Expr>(yystack_[1].value.as < ast::Expr* > ()) );
    }
#line 1789 "parser.cpp"
    break;

  case 87: // Primary: IDENT
#line 365 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Ident(std::move(yystack_[0].value.as < std::string > ())); }
#line 1795 "parser.cpp"
    break;

  case 88: // Primary: INT_LIT
#line 366 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::IntLit(yystack_[0].value.as < long long > ()); }
#line 1801 "parser.cpp"
    break;

  case 89: // Primary: FLOAT_LIT
#line 367 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::FloatLit(yystack_[0].value.as < double > ()); }
#line 1807 "parser.cpp"
    break;

  case 90: // Primary: TRUE_LIT
#line 368 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(true); }
#line 1813 "parser.cpp"
    break;

  case 91: // Primary: FALSE_LIT
#line 369 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(false); }
#line 1819 "parser.cpp"
    break;

  case 92: // Primary: CHAR_LIT
#line 370 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::CharLit(yystack_[0].value.as < char > ()); }
#line 1825 "parser.cpp"
    break;

  case 93: // Primary: STR_LIT
#line 371 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::StringLit(std::move(yystack_[0].value.as < std::string > ())); }
#line 1831 "parser.cpp"
    break;

  case 94: // Primary: LPAREN Expr RPAREN
#line 372 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[1].value.as < ast::Expr* > (); }
#line 1837 "parser.cpp"
    break;

  case 95: // ArgListOpt: %empty
#line 377 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = nullptr; }
#line 1843 "parser.cpp"
    break;

  case 96: // ArgListOpt: ArgList
#line 378 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1849 "parser.cpp"
    break;

  case 97: // ArgList: Expr
#line 382 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = new std::vector<std::unique_ptr<ast::Expr>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); }
#line 1855 "parser.cpp"
    break;

  case 98: // ArgList: ArgList COMMA Expr
#line 383 "parser.y"
                          { yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1861 "parser.cpp"
    break;


#line 1865 "parser.cpp"

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

  const signed char
  parser::yypact_[] =
  {
      64,     2,     9,   103,   103,   -27,   103,    -5,  -112,  -112,
    -112,  -112,  -112,  -112,   118,   118,   118,    11,   103,    44,
      64,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,     5,    37,    39,  -112,   -11,    25,     6,  -112,   -25,
    -112,    22,    48,    51,    51,   103,    49,  -112,   103,  -112,
    -112,  -112,  -112,    54,    11,  -112,    62,  -112,  -112,  -112,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,  -112,   103,    85,    47,    90,   100,  -112,    65,
    -112,  -112,  -112,  -112,  -112,  -112,    39,  -112,  -112,  -112,
       6,     6,    27,    27,    27,    27,  -112,  -112,  -112,    68,
      67,  -112,  -112,  -112,  -112,  -112,  -112,   103,    69,    66,
      72,  -112,  -112,  -112,  -112,  -112,    71,     4,   103,  -112,
     103,  -112,  -112,    85,    80,    90,  -112,  -112,    73,  -112,
    -112,  -112,    85,    51,    84,   103,  -112,  -112,    90,    75,
    -112,    88,    51,    90,  -112,    89,    90,  -112
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,    46,    87,    93,    88,
      89,    92,    90,    91,     0,     0,     0,    29,     0,     0,
       3,     4,     6,    39,     7,    33,    34,    35,    36,    37,
      38,     0,    61,    63,    65,    66,    69,    76,    79,    83,
      84,    41,     0,     0,     0,    53,     0,    47,     0,    87,
      80,    81,    82,     0,    30,    31,     0,     1,     5,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    95,     0,    43,    11,    48,    51,     0,
      54,    45,    60,    28,    32,    94,    62,    64,    67,    68,
      74,    75,    70,    72,    71,    73,    77,    78,    97,     0,
      96,    23,    24,    25,    26,    27,    42,     0,     0,     0,
       0,    12,    13,    14,    15,    16,    17,     0,    55,    85,
       0,    44,    40,     0,     9,     0,    50,    49,     0,    56,
      98,    22,     0,     0,    18,    57,    10,     8,     0,     0,
      58,    19,     0,     0,    52,    20,     0,    21
  };

  const signed char
  parser::yypgoto_[] =
  {
    -112,  -112,  -112,   120,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -100,  -111,   -39,  -112,  -112,   -15,  -112,  -112,
    -112,  -112,  -112,    28,  -112,  -112,  -112,  -112,  -112,  -112,
      -3,  -112,    86,    87,    -4,     8,     0,    -8,  -112,  -112,
    -112,  -112
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    19,    20,    21,    22,   133,   110,   111,   112,   113,
     114,   115,   116,   106,    23,    53,    54,    24,    25,    75,
     108,    26,    46,    27,    28,    29,    79,   128,   139,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      99,   100
  };

  const unsigned char
  parser::yytable_[] =
  {
      43,    44,    55,    47,    77,    78,    50,    51,    52,     3,
      72,    45,   131,    73,     1,    56,     3,    41,     4,     5,
       6,   136,    62,    63,    42,   134,     7,     8,     9,    10,
      11,    12,    13,    70,    71,    14,    15,    16,   141,    84,
      17,    48,    80,   145,    57,    82,   147,    17,    59,    18,
      64,    65,    64,    65,    66,    67,    68,    69,    88,    89,
      60,    61,    96,    97,    90,    91,    74,     1,     2,     3,
      98,     4,     5,     6,    92,    93,    94,    95,   126,     7,
       8,     9,    10,    11,    12,    13,    76,    17,    14,    15,
      16,    83,    81,   107,   137,   101,   102,   103,   104,   105,
      17,    85,    18,   144,   121,   109,   117,   119,   118,   120,
     123,   124,   122,   125,   142,   129,   135,   130,     7,     8,
       9,    10,    11,    12,    13,   132,   138,    14,    15,    16,
     143,   146,   140,    49,     8,     9,    10,    11,    12,    13,
      58,    18,    14,    15,    16,   127,    86,     0,    87,     0,
       0,     0,     0,     0,     0,     0,    18
  };

  const short
  parser::yycheck_[] =
  {
       3,     4,    17,     6,    43,    44,    14,    15,    16,     5,
      35,    38,   123,    38,     3,    18,     5,    15,     7,     8,
       9,   132,    33,    34,    15,   125,    15,    16,    17,    18,
      19,    20,    21,    27,    28,    24,    25,    26,   138,    54,
      36,    46,    45,   143,     0,    48,   146,    36,    43,    38,
      25,    26,    25,    26,    29,    30,    31,    32,    62,    63,
      23,    22,    70,    71,    64,    65,    44,     3,     4,     5,
      73,     7,     8,     9,    66,    67,    68,    69,   117,    15,
      16,    17,    18,    19,    20,    21,    38,    36,    24,    25,
      26,    37,    43,    46,   133,    10,    11,    12,    13,    14,
      36,    39,    38,   142,   107,    15,     6,    39,    43,    42,
      44,    39,    43,    42,    39,   118,    43,   120,    15,    16,
      17,    18,    19,    20,    21,    45,    42,    24,    25,    26,
      42,    42,   135,    15,    16,    17,    18,    19,    20,    21,
      20,    38,    24,    25,    26,   117,    60,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     7,     8,     9,    15,    16,    17,
      18,    19,    20,    21,    24,    25,    26,    36,    38,    49,
      50,    51,    52,    62,    65,    66,    69,    71,    72,    73,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    15,    15,    78,    78,    38,    70,    78,    46,    15,
      85,    85,    85,    63,    64,    65,    78,     0,    51,    43,
      23,    22,    33,    34,    25,    26,    29,    30,    31,    32,
      27,    28,    35,    38,    44,    67,    38,    62,    62,    74,
      78,    43,    78,    37,    65,    39,    80,    81,    82,    82,
      84,    84,    83,    83,    83,    83,    85,    85,    78,    88,
      89,    10,    11,    12,    13,    14,    61,    46,    68,    15,
      54,    55,    56,    57,    58,    59,    60,     6,    43,    39,
      42,    78,    43,    44,    39,    42,    62,    71,    75,    78,
      78,    61,    45,    53,    60,    43,    61,    62,    42,    76,
      78,    60,    39,    42,    62,    60,    42,    60
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    48,    49,    49,    50,    50,    51,    51,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    55,    56,    57,
      58,    59,    60,    61,    61,    61,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      66,    67,    67,    68,    68,    69,    70,    70,    71,    71,
      71,    72,    73,    74,    74,    75,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    81,    82,
      82,    82,    82,    82,    83,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    89
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     1,     2,     1,     1,     7,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     3,     5,
       7,     9,     3,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       5,     0,     2,     0,     2,     3,     0,     1,     3,     5,
       5,     3,     9,     0,     1,     0,     1,     0,     1,     2,
       3,     1,     3,     1,     3,     1,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       2,     2,     2,     1,     1,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "LET", "FN", "IF",
  "ELSE", "WHILE", "FOR", "RETURN", "I32_T", "F64_T", "BOOL_T", "CHAR_T",
  "STR_T", "IDENT", "STR_LIT", "INT_LIT", "FLOAT_LIT", "CHAR_LIT",
  "TRUE_LIT", "FALSE_LIT", "AND", "OR", "NOT", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "LT", "GT", "LE", "GE", "EQ", "NE", "QMARK", "LBRACE",
  "RBRACE", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "COMMA", "SEMICOLON",
  "COLON", "ARROW", "ASSIGN", "IF_NO_ELSE", "$accept", "Program",
  "ItemList", "Item", "FnDecl", "RetTypeOpt", "ParamListOpt", "Param1",
  "Param2", "Param3", "Param4", "Param5", "Param", "Type", "Block",
  "StmtListOpt", "StmtList", "Stmt", "LetStmt", "TypeOpt", "InitOpt",
  "ReturnStmt", "ExprOpt", "IfStmt", "WhileStmt", "ForStmt", "ForInitOpt",
  "ForCondOpt", "ForPostOpt", "ExprStmt", "Expr", "OrExpr", "AndExpr",
  "EqExpr", "RelExpr", "AddExpr", "MulExpr", "Unary", "Postfix", "Primary",
  "ArgListOpt", "ArgList", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    84,    84,    85,    89,    90,    94,    95,   100,   112,
     113,   117,   118,   119,   120,   121,   122,   126,   130,   134,
     139,   144,   149,   157,   158,   159,   160,   161,   166,   175,
     176,   180,   181,   186,   187,   188,   189,   190,   191,   192,
     196,   207,   208,   212,   213,   217,   226,   227,   231,   238,
     246,   257,   267,   279,   280,   283,   284,   287,   288,   292,
     302,   303,   307,   308,   312,   313,   317,   318,   319,   323,
     324,   325,   326,   327,   331,   332,   333,   337,   338,   339,
     343,   344,   345,   346,   350,   351,   358,   365,   366,   367,
     368,   369,   370,   371,   372,   377,   378,   382,   383
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
#line 2286 "parser.cpp"

#line 386 "parser.y"

