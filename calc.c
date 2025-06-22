#include "calc.h"
#include "pilha.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void pushAtribEvent(struct EventPile *pile, char *name, double value) {
  // printf("Tá colocando %f em %s .\n", value, name);
  struct Event temp;
  temp.isAtrib = 1;
  strcpy(temp.name, name);
  temp.value.doubleValue = value;
  eventPilePush(pile, temp);
}

void popAtribEvent(struct EventPile *pile, ht *hashTable) {
  struct Event temp;
  if (pile->size > 0) {
    printf("Evento %s, %d, %f.\n", topEventPile(pile).name,
           topEventPile(pile).isAtrib, topEventPile(pile).value.doubleValue);
    temp = popEventPile(pile);
    if (temp.isAtrib) {
      double *tt = malloc(sizeof(double));
      *tt = temp.value.doubleValue;
      ht_set(hashTable, temp.name, tt);
    }
  }
}

void handleIfCommand(int boolean, int elseExists, struct EventPile *pile,
                     ht *hashTable) {
  // printEventPile(pile);
  struct Event temp;
  if (!pile || pile->size <= 0)
    return;
  if (!boolean && elseExists) {
    popAtribEvent(pile, hashTable);
    return;
  }
  popEventPile(pile);
  popAtribEvent(pile, hashTable);
  return;
}

double getNumberTableValue(ht *hashTable, char *name) {
  Symbol *symb = ht_get(hashTable, name);
  if (symb)
    switch (symb->Type) {
    case Int:
      free(name);
      return ((int)symb->value.intValue);
    case Float:
      free(name);
      return ((int)symb->value.intValue);
    default:
      printf("Error: Wrong use of this function, variable %s is NaN\n", name);
      free(name);
      exit(EXIT_FAILURE);
    }
  printf("Error: variable '%s' not declared\n", name);
  free(name);
  exit(EXIT_FAILURE);
}

Symbol getSymbolTableValue(ht *hashTable, char *name) {
  Symbol *symb = ht_get(hashTable, name);
  if (symb) {
    return *symb;
  }
  printf("Error: variable '%s' not declared\n", name);
  exit(EXIT_FAILURE);
}

char getCharTableValue(ht *hashTable, char *name) {
  Symbol *symb = ht_get(hashTable, name);
  if (!symb) {
    if (symb->Type != Char) {
      printf("Error: Wrong use of this function, variable %s is not a char\n",
             name);
      free(name);
      exit(EXIT_FAILURE);
    } else {
      free(name);
      return ((char)symb->value.charValue);
    }
  }
  printf("Error: variable '%s' not declared\n", name);
  free(name);
  exit(EXIT_FAILURE);
}

int getBooleanTableValue(ht *hashTable, char *name) {
  Symbol *symb = ht_get(hashTable, name);
  if (!symb) {
    if (symb->Type != Bool) {
      printf(
          "Error: Wrong use of this function, variable %s is not a boolean\n",
          name);
      free(name);
      exit(EXIT_FAILURE);
    } else {
      free(name);
      return ((int)symb->value.intValue);
    }
  }
  printf("Error: variable '%s' not declared\n", name);
  free(name);
  exit(EXIT_FAILURE);
}

void declareVariableAtTable(ht *hash, char *name, Types type) {
  if (ht_get(hash, name)) {
    printf("Error: Redeclaration of variable '%s'\n", name);
    free(name);
    exit(EXIT_FAILURE);
  }
  Symbol *symb = malloc(sizeof(Symbol));
  symb->Type = type;
  symb->index = hash->length + 1;
  ht_set(hash, name, symb);
  free(name);
}

void assignNumberValue(ht *hash, char *name, double value) {
  Symbol *symb = ht_get(hash, name);
  if (!symb) {
    printf("Error: Assign of undeclared variable '%s'\n", name);
    free(name);
    exit(EXIT_FAILURE);
  }
  if (symb->Type == Int)
    symb->value.intValue = (int)value;
  else if (symb->Type == Float)
    symb->value.doubleValue = (double)value;
  else {
    if (symb->Type == Char)
      printf("Error: Assign of wrong variable type. Variable '%s' is a char\n",
             name);
    else if (symb->Type == Bool)
      printf(
          "Error: Assign of wrong variable type. Variable '%s' is a boolean\n",
          name);
    else
      printf("Error: Assign of wrong variable type. Variable '%s' is unknown\n",
             name);
    free(name);
    exit(EXIT_FAILURE);
  }
  free(name);
}

void assignCharValue(ht *hash, char *name, char value) {
  Symbol *symb = ht_get(hash, name);
  if (!symb) {
    printf("Error: Assign of undeclared variable '%s'\n", name);
    free(name);
    exit(EXIT_FAILURE);
  }
  if (symb->Type != Char) {
    printf(
        "Error: Assign of wrong variable type. Variable '%s' is not a char\n",
        name);
    free(name);
    exit(EXIT_FAILURE);
  }
  free(name);
  symb->value.charValue = value;
}

void assignBooleanValue(ht *hash, char *name, int value) {
  Symbol *symb = ht_get(hash, name);
  if (!symb) {
    printf("Error: Assign of undeclared variable '%s'\n", name);
    free(name);
    exit(EXIT_FAILURE);
  }
  if (symb->Type != Bool) {
    printf("Error: Assign of wrong variable type. Variable '%s' is not a "
           "boolean\n",
           name);
    free(name);
    exit(EXIT_FAILURE);
  }
  free(name);
  symb->value.intValue = value;
}

/* MADE BY CHATGPT */
char *process_string(const char *text) {
  size_t len = strlen(text);
  char *result = (char *)malloc(len); // Allocate enough space (might shrink)
  if (!result)
    return NULL; // Always check malloc

  size_t j = 0;
  for (size_t i = 1; i < len - 1; ++i) { // Skip the first and last quotes
    if (text[i] == '\\') {
      i++;
      switch (text[i]) {
      case 'n':
        result[j++] = '\n';
        break;
      case 't':
        result[j++] = '\t';
        break;
      case 'r':
        result[j++] = '\r';
        break;
      case '\\':
        result[j++] = '\\';
        break;
      case '"':
        result[j++] = '"';
        break;
      // You can add more escapes here if you want
      default:
        result[j++] = text[i];
        break; // Unknown escape: copy as-is
      }
    } else {
      result[j++] = text[i];
    }
  }
  result[j] = '\0'; // Null-terminate
  return result;
}
/* END OF MADE BY CHATGPT */

void printTempSymbTable(TempSymb *table, int max) {
  for (int i = 0; i < max; i++) {
    printf("| result %s | op \'%c\' | arg1 %.1f | arg2 %.1f |\n",
           table[i].result, table[i].op, table[i].arg1, table[i].arg2);
    printf("x - - - - - | - - - -| - - - - -| - - - - -x\n");
  }
}

void printTempSymbTableToFile(FILE *file, TempSymb *table, int max,
                              int identation, Types type) {
  for (int i = 0; i < max; i++) {
    switch (table[i].op) {
    case OP_EQUAL:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = fadd float 0.0, %f\n", table[i].result,
                table[i].arg1);
        break;
      case Int:
        fprintf(file, "%s = add i32 0, %d\n", table[i].result,
                (int)table[i].arg1);
        break;
      case Char:
        fprintf(file, "%s = add i8 0, %d\n", table[i].result,
                (int)table[i].arg1);
      default:
        break;
      }
      break;
    case OP_MULT:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = fmul float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = mul i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = mul i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_DIV:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = fdiv float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = udiv i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = udiv i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_PLUS:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = fadd float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = add i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = add i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_MINUS:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = fsub float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = sub i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = sub i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_VAR:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = load float, float* %s, align 4\n", table[i].result,
                table[i].name);
        break;
      case Int:
        fprintf(file, "%s = load i32, i32* %s, align 4\n", table[i].result,
                table[i].name);
        break;
      case Char:
        fprintf(file, "%s = load i8, i8* %s, align 1\n", table[i].result,
                table[i].name);
      default:
        break;
      }
      break;
    case OP_L_EQUAL:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = icmp eq float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = icmp eq i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = icmp eq i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_AND:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      fprintf(file, "%s = %s && %s;\n", table[i].result,
              table[(int)table[i].arg1].result,
              table[(int)table[i].arg2].result);
      break;
    case OP_OR:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      fprintf(file, "%s = %s || %s;\n", table[i].result,
              table[(int)table[i].arg1].result,
              table[(int)table[i].arg2].result);
      break;
    case OP_DIF:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = icmp ne float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = icmp ne i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = icmp ne i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_GT:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = icmp sgt float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = icmp sgt i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = icmp sgt i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_GE:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = icmp sge float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = icmp sge i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = icmp sge i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_LT:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = icmp slt float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = icmp slt i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = icmp slt i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_LE:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = icmp sle float %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Int:
        fprintf(file, "%s = icmp sle i32 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
        break;
      case Char:
        fprintf(file, "%s = icmp sle i8 %s, %s\n", table[i].result,
                table[(int)table[i].arg1].result,
                table[(int)table[i].arg2].result);
      default:
        break;
      }
      break;
    case OP_NOT:
      for (int i = 0; i < identation; i++)
        fprintf(file, "\t");
      switch (type) {
      case Float:
        fprintf(file, "%s = icmp ne float %s, 0\n", table[i].result,
                table[(int)table[i].arg1].result);
        break;
      case Int:
        fprintf(file, "%s = icmp ne i32 %s, 0\n", table[i].result,
                table[(int)table[i].arg1].result);
        break;
      case Char:
        fprintf(file, "%s = icmp ne i8 %s, 0\n", table[i].result,
                table[(int)table[i].arg1].result);
      default:
        break;
      }
      break;
    }
  }
}

char *tempSymbTableToString(TempSymb *table, int max) {
  if (max <= 0)
    return NULL;
  char *buffer = (char *)malloc(max * 128 * sizeof(char));
  for (int i = 0; i < max; i++) {
    switch (table[i].op) {
    case OP_EQUAL:
      sprintf(buffer, "%s = %f;\n", table[i].result, table[i].arg1);
      break;
    case OP_MULT:
      sprintf(buffer, "%s = %s * %s;\n", table[i].result,
              table[(int)table[i].arg1].result,
              table[(int)table[i].arg2].result);
      break;
    case OP_DIV:
      sprintf(buffer, "%s = %s / %s;\n", table[i].result,
              table[(int)table[i].arg1].result,
              table[(int)table[i].arg2].result);
      break;
    case OP_PLUS:
      sprintf(buffer, "%s = %s + %s;\n", table[i].result,
              table[(int)table[i].arg1].result,
              table[(int)table[i].arg2].result);
      break;
    case OP_MINUS:
      sprintf(buffer, "%s = %s - %s;\n", table[i].result,
              table[(int)table[i].arg1].result,
              table[(int)table[i].arg2].result);
      break;
    case OP_VAR:
      sprintf(buffer, "%s = %s;\n", table[i].result, table[i].name);
      break;
    default:
      break;
    }
  }
  return buffer;
}

Types parseString(const char *string, String *result) {
  size_t old_len = strlen(string);
  size_t count = 0;

  // First, count how many times "old" appears in "source"
  const char *pos = string;
  while ((pos = strstr(pos, "\n")) != NULL) {
    count++;
    pos += old_len;
  }

  // Allocate enough space for new string
  size_t new_size = strlen(string) + (count+1) * 3;
  result->data = malloc(new_size);
  result->size = strlen(string)  + 1;
  if (!result->data)
    return TypeError;

  char *dst = result->data;
  pos = string;

  while (*pos) {
    const char *match = strstr(pos, "\n");
    if (match) {
      // Copy up to match
      size_t len = match - pos;
      memcpy(dst, pos, len);
      dst += len;

      // Copy replacement string
      memcpy(dst, "\\0A", 3);
      dst += 3;

      pos = match + 1;
    } else {
      // No more matches, copy the rest
      strcpy(dst, pos);
      break;
    }
  }
  int size = strlen(result->data);
  result->data[size] = '\\';
  result->data[size+1] = '0';
  result->data[size+2] = '0';
  result->data[size+3] = '\0';

  pos = string;

  const char *match = strstr(pos, "%d");
  if (match) {
    return Int;
  }
  match = strstr(pos, "%f");
  if (match) {
    return Float;
  }
  match = strstr(pos, "%c");
  if (match) {
    return Char;
  }
  return TypeError;
}
