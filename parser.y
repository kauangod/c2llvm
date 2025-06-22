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
String stringsEstaticas[128];
int stringsCount = 0;
int lastTemp = 0;
int tempCounter = 0;
char str_num[32];
int lastLabel = 0;
struct Pile *labelStack;
int indentation = 1;
int have_printf = 0;
int have_scanf = 0;

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
%token COMMA
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

%define parse.error verbose

%type <doubleValue> expr term factor

%type <intValue> logical_operations logical_expr else_command
%%

program:
    declarations commands
;

declarations:
      %empty
    | declarations declaration ';'
;

declaration:
      INTtype ID {
      fprintf(fptr, "\t");
      char* temp = strdup($2);
      declareVariableAtTable(hashTable, $2, Int);
      fprintf(fptr, "%%var%d = alloca i32, align 4\n", getSymbolTableValue(hashTable, temp).index);
      free(temp);
      }
    | FLOATtype ID {
      fprintf(fptr, "\t");
      char* temp = strdup($2);
      declareVariableAtTable(hashTable, $2, Float);
      fprintf(fptr, "%%var%d = alloca float, align 4\n", getSymbolTableValue(hashTable, temp).index);
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
    | atrib ';'
    | read_command ';'
    | write_command ';'
    | return_command ';'
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
      } B_LEFT commands {
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
    readCommand LEFT read_value RIGHT {
        have_scanf = 1;
    }
;
read_value: STRING COMMA '&'ID {
    String temp;
    Types type = parseString($1, &temp); /* Parseando para identificar o tipo da string */
    if (type != TypeError){
      for (int i = 0; i < indentation; i++) { fprintf(fptr, "\t"); }
      char* aux;
      aux = strdup($4);
      fprintf(fptr, "%%%d = call i32 (ptr, ...) @__isoc99_scanf(ptr noundef @.str.%d, ptr noundef %%var%d)\n", tempCounter + lastTemp, stringsCount, getSymbolTableValue(hashTable, aux).index);
      tempCounter++;
      free(aux);
      stringsEstaticas[stringsCount] = temp;
      stringsCount++;
    }
}
;

write_command:
    writeCommand LEFT write_value RIGHT { have_printf = 1; }
;

write_value:
      STRING COMMA write_formats {
      String temp;
      Types type = parseString($1, &temp);
      printTempSymbTableToFile(fptr, tabelaTemp, lastTemp, indentation, type);
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");

      switch (type) {
        case Float:
        fprintf(fptr, "%%%d = fpext float %s to double\n", tempCounter + lastTemp, tabelaTemp[lastTemp-1].result);
        tempCounter++;
        fprintf(fptr, "%%%d = call i32 (ptr, ...) @printf(ptr noundef @.str.%d, double noundef %%%d)\n", tempCounter + lastTemp, stringsCount, tempCounter + lastTemp - 1);
        break;
        case Int:
        fprintf(fptr, "%%%d = call i32 (ptr, ...) @printf(ptr noundef @.str.%d, i32 noundef %s)\n", tempCounter + lastTemp, stringsCount, tabelaTemp[lastTemp-1].result);
        break;
        case Char:
        fprintf(fptr, "%%%d = sext i8 %s to i32\n", tempCounter + lastTemp, tabelaTemp[lastTemp-1].result);
        tempCounter++;
        fprintf(fptr, "%%%d = call i32 (ptr, ...) @printf(ptr noundef @.str.%d, i32 noundef %%%d)\n", tempCounter + lastTemp, stringsCount, tempCounter + lastTemp - 1);
        break;
        case TypeError:
        printf("Má formatação no printf.\nEncerrando Compilação sem exito.\n");
        exit(EXIT_FAILURE);
        break;
      }
      stringsEstaticas[stringsCount] = temp;
      stringsCount++;
      tempCounter++;
      tempCounter += lastTemp;
      lastTemp = 0;
    }
    | STRING {
      for(int i =0; i < indentation; i++) fprintf(fptr, "\t");
      fprintf(fptr, "%%%d = call i32 (ptr, ...) @printf(ptr noundef @.str.%d)\n", tempCounter + lastTemp, stringsCount);
      String temp;
      Types type = parseString($1, &temp);
      if (type != TypeError) {
        printf("Má formatação no printf.\nEncerrando Compilação sem exito.\n");
        exit(EXIT_FAILURE);
      }
      stringsEstaticas[stringsCount] = temp;
      stringsCount++;
      tempCounter++;
    }
;

write_formats:
        expr {
        }

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
    | CHARACTER {$$ = lastTemp;
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

  yyin = fopen(argv[1], "r"); /* Abre o arquivo de entrada, posição zero é equivalente ao nome do programa executável. */
  if (yyin == NULL) {
      fprintf(stderr, "Error opening file `%s`\n", argv[1]);
      return 1;
  }


  // Open a file in writing mode
  fptr = fopen("saida.ll", "w");

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


  fprintf(fptr,"\n\n");
  if (have_printf) {
    fprintf(fptr,"\n\n");
    fprintf(fptr,"declare i32 @printf(ptr noundef, ...) #1\n");
  }
  if (have_scanf) {
    fprintf(fptr,"\n\n");
    fprintf(fptr,"declare i32 @__isoc99_scanf(ptr noundef, ...) #1\n");
  }
  fprintf(fptr,"attributes #0 = { noinline nounwind optnone sspstrong uwtable \"frame-pointer\"=\"all\" \"min-legal-vector-width\"=\"0\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"x86-64\" \"target-features\"=\"+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"tune-cpu\"=\"generic\" }\n");
  fprintf(fptr,"attributes #1 = { \"frame-pointer\"=\"all\" \"no-trapping-math\"=\"true\" \"stack-protector-buffer-size\"=\"8\" \"target-cpu\"=\"x86-64\" \"target-features\"=\"+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87\" \"tune-cpu\"=\"generic\" }\n");

  for(int i = 0; i < stringsCount; i++) {
    fprintf(fptr,"@.str.%d = private unnamed_addr constant [%d x i8] c\"%s\", align 1\n",
            i, stringsEstaticas[i].size, stringsEstaticas[i].data);
    free(stringsEstaticas[i].data);
  }
  fclose(fptr);
  destroyPile(labelStack);

  printTempSymbTable(tabelaTemp, lastTemp);
  return 0;
}
