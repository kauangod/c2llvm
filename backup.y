%{

#include <stdio.h>
#include <string.h>

int yylex();
int yywrap( );
void yyerror(const char* str);

/* the result variable */
double result = 0;
double symb[26];

%}

/* declare type possibilities of symbols */
%union {
  double value;
  int valueInt;
}

/* declare tokens (default is typeless) */
%token <value> VAL
%token PLUS
%token MINUS
%token DIVIDE
%token TIMES
%token LEFT
%token RIGHT
%token DONE
%token <valueInt> VARIABLE
%token EQUALS

/* declare non-terminals */
%type <value> stmt expr term factor

/* give us more detailed errors */
%define parse.error verbose

%%

/* one expression only followed by a new line */
progexec: stmt
    |  stmt progexec

stmt: atrib DONE {}
    | expr DONE {printf("value: %f\n", (double)$1);}

/* variable value */
atrib: VARIABLE EQUALS expr { symb[$1] = $3;printf("register '%c' received value: %f\n", (char)($1 + 97), $3);}

/* an expression uses + or - or neither */
expr: expr term PLUS   {$$ = $1 + $2;}
    | expr term MINUS  {$$ = $1 - $2;}
    | expr term DIVIDE {$$ = $1 / $2;}
    | expr term TIMES  {$$ = $1 * $2;}
    | term {$$ = $1;}

/* an expression uses * or / or neither */
term: factor {$$ = $1;}

factor: VAL {$$ = $1;}
      | VARIABLE { $$ = symb[$1];}
%%

int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
  fprintf(stderr, "Compiler error: '%s'.\n", str);
}

int main( ) {
  yyparse( );
  printf("The answer is %lf\n", result);
  return 0;
}


