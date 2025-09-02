%skeleton "lalr1.cc"
%define api.namespace {yy}
%define api.token.raw             
%define api.value.type {int}    

%code requires {
  int yylex(int* yylval);
}

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

%token TRUE_LIT FALSE_LIT
%token INT_LIT FLOAT_LIT STR_LIT CHAR_LIT

%token AND OR NOT
%token PLUS MINUS STAR SLASH

%token LBRACE RBRACE LPAREN RPAREN LBRACK RBRACK COMMA SEMICOLON
%token COLON ARROW ASSIGN

%token IDENT

/* ==== Precedencias ==== */
%right ASSIGN
%left  OR
%left  AND
%right NOT
%left  PLUS MINUS
%left  STAR SLASH

%nonassoc ELSE
%nonassoc IF_NO_ELSE

/* Punto de inicio */
%start Program

%%

/* ===== Programa y elementos ===== */

Program
  : /* vacío */ 
  | ItemList
  ;

ItemList
  : Item
  | ItemList Item
  ;

Item
  : FnDecl
  | Stmt
  ;

/* ===== Definición de funciones ===== */

FnDecl
  : FN IDENT LPAREN ParamListOpt RPAREN RetTypeOpt Block
  ;

RetTypeOpt
  : /* vacío */
  | ARROW Type
  ;

ParamListOpt
  : /* vacío */
  | Param1
  | Param2
  | Param3
  | Param4
  | Param5
  ;

Param1
  : Param
  ;

Param2
  : Param COMMA Param
  ;

Param3
  : Param COMMA Param COMMA Param
  ;

Param4
  : Param COMMA Param COMMA Param COMMA Param
  ;

Param5
  : Param COMMA Param COMMA Param COMMA Param COMMA Param
  ;

Param
  : IDENT COLON Type
  ;

Type
  : I32_T
  | F64_T
  | BOOL_T
  | CHAR_T
  | STR_T
  ;

/* ===== Bloques y lista de sentencias ===== */

Block
  : LBRACE StmtListOpt RBRACE
  ;

StmtListOpt
  : /* vacío */
  | StmtList
  ;

StmtList
  : Stmt
  | StmtList Stmt
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
  ;

TypeOpt
  : /* vacío */
  | COLON Type
  ;

InitOpt
  : /* vacío */
  | ASSIGN Expr
  ;

ReturnStmt
  : RETURN ExprOpt SEMICOLON
  ;

ExprOpt
  : /* vacío */
  | Expr
  ;

IfStmt
  : IF Expr Block %prec IF_NO_ELSE       
  | IF Expr Block ELSE IfStmt            
  | IF Expr Block ELSE Block
  ;

WhileStmt
  : WHILE Expr Block
  ;

ForStmt
  : FOR LPAREN ForInitOpt SEMICOLON ForCondOpt SEMICOLON ForPostOpt RPAREN Block
  ;

ForInitOpt
  : /* vacío */
  | Expr
  ;

ForCondOpt
  : /* vacío */
  | Expr
  ;

ForPostOpt
  : /* vacío */
  | Expr
  ;

ExprStmt
  : Expr SEMICOLON
  ;

/* ===== Expresiones ===== */
Expr
  : IDENT ASSIGN Expr
  | OrExpr
  ;

OrExpr
  : OrExpr OR AndExpr
  | AndExpr
  ;

AndExpr
  : AndExpr AND AddExpr
  | AddExpr
  ;

AddExpr
  : AddExpr PLUS MulExpr
  | AddExpr MINUS MulExpr
  | MulExpr
  ;

MulExpr
  : MulExpr STAR Unary
  | MulExpr SLASH Unary
  | Unary
  ;

Unary
  : NOT Unary
  | PLUS Unary
  | MINUS Unary
  | Postfix
  ;

Postfix
  : Primary
  | Postfix LPAREN ArgListOpt RPAREN
  ;

Primary
  : IDENT
  | Literal
  | LPAREN Expr RPAREN
  ;

ArgListOpt
  : /* vacío */
  | ArgList
  ;

ArgList
  : Expr
  | ArgList COMMA Expr
  ;

Literal
  : INT_LIT
  | FLOAT_LIT
  | TRUE_LIT
  | FALSE_LIT
  | CHAR_LIT
  | STR_LIT
  ;

%%
