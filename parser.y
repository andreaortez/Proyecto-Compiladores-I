%skeleton "lalr1.cc"
%define api.namespace {yy}
%define api.token.raw
%define api.value.type variant

%code requires {
  #include <memory>
  #include <string>
  #include <vector>
  #include "ast.hpp"
}

/* Hace visible yylex() para parser.cpp con la firma correcta */
%code provides {
  int yylex( yy::parser::semantic_type* yylval );
}

/* arbol sintáctico AST */
%parse-param { std::unique_ptr<ast::Program>& out }

%code {
  #include <cstdio>
  #include <string>
  namespace yy {
    void parser::error(const std::string& m) {
      std::fprintf(stderr, "[parse] %s\n", m.c_str());
    }
  }
}

%token LET FN IF ELSE WHILE FOR RETURN
%token I32_T F64_T BOOL_T CHAR_T STR_T

%token <std::string> IDENT STR_LIT
%token <long long>   INT_LIT
%token <double>      FLOAT_LIT
%token <char>        CHAR_LIT
%token TRUE_LIT FALSE_LIT

%token AND OR NOT
%token PLUS MINUS MULTIPLY DIVIDE

%token LT GT LE GE EQ NE
%token QMARK

%token LBRACE RBRACE LPAREN RPAREN LBRACK RBRACK COMMA SEMICOLON
%token COLON ARROW ASSIGN

%type <ast::Program*> Program
%type <ast::Item*>    Item
%type <std::vector<std::unique_ptr<ast::Item>>*> ItemList

%type <ast::Stmt*>    Stmt LetStmt ReturnStmt IfStmt WhileStmt ForStmt ExprStmt Block
%type <std::vector<std::unique_ptr<ast::Stmt>>*> StmtList StmtListOpt

%type <ast::Expr*>    Expr OrExpr AndExpr EqExpr RelExpr AddExpr MulExpr Unary Postfix Primary
%type <std::vector<std::unique_ptr<ast::Expr>>*> ArgList ArgListOpt

%type <std::vector<ast::Param>*> ParamListOpt Param1 Param2 Param3 Param4 Param5
%type <ast::Param>    Param
%type <std::string>   Type TypeOpt RetTypeOpt
%type <ast::Fn*>      FnDecl

%type <ast::Expr*> InitOpt ExprOpt
%type <ast::Expr*> ForInitOpt ForCondOpt ForPostOpt

/* ==== Precedencias ==== */
%left  MULTIPLY DIVIDE
%left  PLUS MINUS
%nonassoc LT LE GT GE        
%nonassoc EQ NE             
%left  AND
%left  OR
%right ASSIGN
%right NOT

%nonassoc ELSE
%nonassoc IF_NO_ELSE

%start Program

%%  /* ===== Reglas ===== */
Program
  : /* vacío */           { $$ = new ast::Program(); out.reset($$); }
  | ItemList              { auto p = new ast::Program(); p->items = std::move(*$1); delete $1; $$ = p; out.reset(p); }
  ;

ItemList
  : Item                  { $$ = new std::vector<std::unique_ptr<ast::Item>>{}; $$->emplace_back($1); }
  | ItemList Item         { $1->emplace_back($2); $$ = $1; }
  ;

Item
  : FnDecl                { $$ = new ast::FnItem( std::unique_ptr<ast::Fn>($1) ); }
  | Stmt                  { $$ = new ast::StmtItem( std::unique_ptr<ast::Stmt>($1) ); }
  ;

/* ===== Definición de función ===== */
FnDecl
  : FN IDENT LPAREN ParamListOpt RPAREN RetTypeOpt Block
    {
      auto fn = std::make_unique<ast::Fn>();
      fn->name = std::move($2);
      if ($4) { fn->params = std::move(*$4); delete $4; }
      fn->retType = std::move($6);                
      fn->body.reset( (ast::Block*)$7 );
      $$ = fn.release();
    }
  ;

RetTypeOpt
  : /* vacío */           { $$ = std::string{}; }
  | ARROW Type            { $$ = std::move($2); }
  ;

ParamListOpt
  : /* vacío */           { $$ = nullptr; }
  | Param1                { $$ = $1; }
  | Param2                { $$ = $1; }
  | Param3                { $$ = $1; }
  | Param4                { $$ = $1; }
  | Param5                { $$ = $1; } 
  ;

Param1
  : Param                 { $$ = new std::vector<ast::Param>{ $1 }; }
  ;

Param2
  : Param COMMA Param     { $$ = new std::vector<ast::Param>{ $1, $3 }; }
  ;

Param3
  : Param COMMA Param COMMA Param
                          { $$ = new std::vector<ast::Param>{ $1, $3, $5 }; }
  ;

Param4
  : Param COMMA Param COMMA Param COMMA Param
                          { $$ = new std::vector<ast::Param>{ $1, $3, $5, $7 }; }
  ;

  Param5
  : Param COMMA Param COMMA Param COMMA Param COMMA Param
                          { $$ = new std::vector<ast::Param>{ $1, $3, $5, $7, $9 }; }
  ;

Param
  : IDENT COLON Type
    {
      $$.name = std::move($1);
      $$.type   = std::move($3);
    }
  ;

Type
  : I32_T                 { $$ = "i32"; }
  | F64_T                 { $$ = "f64"; }
  | BOOL_T                { $$ = "bool"; }
  | CHAR_T                { $$ = "char"; }
  | STR_T                 { $$ = "str"; }
  ;

/* ===== Bloques y lista de sentencias ===== */
Block
  : LBRACE StmtListOpt RBRACE
    {
      auto b = std::make_unique<ast::Block>();
      if ($2) { b->stmts = std::move(*$2); delete $2; }
      $$ = b.release();
    }
  ;

StmtListOpt
  : /* vacío */           { $$ = nullptr; }
  | StmtList              { $$ = $1; }
  ;

StmtList
  : Stmt                  { $$ = new std::vector<std::unique_ptr<ast::Stmt>>{}; $$->emplace_back($1); }
  | StmtList Stmt         { $1->emplace_back($2); $$ = $1; }
  ;

/* ===== Sentencias ===== */
Stmt
  : LetStmt
  | ReturnStmt
  | IfStmt
  | WhileStmt
  | ForStmt
  | ExprStmt
  | Block
  ;

LetStmt
  : LET IDENT TypeOpt InitOpt SEMICOLON
    {
      auto s = std::make_unique<ast::Let>();
      s->name = std::move($2);
      s->type   = std::move($3);
      s->init.reset( (ast::Expr*)$4 );
      $$ = s.release();
    }
  ;

TypeOpt
  : /* vacío */           { $$ = std::string{}; }
  | COLON Type            { $$ = std::move($2); }
  ;

InitOpt
  : /* vacío */           { $$ = (ast::Expr*)nullptr; }
  | ASSIGN Expr           { $$ = $2; }
  ;

ReturnStmt
  : RETURN ExprOpt SEMICOLON
    {
      auto s = std::make_unique<ast::Return>();
      s->value.reset($2);
      $$ = s.release();
    }
  ;

ExprOpt
  : /* vacío */           { $$ = (ast::Expr*)nullptr; }
  | Expr                  { $$ = $1; }
  ;

IfStmt
  : IF Expr Block %prec IF_NO_ELSE
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset($2);
      s->thenB.reset((ast::Block*)$3);
      $$ = s.release();
    }
  | IF Expr Block ELSE IfStmt
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset($2);
      s->thenB.reset((ast::Block*)$3);
      s->elseS.reset($5);
      $$ = s.release();
    }
  | IF Expr Block ELSE Block
    {
      auto s = std::make_unique<ast::If>();
      s->cond.reset($2);
      s->thenB.reset((ast::Block*)$3);
      s->elseS.reset($5);
      $$ = s.release();
    }
  ;

WhileStmt
  : WHILE Expr Block
    {
      auto s = std::make_unique<ast::While>();
      s->cond.reset($2);
      s->body.reset((ast::Block*)$3);
      $$ = s.release();
    }
  ;

ForStmt
  : FOR LPAREN ForInitOpt SEMICOLON ForCondOpt SEMICOLON ForPostOpt RPAREN Block
    {
      auto s = std::make_unique<ast::For>();
      s->init.reset($3);
      s->cond.reset($5);
      s->post.reset($7);
      s->body.reset((ast::Block*)$9);
      $$ = s.release();
    }
  ;

ForInitOpt
  : /* vacío */           { $$ = (ast::Expr*)nullptr; }
  | Expr                  { $$ = $1; }
  ;
ForCondOpt
  : /* vacío */           { $$ = (ast::Expr*)nullptr; }
  | Expr                  { $$ = $1; }
  ;
ForPostOpt
  : /* vacío */           { $$ = (ast::Expr*)nullptr; }
  | Expr                  { $$ = $1; }
  ;

ExprStmt
  : Expr SEMICOLON
    {
      auto s = std::make_unique<ast::ExprStmt>();
      s->expr.reset($1);
      $$ = s.release();
    }
  ;

/* ===== Expresiones ===== */
Expr
  : IDENT ASSIGN Expr     { $$ = new ast::Binary(ast::BinOp::Assign, std::make_unique<ast::Ident>(std::move($1)), std::unique_ptr<ast::Expr>($3)); }
  | OrExpr                { $$ = $1; }
  ;

OrExpr
  : OrExpr OR AndExpr     { $$ = new ast::Binary(ast::BinOp::Or,  std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | AndExpr               { $$ = $1; }
  ;

AndExpr
  : AndExpr AND EqExpr   { $$ = new ast::Binary(ast::BinOp::And, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | EqExpr               { $$ = $1; }
  ;

EqExpr
  : RelExpr               { $$ = $1; }
  | RelExpr EQ RelExpr    { $$ = new ast::Binary(ast::BinOp::Eq, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | RelExpr NE RelExpr    { $$ = new ast::Binary(ast::BinOp::Ne, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  ;

RelExpr
  : AddExpr               { $$ = $1; }
  | AddExpr LT AddExpr    { $$ = new ast::Binary(ast::BinOp::Lt, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | AddExpr LE AddExpr    { $$ = new ast::Binary(ast::BinOp::Le, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | AddExpr GT AddExpr    { $$ = new ast::Binary(ast::BinOp::Gt, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | AddExpr GE AddExpr    { $$ = new ast::Binary(ast::BinOp::Ge, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  ;

AddExpr
  : AddExpr PLUS MulExpr  { $$ = new ast::Binary(ast::BinOp::Add, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | AddExpr MINUS MulExpr { $$ = new ast::Binary(ast::BinOp::Sub, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | MulExpr               { $$ = $1; }
  ;

MulExpr
  : MulExpr MULTIPLY Unary    { $$ = new ast::Binary(ast::BinOp::Mul, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | MulExpr DIVIDE Unary      { $$ = new ast::Binary(ast::BinOp::Div, std::unique_ptr<ast::Expr>($1), std::unique_ptr<ast::Expr>($3)); }
  | Unary                     { $$ = $1; }
  ;

Unary
  : NOT  Unary            { $$ = new ast::Unary(ast::UnOp::Not, std::unique_ptr<ast::Expr>($2)); }
  | PLUS Unary            { $$ = new ast::Unary(ast::UnOp::Positive, std::unique_ptr<ast::Expr>($2)); }
  | MINUS Unary           { $$ = new ast::Unary(ast::UnOp::Negative, std::unique_ptr<ast::Expr>($2)); }
  | Postfix               { $$ = $1; }
  ;

Postfix
  : Primary
  | Postfix LPAREN ArgListOpt RPAREN
    {
      auto call = new ast::Call();
      call->callee.reset($1);
      if ($3) { call->args = std::move(*$3); delete $3; }
      $$ = call;
    }
  | Postfix QMARK     
    {
      $$ = new ast::Try( std::unique_ptr<ast::Expr>($1) );
    }
  ;

Primary
  : IDENT                 { $$ = new ast::Ident(std::move($1)); }
  | INT_LIT               { $$ = new ast::IntLit($1); }
  | FLOAT_LIT             { $$ = new ast::FloatLit($1); }
  | TRUE_LIT              { $$ = new ast::BoolLit(true); }
  | FALSE_LIT             { $$ = new ast::BoolLit(false); }
  | CHAR_LIT              { $$ = new ast::CharLit($1); }
  | STR_LIT               { $$ = new ast::StringLit(std::move($1)); }
  | LPAREN Expr RPAREN    { $$ = $2; }
  ;

/* argumentos */
ArgListOpt
  : /* vacío */           { $$ = nullptr; }
  | ArgList               { $$ = $1; }
  ;

ArgList
  : Expr                  { $$ = new std::vector<std::unique_ptr<ast::Expr>>{}; $$->emplace_back($1); }
  | ArgList COMMA Expr    { $1->emplace_back($3); $$ = $1; }
  ;

%%  /* ===== Fin de reglas ===== */
