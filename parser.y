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
int tempCounter = 0;
char str_num[32];
int lastLabel = 0;
struct Pile *labelStack;
int indentation = 1;

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
%token WHILE
%token INTtype
%token FLOATtype
%token BOOLEANtype
%token CHARtype
%token writeCommand
%token readCommand
%token returnCommand

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
      INTtype ID {
      fprintf(fptr, "\t");
      char* temp = strdup($2);
      declareVariableAtTable(hashTable, $2, Int);
      fprintf(fptr, "%%var%d = alloca i32, align 4\n", getSymbolTableValue(hashTable, temp).index, temp);
      free(temp);
      }
    | FLOATtype ID {
      fprintf(fptr, "\t");
      char* temp = strdup($2);
      declareVariableAtTable(hashTable, $2, Float);
      fprintf(fptr, "%%var%d = alloca float, align 4\n", getSymbolTableValue(hashTable, temp).index, temp);
      free(temp);
      }
    | BOOLEANtype ID {fprintf(fptr, "bool %s;\n", strdup($2)); declareVariableAtTable(hashTable, $2, Bool);}
    | CHARtype ID {
      fprintf(fptr, "\t");
      char* temp = strdup($2);
      declareVariableAtTable(hashTable, $2, Char);
      fprintf(fptr, "%%var%d = alloca i8, align 1\n", getSymbolTableValue(hashTable, temp).index, temp);
      free(temp);
      }
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
    | return_command
    | while_command
;

while_command:
    WHILE LEFT logical_expr RIGHT {
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br label %%Label%d\n\n", lastLabel);
      fprintf(fptr, "Label%d:\n", lastLabel);
      pilePush(labelStack, lastLabel++);
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, Int);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br i1 %%%d, label %%Label%d, label %%Label%d\n", lastTemp-1 + tempCounter, lastLabel+1, lastLabel);
      tempCounter += lastTemp;
      lastTemp = 0;
      pilePush(labelStack, lastLabel);
      lastLabel++;
      fprintf(fptr, "Label%d:\n", lastLabel++);
      indentation++;
      } B_LEFT commands {// printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation);
      tempCounter += lastTemp;
      lastTemp = 0;
      indentation--;
      } B_RIGHT {
      int temp = (int) popPile(labelStack);
      fprintf(fptr, "br label %%Label%d\n\n", (int) popPile(labelStack));
      fprintf(fptr, "Label%d:\n", temp);
      }

return_command:
    returnCommand expr {
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, Int);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "ret i32 %s\n", tabelaTemp[lastTemp-1].result);
      tempCounter += lastTemp;
      lastTemp = 0;
}

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
      ID EQUALS expr {
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, getSymbolTableValue(hashTable, $1).Type);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");

      switch (getSymbolTableValue(hashTable, $1).Type) {
      case Float:
        fprintf(fptr, "store float %s, ptr %%var%d, align 4;\n", tabelaTemp[lastTemp-1].result, getSymbolTableValue(hashTable, $1).index);
        break;
      case Int:
        fprintf(fptr, "store i32 %s, ptr %%var%d, align 4;\n", tabelaTemp[lastTemp-1].result, getSymbolTableValue(hashTable, $1).index);
        break;
      case Char:
        fprintf(fptr, "store i8 %s, ptr %%var%d, align 1;\n", tabelaTemp[lastTemp-1].result, getSymbolTableValue(hashTable, $1).index);
      default:
        break;
      }
      tempCounter += lastTemp;
      lastTemp = 0;
    }
    | ID EQUALS CHARACTER {assignCharValue(hashTable, $1, $3);}
;

if_command:
    IF LEFT logical_expr RIGHT {
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, Int);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br i1 %%%d, label %%Label%d, label %%Label%d\n", lastTemp-1 + tempCounter, lastLabel+1, lastLabel);
      tempCounter += lastTemp;
      lastTemp = 0;
      pilePush(labelStack, lastLabel);
      lastLabel++;
      fprintf(fptr, "Label%d:\n", lastLabel++);
      indentation++;
      } B_LEFT commands {// printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation);
      tempCounter += lastTemp;
      lastTemp = 0;
      indentation--;
      } B_RIGHT  else_command
;

else_command:
      ELSE {
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "br label %%Label%d\n\n", lastLabel);
      fprintf(fptr, "Label%d:\n", (int) popPile(labelStack));
      indentation++;
      } B_LEFT commands B_RIGHT {
      indentation--;
      fprintf(fptr, "br label %%Label%d\n\n", lastLabel);
      fprintf(fptr, "Label%d:\n", lastLabel);
      lastLabel++;
      }
    | %empty {
    fprintf(fptr, "Label%d:\n", (int) popPile(labelStack));
    }
;

logical_expr:
    logical_operations {$$ = $1;}
;

expr:
      expr PLUS term {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_PLUS;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | expr MINUS term {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_DIV;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | term {$$ = $1;}
;

term:
      term TIMES factor {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_MULT;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | term DIVIDE factor {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_DIV;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | factor {$$ = $1;}
;

factor:
      DOUBLE {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_EQUAL;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
    | INT {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_EQUAL;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
    | ID {
      $$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_VAR;
      tabelaTemp[lastTemp].arg1 = 0;
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%var%d", getSymbolTableValue(hashTable, $1).index);
      strcpy(tabelaTemp[lastTemp].name, str_num);
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
        Symbol symb = getSymbolTableValue(hashTable, $1);
        if(symb.Type == Char)
          printf("deu merda filho\n");
        free($1);
      }
    | LEFT expr RIGHT {$$ = $2;}
;

logical_operations:
      logical_operations AND logical_operations {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_AND;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | logical_operations OR logical_operations {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_OR;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | logical_operations GT expr {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_GT;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | logical_operations GE expr  {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_GE;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | logical_operations LT expr {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_LT;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | logical_operations LE expr  {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_LE;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | logical_operations DIF expr {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_DIF;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | logical_operations l_EQUALS expr {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_L_EQUAL;
      tabelaTemp[lastTemp].arg1 = $1;
      tabelaTemp[lastTemp].arg2 = $3;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
      }
    | NOT logical_operations {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_NOT;
      tabelaTemp[lastTemp].arg1 = $2;
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
    | NOT LEFT logical_operations RIGHT {$$ = lastTemp;
      tabelaTemp[lastTemp].op = OP_NOT;
      tabelaTemp[lastTemp].arg1 = $3;
      tabelaTemp[lastTemp].arg2 = 0;
      sprintf(str_num, "%%%d", lastTemp + tempCounter);
      strcpy(tabelaTemp[lastTemp].result, str_num);
      lastTemp++;
    }
    | expr {$$ = $1;}
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
  fprintf(fptr,"define i32 @main() {\nentry:\n");

  labelStack = createPile();
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
  fprintf(fptr,"\n}\n");
  fclose(fptr);
  destroyPile(labelStack);

  printTempSymbTable(tabelaTemp, lastTemp);
  return 0;
}
