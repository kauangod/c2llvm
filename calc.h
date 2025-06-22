#ifndef CALC
#define CALC
#include "utils.h"
#include "pilha.h"
#include "ht.h"
#include <stdlib.h>
#include <stdio.h>
void pushAtribEvent(struct EventPile *pile, char* name, double value);
void popAtribEvent(struct EventPile* pile, ht* hashTable);
void handleIfCommand(int boolean, int elseExists, struct EventPile* pile, ht* hashTable);
double getNumberTableValue(ht *hashTable, char *name);
Symbol getSymbolTableValue(ht *hashTable, char *name);
char getCharTableValue(ht *hashTable, char *name);
int getBooleanTableValue(ht *hashTable, char *name);
void declareVariableAtTable(ht *hash, char *name, Types type);
void assignNumberValue(ht *hash, char *name, double value);
void assignCharValue(ht *hash, char *name, char value);
void assignBooleanValue(ht *hash, char *name, int value);
char* process_string(const char* text); // made by chatgpt
void printTempSymbTableToFile(FILE *file, TempSymb *table, int max, int identation, Types type);
char* tempSymbTableToString(TempSymb *table, int max);

#endif // !CALC
