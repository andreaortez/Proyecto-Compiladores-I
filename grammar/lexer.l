%option noyywrap
%option nounput noinput

%{
#include "parser.h"
#include <stdlib.h>
%}

%%

[ \t\r]+            ;              /* ignora espacios */
\n                  return '\n';   /* fin de línea */
[0-9]+              { yylval = atoi(yytext); return NUMBER; }

"("                 return '(';
")"                 return ')';
"+"|"-"|"*"|"/"     return yytext[0];

.                   ;              /* ignora cualquier otro char */

%%
