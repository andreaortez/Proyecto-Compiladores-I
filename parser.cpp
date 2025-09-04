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
#line 79 "parser.y"
                           { yylhs.value.as < ast::Program* > () = new ast::Program(); out.reset(yylhs.value.as < ast::Program* > ()); }
#line 1207 "parser.cpp"
    break;

  case 3: // Program: ItemList
#line 80 "parser.y"
                          { auto p = new ast::Program(); p->items = std::move(*yystack_[0].value.as < std::vector<std::unique_ptr<ast::Item>>* > ()); delete yystack_[0].value.as < std::vector<std::unique_ptr<ast::Item>>* > (); yylhs.value.as < ast::Program* > () = p; out.reset(p); }
#line 1213 "parser.cpp"
    break;

  case 4: // ItemList: Item
#line 84 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > () = new std::vector<std::unique_ptr<ast::Item>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > ()->emplace_back(yystack_[0].value.as < ast::Item* > ()); }
#line 1219 "parser.cpp"
    break;

  case 5: // ItemList: ItemList Item
#line 85 "parser.y"
                          { yystack_[1].value.as < std::vector<std::unique_ptr<ast::Item>>* > ()->emplace_back(yystack_[0].value.as < ast::Item* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Item>>* > () = yystack_[1].value.as < std::vector<std::unique_ptr<ast::Item>>* > (); }
#line 1225 "parser.cpp"
    break;

  case 6: // Item: FnDecl
#line 89 "parser.y"
                          { yylhs.value.as < ast::Item* > () = new ast::FnItem( std::unique_ptr<ast::Fn>(yystack_[0].value.as < ast::Fn* > ()) ); }
#line 1231 "parser.cpp"
    break;

  case 7: // Item: Stmt
#line 90 "parser.y"
                          { yylhs.value.as < ast::Item* > () = new ast::StmtItem( std::unique_ptr<ast::Stmt>(yystack_[0].value.as < ast::Stmt* > ()) ); }
#line 1237 "parser.cpp"
    break;

  case 8: // FnDecl: FN IDENT LPAREN ParamListOpt RPAREN RetTypeOpt Block
#line 96 "parser.y"
    {
      auto fn = std::make_unique<ast::Fn>();
      fn->name = std::move(yystack_[5].value.as < std::string > ());
      if (yystack_[3].value.as < std::vector<ast::Param>* > ()) { fn->params = std::move(*yystack_[3].value.as < std::vector<ast::Param>* > ()); delete yystack_[3].value.as < std::vector<ast::Param>* > (); }
      fn->retTy = std::move(yystack_[1].value.as < std::string > ());                
      fn->body.reset( (ast::Block*)yystack_[0].value.as < ast::Stmt* > () );
      yylhs.value.as < ast::Fn* > () = fn.release();
    }
#line 1250 "parser.cpp"
    break;

  case 9: // RetTypeOpt: %empty
#line 107 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1256 "parser.cpp"
    break;

  case 10: // RetTypeOpt: ARROW Type
#line 108 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1262 "parser.cpp"
    break;

  case 11: // ParamListOpt: %empty
#line 112 "parser.y"
                           { yylhs.value.as < std::vector<ast::Param>* > () = nullptr; }
#line 1268 "parser.cpp"
    break;

  case 12: // ParamListOpt: Param1
#line 113 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1274 "parser.cpp"
    break;

  case 13: // ParamListOpt: Param2
#line 114 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1280 "parser.cpp"
    break;

  case 14: // ParamListOpt: Param3
#line 115 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1286 "parser.cpp"
    break;

  case 15: // ParamListOpt: Param4
#line 116 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1292 "parser.cpp"
    break;

  case 16: // ParamListOpt: Param5
#line 117 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = yystack_[0].value.as < std::vector<ast::Param>* > (); }
#line 1298 "parser.cpp"
    break;

  case 17: // Param1: Param
#line 121 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[0].value.as < ast::Param > () }; }
#line 1304 "parser.cpp"
    break;

  case 18: // Param2: Param COMMA Param
#line 125 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1310 "parser.cpp"
    break;

  case 19: // Param3: Param COMMA Param COMMA Param
#line 130 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1316 "parser.cpp"
    break;

  case 20: // Param4: Param COMMA Param COMMA Param COMMA Param
#line 135 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[6].value.as < ast::Param > (), yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1322 "parser.cpp"
    break;

  case 21: // Param5: Param COMMA Param COMMA Param COMMA Param COMMA Param
#line 140 "parser.y"
                          { yylhs.value.as < std::vector<ast::Param>* > () = new std::vector<ast::Param>{ yystack_[8].value.as < ast::Param > (), yystack_[6].value.as < ast::Param > (), yystack_[4].value.as < ast::Param > (), yystack_[2].value.as < ast::Param > (), yystack_[0].value.as < ast::Param > () }; }
#line 1328 "parser.cpp"
    break;

  case 22: // Param: IDENT COLON Type
#line 145 "parser.y"
    {
      yylhs.value.as < ast::Param > ().name = std::move(yystack_[2].value.as < std::string > ());
      yylhs.value.as < ast::Param > ().ty   = std::move(yystack_[0].value.as < std::string > ());
    }
#line 1337 "parser.cpp"
    break;

  case 23: // Type: I32_T
#line 152 "parser.y"
                          { yylhs.value.as < std::string > () = "i32"; }
#line 1343 "parser.cpp"
    break;

  case 24: // Type: F64_T
#line 153 "parser.y"
                          { yylhs.value.as < std::string > () = "f64"; }
#line 1349 "parser.cpp"
    break;

  case 25: // Type: BOOL_T
#line 154 "parser.y"
                          { yylhs.value.as < std::string > () = "bool"; }
#line 1355 "parser.cpp"
    break;

  case 26: // Type: CHAR_T
#line 155 "parser.y"
                          { yylhs.value.as < std::string > () = "char"; }
#line 1361 "parser.cpp"
    break;

  case 27: // Type: STR_T
#line 156 "parser.y"
                          { yylhs.value.as < std::string > () = "str"; }
#line 1367 "parser.cpp"
    break;

  case 28: // Block: LBRACE StmtListOpt RBRACE
#line 162 "parser.y"
    {
      auto b = std::make_unique<ast::Block>();
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()) { b->stmts = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
      yylhs.value.as < ast::Stmt* > () = b.release();
    }
#line 1377 "parser.cpp"
    break;

  case 29: // StmtListOpt: %empty
#line 170 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = nullptr; }
#line 1383 "parser.cpp"
    break;

  case 30: // StmtListOpt: StmtList
#line 171 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
#line 1389 "parser.cpp"
    break;

  case 31: // StmtList: Stmt
#line 175 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = new std::vector<std::unique_ptr<ast::Stmt>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()->emplace_back(yystack_[0].value.as < ast::Stmt* > ()); }
#line 1395 "parser.cpp"
    break;

  case 32: // StmtList: StmtList Stmt
#line 176 "parser.y"
                          { yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > ()->emplace_back(yystack_[0].value.as < ast::Stmt* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Stmt>>* > () = yystack_[1].value.as < std::vector<std::unique_ptr<ast::Stmt>>* > (); }
#line 1401 "parser.cpp"
    break;

  case 33: // Stmt: LetStmt
#line 181 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1407 "parser.cpp"
    break;

  case 34: // Stmt: ReturnStmt
#line 182 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1413 "parser.cpp"
    break;

  case 35: // Stmt: IfStmt
#line 183 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1419 "parser.cpp"
    break;

  case 36: // Stmt: WhileStmt
#line 184 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1425 "parser.cpp"
    break;

  case 37: // Stmt: ForStmt
#line 185 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1431 "parser.cpp"
    break;

  case 38: // Stmt: ExprStmt
#line 186 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1437 "parser.cpp"
    break;

  case 39: // Stmt: Block
#line 187 "parser.y"
    { yylhs.value.as < ast::Stmt* > () = yystack_[0].value.as < ast::Stmt* > (); }
#line 1443 "parser.cpp"
    break;

  case 40: // LetStmt: LET IDENT TypeOpt InitOpt SEMICOLON
#line 192 "parser.y"
    {
      auto s = std::make_unique<ast::Let>();
      s->name = std::move(yystack_[3].value.as < std::string > ());
      s->ty   = std::move(yystack_[2].value.as < std::string > ());
      s->init.reset( (ast::Expr*)yystack_[1].value.as < ast::Expr* > () );
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1455 "parser.cpp"
    break;

  case 41: // TypeOpt: %empty
#line 202 "parser.y"
                           { yylhs.value.as < std::string > () = std::string{}; }
#line 1461 "parser.cpp"
    break;

  case 42: // TypeOpt: COLON Type
#line 203 "parser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 1467 "parser.cpp"
    break;

  case 43: // InitOpt: %empty
#line 207 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1473 "parser.cpp"
    break;

  case 44: // InitOpt: ASSIGN Expr
#line 208 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1479 "parser.cpp"
    break;

  case 45: // ReturnStmt: RETURN ExprOpt SEMICOLON
#line 213 "parser.y"
    {
      auto s = std::make_unique<ast::Return>();
      s->value.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1489 "parser.cpp"
    break;

  case 46: // ExprOpt: %empty
#line 221 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1495 "parser.cpp"
    break;

  case 47: // ExprOpt: Expr
#line 222 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1501 "parser.cpp"
    break;

  case 48: // IfStmt: IF Expr Block
#line 227 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1512 "parser.cpp"
    break;

  case 49: // IfStmt: IF Expr Block ELSE IfStmt
#line 234 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[3].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[2].value.as < ast::Stmt* > ());
      s->elseS.reset(yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1524 "parser.cpp"
    break;

  case 50: // IfStmt: IF Expr Block ELSE Block
#line 242 "parser.y"
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset(yystack_[3].value.as < ast::Expr* > ());
      s->thenB.reset((ast::Block*)yystack_[2].value.as < ast::Stmt* > ());
      s->elseS.reset(yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1536 "parser.cpp"
    break;

  case 51: // WhileStmt: WHILE Expr Block
#line 253 "parser.y"
    {
      auto s = std::make_unique<ast::While>();
      s->cond.reset(yystack_[1].value.as < ast::Expr* > ());
      s->body.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1547 "parser.cpp"
    break;

  case 52: // ForStmt: FOR LPAREN ForInitOpt SEMICOLON ForCondOpt SEMICOLON ForPostOpt RPAREN Block
#line 263 "parser.y"
    {
      auto s = std::make_unique<ast::For>();
      s->init.reset(yystack_[6].value.as < ast::Expr* > ());
      s->cond.reset(yystack_[4].value.as < ast::Expr* > ());
      s->post.reset(yystack_[2].value.as < ast::Expr* > ());
      s->body.reset((ast::Block*)yystack_[0].value.as < ast::Stmt* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1560 "parser.cpp"
    break;

  case 53: // ForInitOpt: %empty
#line 274 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1566 "parser.cpp"
    break;

  case 54: // ForInitOpt: Expr
#line 275 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1572 "parser.cpp"
    break;

  case 55: // ForCondOpt: %empty
#line 278 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1578 "parser.cpp"
    break;

  case 56: // ForCondOpt: Expr
#line 279 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1584 "parser.cpp"
    break;

  case 57: // ForPostOpt: %empty
#line 282 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = (ast::Expr*)nullptr; }
#line 1590 "parser.cpp"
    break;

  case 58: // ForPostOpt: Expr
#line 283 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1596 "parser.cpp"
    break;

  case 59: // ExprStmt: Expr SEMICOLON
#line 288 "parser.y"
    {
      auto s = std::make_unique<ast::ExprStmt>();
      s->expr.reset(yystack_[1].value.as < ast::Expr* > ());
      yylhs.value.as < ast::Stmt* > () = s.release();
    }
#line 1606 "parser.cpp"
    break;

  case 60: // Expr: IDENT ASSIGN Expr
#line 297 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Assign, std::make_unique<ast::Ident>(std::move(yystack_[2].value.as < std::string > ())), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1612 "parser.cpp"
    break;

  case 61: // Expr: OrExpr
#line 298 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1618 "parser.cpp"
    break;

  case 62: // OrExpr: OrExpr OR AndExpr
#line 302 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Or,  std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1624 "parser.cpp"
    break;

  case 63: // OrExpr: AndExpr
#line 303 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1630 "parser.cpp"
    break;

  case 64: // AndExpr: AndExpr AND AddExpr
#line 307 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::And, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1636 "parser.cpp"
    break;

  case 65: // AndExpr: AddExpr
#line 308 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1642 "parser.cpp"
    break;

  case 66: // AddExpr: AddExpr PLUS MulExpr
#line 312 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Add, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1648 "parser.cpp"
    break;

  case 67: // AddExpr: AddExpr MINUS MulExpr
#line 313 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Sub, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1654 "parser.cpp"
    break;

  case 68: // AddExpr: MulExpr
#line 314 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1660 "parser.cpp"
    break;

  case 69: // MulExpr: MulExpr MULTIPLY Unary
#line 318 "parser.y"
                              { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Mul, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1666 "parser.cpp"
    break;

  case 70: // MulExpr: MulExpr DIVIDE Unary
#line 319 "parser.y"
                           { yylhs.value.as < ast::Expr* > () = new ast::Binary(ast::BinOp::Div, std::unique_ptr<ast::Expr>(yystack_[2].value.as < ast::Expr* > ()), std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1672 "parser.cpp"
    break;

  case 71: // MulExpr: Unary
#line 320 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1678 "parser.cpp"
    break;

  case 72: // Unary: NOT Unary
#line 324 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Not, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1684 "parser.cpp"
    break;

  case 73: // Unary: PLUS Unary
#line 325 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Pos, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1690 "parser.cpp"
    break;

  case 74: // Unary: MINUS Unary
#line 326 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Unary(ast::UnOp::Neg, std::unique_ptr<ast::Expr>(yystack_[0].value.as < ast::Expr* > ())); }
#line 1696 "parser.cpp"
    break;

  case 75: // Unary: Postfix
#line 327 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1702 "parser.cpp"
    break;

  case 76: // Postfix: Primary
#line 331 "parser.y"
    { yylhs.value.as < ast::Expr* > () = yystack_[0].value.as < ast::Expr* > (); }
#line 1708 "parser.cpp"
    break;

  case 77: // Postfix: Postfix LPAREN ArgListOpt RPAREN
#line 333 "parser.y"
    {
      auto call = new ast::Call();
      call->callee.reset(yystack_[3].value.as < ast::Expr* > ());
      if (yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()) { call->args = std::move(*yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()); delete yystack_[1].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
      yylhs.value.as < ast::Expr* > () = call;
    }
#line 1719 "parser.cpp"
    break;

  case 78: // Primary: IDENT
#line 342 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::Ident(std::move(yystack_[0].value.as < std::string > ())); }
#line 1725 "parser.cpp"
    break;

  case 79: // Primary: INT_LIT
#line 343 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::IntLit(yystack_[0].value.as < long long > ()); }
#line 1731 "parser.cpp"
    break;

  case 80: // Primary: FLOAT_LIT
#line 344 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::FloatLit(yystack_[0].value.as < double > ()); }
#line 1737 "parser.cpp"
    break;

  case 81: // Primary: TRUE_LIT
#line 345 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(true); }
#line 1743 "parser.cpp"
    break;

  case 82: // Primary: FALSE_LIT
#line 346 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::BoolLit(false); }
#line 1749 "parser.cpp"
    break;

  case 83: // Primary: CHAR_LIT
#line 347 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::CharLit(yystack_[0].value.as < char > ()); }
#line 1755 "parser.cpp"
    break;

  case 84: // Primary: STR_LIT
#line 348 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = new ast::StringLit(std::move(yystack_[0].value.as < std::string > ())); }
#line 1761 "parser.cpp"
    break;

  case 85: // Primary: LPAREN Expr RPAREN
#line 349 "parser.y"
                          { yylhs.value.as < ast::Expr* > () = yystack_[1].value.as < ast::Expr* > (); }
#line 1767 "parser.cpp"
    break;

  case 86: // ArgListOpt: %empty
#line 354 "parser.y"
                           { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = nullptr; }
#line 1773 "parser.cpp"
    break;

  case 87: // ArgListOpt: ArgList
#line 355 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[0].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1779 "parser.cpp"
    break;

  case 88: // ArgList: Expr
#line 359 "parser.y"
                          { yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = new std::vector<std::unique_ptr<ast::Expr>>{}; yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); }
#line 1785 "parser.cpp"
    break;

  case 89: // ArgList: ArgList COMMA Expr
#line 360 "parser.y"
                          { yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > ()->emplace_back(yystack_[0].value.as < ast::Expr* > ()); yylhs.value.as < std::vector<std::unique_ptr<ast::Expr>>* > () = yystack_[2].value.as < std::vector<std::unique_ptr<ast::Expr>>* > (); }
#line 1791 "parser.cpp"
    break;


#line 1795 "parser.cpp"

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









  const signed char parser::yypact_ninf_ = -101;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      67,     9,    15,     1,     1,     5,     1,     0,  -101,  -101,
    -101,  -101,  -101,  -101,    32,    32,    32,   103,     1,    41,
      67,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,     6,    21,    23,   -14,     7,  -101,    28,  -101,    25,
      29,    17,    17,     1,    30,  -101,     1,  -101,  -101,  -101,
    -101,    34,   103,  -101,    35,  -101,  -101,  -101,    32,    32,
      32,    32,    32,    32,     1,   125,    38,    53,    63,  -101,
      37,  -101,  -101,  -101,  -101,  -101,  -101,    23,   -14,     7,
       7,  -101,  -101,  -101,    46,    44,  -101,  -101,  -101,  -101,
    -101,  -101,     1,    58,    43,    65,  -101,  -101,  -101,  -101,
    -101,    60,     4,     1,  -101,     1,  -101,  -101,   125,    61,
      53,  -101,  -101,    68,  -101,  -101,  -101,   125,    17,    66,
       1,  -101,  -101,    53,    71,  -101,    70,    17,    53,  -101,
      72,    53,  -101
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,    46,    78,    84,    79,
      80,    83,    81,    82,     0,     0,     0,    29,     0,     0,
       3,     4,     6,    39,     7,    33,    34,    35,    36,    37,
      38,     0,    61,    63,    65,    68,    71,    75,    76,    41,
       0,     0,     0,    53,     0,    47,     0,    78,    72,    73,
      74,     0,    30,    31,     0,     1,     5,    59,     0,     0,
       0,     0,     0,     0,    86,     0,    43,    11,    48,    51,
       0,    54,    45,    60,    28,    32,    85,    62,    64,    66,
      67,    69,    70,    88,     0,    87,    23,    24,    25,    26,
      27,    42,     0,     0,     0,     0,    12,    13,    14,    15,
      16,    17,     0,    55,    77,     0,    44,    40,     0,     9,
       0,    50,    49,     0,    56,    89,    22,     0,     0,    18,
      57,    10,     8,     0,     0,    58,    19,     0,     0,    52,
      20,     0,    21
  };

  const signed char
  parser::yypgoto_[] =
  {
    -101,  -101,  -101,    89,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,  -100,   -79,   -37,  -101,  -101,   -15,  -101,  -101,
    -101,  -101,  -101,    11,  -101,  -101,  -101,  -101,  -101,  -101,
      -3,  -101,    56,    57,   -47,    -8,  -101,  -101,  -101,  -101
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    19,    20,    21,    22,   118,    95,    96,    97,    98,
      99,   100,   101,    91,    23,    51,    52,    24,    25,    66,
      93,    26,    44,    27,    28,    29,    70,   113,   124,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    84,    85
  };

  const unsigned char
  parser::yytable_[] =
  {
      41,    42,    53,    45,    68,    69,    48,    49,    50,     3,
     119,    60,    61,    79,    80,    54,     7,     8,     9,    10,
      11,    12,    13,   126,    39,    14,    15,    16,   130,   116,
      40,   132,    18,    17,    62,    63,    43,    75,   121,    46,
      71,    55,    57,    73,    58,    59,    17,    47,     8,     9,
      10,    11,    12,    13,    81,    82,    14,    15,    16,    64,
      67,    83,    65,    18,    74,   111,    72,    76,    94,   102,
       1,     2,     3,   103,     4,     5,     6,    92,   104,   105,
     108,   122,     7,     8,     9,    10,    11,    12,    13,   106,
     129,    14,    15,    16,   107,   110,    17,   109,    18,   117,
     114,   123,   115,   127,   120,   128,     1,   131,     3,    56,
       4,     5,     6,   112,    77,     0,    78,   125,     7,     8,
       9,    10,    11,    12,    13,     0,     0,    14,    15,    16,
       0,     0,    17,     0,    18,    86,    87,    88,    89,    90
  };

  const short
  parser::yycheck_[] =
  {
       3,     4,    17,     6,    41,    42,    14,    15,    16,     5,
     110,    25,    26,    60,    61,    18,    15,    16,    17,    18,
      19,    20,    21,   123,    15,    24,    25,    26,   128,   108,
      15,   131,    31,    29,    27,    28,    31,    52,   117,    39,
      43,     0,    36,    46,    23,    22,    29,    15,    16,    17,
      18,    19,    20,    21,    62,    63,    24,    25,    26,    31,
      31,    64,    37,    31,    30,   102,    36,    32,    15,     6,
       3,     4,     5,    36,     7,     8,     9,    39,    32,    35,
      37,   118,    15,    16,    17,    18,    19,    20,    21,    92,
     127,    24,    25,    26,    36,    35,    29,    32,    31,    38,
     103,    35,   105,    32,    36,    35,     3,    35,     5,    20,
       7,     8,     9,   102,    58,    -1,    59,   120,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    26,
      -1,    -1,    29,    -1,    31,    10,    11,    12,    13,    14
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     7,     8,     9,    15,    16,    17,
      18,    19,    20,    21,    24,    25,    26,    29,    31,    42,
      43,    44,    45,    55,    58,    59,    62,    64,    65,    66,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    15,
      15,    71,    71,    31,    63,    71,    39,    15,    76,    76,
      76,    56,    57,    58,    71,     0,    44,    36,    23,    22,
      25,    26,    27,    28,    31,    37,    60,    31,    55,    55,
      67,    71,    36,    71,    30,    58,    32,    73,    74,    75,
      75,    76,    76,    71,    79,    80,    10,    11,    12,    13,
      14,    54,    39,    61,    15,    47,    48,    49,    50,    51,
      52,    53,     6,    36,    32,    35,    71,    36,    37,    32,
      35,    55,    64,    68,    71,    71,    54,    38,    46,    53,
      36,    54,    55,    35,    69,    71,    53,    32,    35,    55,
      53,    35,    53
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    42,    43,    43,    44,    44,    45,    46,
      46,    47,    47,    47,    47,    47,    47,    48,    49,    50,
      51,    52,    53,    54,    54,    54,    54,    54,    55,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    60,    61,    61,    62,    63,    63,    64,    64,
      64,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80
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
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     2,     2,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     3
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
  "DIVIDE", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "COMMA", "SEMICOLON", "COLON", "ARROW", "ASSIGN", "IF_NO_ELSE",
  "$accept", "Program", "ItemList", "Item", "FnDecl", "RetTypeOpt",
  "ParamListOpt", "Param1", "Param2", "Param3", "Param4", "Param5",
  "Param", "Type", "Block", "StmtListOpt", "StmtList", "Stmt", "LetStmt",
  "TypeOpt", "InitOpt", "ReturnStmt", "ExprOpt", "IfStmt", "WhileStmt",
  "ForStmt", "ForInitOpt", "ForCondOpt", "ForPostOpt", "ExprStmt", "Expr",
  "OrExpr", "AndExpr", "AddExpr", "MulExpr", "Unary", "Postfix", "Primary",
  "ArgListOpt", "ArgList", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    79,    79,    80,    84,    85,    89,    90,    95,   107,
     108,   112,   113,   114,   115,   116,   117,   121,   125,   129,
     134,   139,   144,   152,   153,   154,   155,   156,   161,   170,
     171,   175,   176,   181,   182,   183,   184,   185,   186,   187,
     191,   202,   203,   207,   208,   212,   221,   222,   226,   233,
     241,   252,   262,   274,   275,   278,   279,   282,   283,   287,
     297,   298,   302,   303,   307,   308,   312,   313,   314,   318,
     319,   320,   324,   325,   326,   327,   331,   332,   342,   343,
     344,   345,   346,   347,   348,   349,   354,   355,   359,   360
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
#line 2203 "parser.cpp"

#line 363 "parser.y"
  /* ===== Fin de reglas ===== */
