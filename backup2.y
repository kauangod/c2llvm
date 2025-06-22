%{

#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "utils.h"
#include "ht.h"
#include "calc.h"

int yylex();
int yywrap();
void yyerror(const char* str);
FILE *fptr;
ht* hashTable;
TempSymb tabelaTemp[100];
int lastTemp = 0;
char str_num[32];

%}

%union {
  char character;
  char* name;
  double doubleValue;
  int intValue;
}
%token <doubleValue> DOUBLE
%token <intValue> INT
%token <character> CHARACTER
%token PLUS
%token MINUS
%token DIVIDE
%token TIMES
%token LEFT
%token RIGHT
%token DONE
%token <name> ID
%token <name> STRING
%token EQUALS
%token AND
%token OR
%token GT
%token GE
%token LT
%token LE
%token l_EQUALS
%token DIF
%token NOT
%token B_LEFT
%token B_RIGHT
%token IF
%token ELSE
%token INTtype
%token FLOATtype
%token BOOLEANtype
%token CHARtype
%token writeCommand
%token readCommand

%type <doubleValue> expr term factor

%type <intValue> logical_operations logical_expr else_command
%%

program:
    declarations commands
;

declarations:
      %empty
    | declarations declaration
;

declaration:
      INTtype ID {fprintf(fptr, "int %s;\n", strdup($2)); declareVariableAtTable(hashTable, $2, Int);}
    | FLOATtype ID {fprintf(fptr, "float %s;\n", strdup($2)); declareVariableAtTable(hashTable, $2, Float);}
    | BOOLEANtype ID {fprintf(fptr, "bool %s;\n", strdup($2)); declareVariableAtTable(hashTable, $2, Bool);}
    | CHARtype ID {fprintf(fptr, "char %s;\n", strdup($2)); declareVariableAtTable(hashTable, $2, Char);}
;

commands:
      %empty
    | commands command
;

command:
      if_command
    | atrib
    | read_command
    | write_command
;

read_command:
    readCommand LEFT ID RIGHT {
        Symbol symb = getSymbolTableValue(hashTable, $3);
        if(symb.Type == Int) {
          int temp;
          scanf("%d", &temp);
          assignNumberValue(hashTable, $3, temp);
        }
        else if(symb.Type == Float) {
          float temp;
          scanf("%f", &temp);
          assignNumberValue(hashTable, $3, temp);
        }
        else if(symb.Type == Char) {
          char temp;
          scanf("%c", &temp);
          assignCharValue(hashTable, $3, temp);
        }
        else if(symb.Type == Bool) {
          int temp;
          scanf("%d", &temp);
          assignNumberValue(hashTable, $3, temp);
        }
    }
;

write_command:
    writeCommand LEFT write_value RIGHT
;

write_value:
      ID {
        Symbol symb = getSymbolTableValue(hashTable, $1);
        if(symb.Type == Int)
          printf("%s is an int and equals to %d\n", $1, symb.value.intValue);
        else if(symb.Type == Float)
          printf("%s is an float and equals to %f\n", $1, symb.value.doubleValue);
        else if(symb.Type == Char)
          printf("%s is an char and equals to %c\n", $1, symb.value.charValue);
        else if(symb.Type == Bool)
          printf("%s is an boolean and equals to %s\n", $1, symb.value.intValue ? "True":"False");
        free($1);
      }
    | INT {
      printf("%d", $1);
    }
    | DOUBLE {
      printf("%f",$1);
    }
    | STRING {
      printf("%s",$1);
      free($1);
    }
    | CHARACTER {
      printf("%c",$1);
    }
;

atrib:
      ID EQUALS expr {printTempSymbTableToFile(fptr, tabelaTemp, lastTemp);
      fprintf(fptr, "%s = %s;\n", strdup($1), tabelaTemp[lastTemp-1].result);
      lastTemp = 0;
}
    | ID EQUALS CHARACTER {assignCharValue(hashTable, $1, $3);}
;

if_command:
    IF LEFT logical_expr RIGHT B_LEFT commands B_RIGHT else_command
;

else_command:
      ELSE B_LEFT commands B_RIGHT {}
    | %empty {}
;

logical_expr:
    expr {$$ = $1;}
;

expr:
      expr PLUS term {$$ = lastTemp;
      tabelaTemp[lastTemp].op = '+';
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "t%d", lastTemp);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | expr MINUS term {$$ = lastTemp;
      tabelaTemp[lastTemp].op = '/';
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "t%d", lastTemp);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | term {$$ = $1;}
;

term:
      term TIMES factor {$$ = lastTemp;
      tabelaTemp[lastTemp].op = '*';
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "t%d", lastTemp);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | term DIVIDE factor {$$ = lastTemp;
      tabelaTemp[lastTemp].op = '/';
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "t%d", lastTemp);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | factor {$$ = $1;}
;

factor:
      DOUBLE {$$ = $1;}
    | INT {$$ = lastTemp;
      tabelaTemp[lastTemp].op = '=';
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "t%d", lastTemp);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
    | ID {
      $$ = lastTemp;
      tabelaTemp[lastTemp].op = 'V';
      tabelaTemp[lastTemp].arg1 = 0;
      tabelaTemp[lastTemp].arg2 = 0;
      strcpy(tabelaTemp[lastTemp].name, $1);
      sprintf(str_num, "t%d", lastTemp);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
        Symbol symb = getSymbolTableValue(hashTable, $1);
        if(symb.Type == Char)
          printf("deu merda filho\n");
        else if(symb.Type == Bool)
          printf("deu merda filho\n");
        free($1);
      }
    | LEFT expr RIGHT {$$ = $2;}
    | logical_operations {$$ = $1;}
;

logical_operations:
      expr AND expr {$$ = $1 && $3;}
    | expr OR expr  {$$ = $1 || $3;}
    | expr GT expr  {$$ = $1 > $3;}
    | expr GE expr  {$$ = $1 >= $3;}
    | expr LT expr  {$$ = $1 < $3;}
    | expr LE expr  {$$ = $1 <= $3;}
    | expr DIF expr {$$ = $1 != $3;}
    | expr l_EQUALS expr {$$ = $1 == $3;}
    | NOT expr {$$ = !$2;}
;   
%%

int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
  fprintf(stderr, "Compiler error: '%s'.\n", str);
}

extern int yylex_destroy(void);
extern FILE *yyin;

int main(int argc, char *argv[]) {
  if (argc != 2) {
      fprintf(stderr, "Usage: %s <input-file>\n", argv[0]);
      return 1;
  }
  yyin = fopen(argv[1], "r");
  if (yyin == NULL) {
      fprintf(stderr, "Error opening file `%s`\n", argv[1]);
      return 1;
  }


  // Open a file in writing mode
  fptr = fopen("saida.txt", "w");

  int c;
  while ((c = fgetc(yyin)) != EOF)
  {
      fputc(c, fptr);
  }
  fputc('\n', fptr);

  fclose(yyin);
  yyin = fopen(argv[1], "r");
  if (yyin == NULL) {
      fprintf(stderr, "Error opening file `%s`\n", argv[1]);
      return 1;
  }

  // Write some text to the file
  fprintf(fptr, "Starting file\n");

  hashTable = ht_create();
  yyparse();
  hti it = ht_iterator(hashTable);
  while (ht_next(&it)) {
    if (it.value) {
      free(it.value);
      it.value = NULL;
    }
  }
  ht_destroy(hashTable);
  yylex_destroy();
  fclose(stdin);
  fclose(fptr); 
  
  printTempSymbTable(tabelaTemp, lastTemp);
  return 0;
}
