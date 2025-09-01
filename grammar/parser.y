%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(const char* s);
int yylex(void);
%}

/* valores como int */
%define api.value.type {int}

/* tokens */
%token NUMBER

/* precedencias (izq.) */
%left '+' '-'
%left '*' '/'

%%
input
  : /* vacío */
  | input line
  ;

line
  : '\n'
  | expr '\n'        { printf("= %d\n", $1); }
  ;

expr
  : NUMBER
  | expr '+' expr    { $$ = $1 + $3; }
  | expr '-' expr    { $$ = $1 - $3; }
  | expr '*' expr    { $$ = $1 * $3; }
  | expr '/' expr    { $$ = $1 / $3; }
  | '(' expr ')'     { $$ = $2; }
  ;
%%

void yyerror(const char* s) { fprintf(stderr, "parse error: %s\n", s); }
int main(void) { return yyparse(); }
