%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
#include "calc.h"

%}

%option noyywrap

%%

"int"            {return INTtype;}
"float"          {return FLOATtype;}
"boolean"        {return BOOLEANtype;}
"char"           {return CHARtype;}
"printf"          {return writeCommand;}
"read"           {return readCommand;}
"return"         {return returnCommand;}
"+"              {return PLUS;}
"-"              {return MINUS;}
"/"              {return DIVIDE;}
"*"              {return TIMES;}
"("              {return LEFT;}
")"              {return RIGHT;}
">"              {return GT;}
"<"              {return LT;}
">="             {return GE;}
"<="             {return LE;}
"!="             {return DIF;}
"!"              {return NOT;}
"=="             {return l_EQUALS;}
"&&"             {return AND;}
"||"             {return OR;}
"if"             {return IF;}
"else"           {return ELSE;}
"while"          {return WHILE;}
"{"              {return B_LEFT;}
"}"              {return B_RIGHT;}
","              {return COMMA;}
"'\\n'"          {yylval.character = '\n'; return CHARACTER;}
"'"[\x0-\x7f]"'" {yylval.character = yytext[1]; return CHARACTER;}
\"[^"]*\"        {yylval.name = process_string(yytext); return STRING; }

[a-zA-Z_][a-zA-Z_0-9]{0,9} {yylval.name = strdup(yytext); return ID; }
"="		                     {return EQUALS;}
[-+]?[0-9]+                {yylval.intValue = atoi(yytext); return INT;}
[-+]?[0-9]+"."[0-9]+       {yylval.doubleValue = atof(yytext); return DOUBLE;}
[ \t]                      {}
"\n"                       {}
";"                        {return ';';}
.                          {printf("Error: invlaid lexeme '%s'.\n", yytext); return 0;}

%%



