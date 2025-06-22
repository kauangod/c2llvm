#include "pilha.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int pilePush(struct Pile *pile, double data) {
  if (!pile)
    return -1;

  if (pile->size < pile->allocated - 1) {
    pile->arr[pile->size] = data;
    pile->size++;
    return 0;
  }
  pile->allocated = 3 / 2 * pile->allocated;
  pile->arr = (double *)realloc(pile->arr, pile->allocated * sizeof(double));
  if (!pile->arr)
    return -1;

  pile->arr[pile->size] = data;
  pile->size++;
  return 0;
}

struct Pile *createPile(void) {
  struct Pile *pile = (struct Pile *)malloc(sizeof(struct Pile));
  pile->size = 0;
  pile->allocated = 10;
  pile->arr = (double *)malloc(pile->allocated * sizeof(double));
  return pile;
}

void destroyPile(struct Pile *pile) {
  if (!pile)
    return;
  if (pile->arr) {
    free(pile->arr);
    pile->arr = NULL;
  }
  free(pile);
}

double popPile(struct Pile *pile) {
  if (!pile)
    exit(1);
  if (!pile->size)
    exit(1);

  double var = pile->arr[--(pile->size)];
  return var;
}

double topPile(struct Pile *pile) {
  if (!pile)
    exit(1);
  return pile->arr[pile->size - 1];
}

int eventPilePush(struct EventPile *pile, struct Event data) {
  if (!pile)
    return -1;

  if (pile->size < pile->allocated - 1) {
    pile->arr[pile->size] = data;
    pile->size++;
    return 0;
  }
  pile->allocated = 3 / 2 * pile->allocated;
  pile->arr = (struct Event *)realloc(pile->arr,
                                      pile->allocated * sizeof(struct Event));
  if (!pile->arr)
    return -1;

  pile->arr[pile->size] = data;
  pile->size++;
  return 0;
}

struct EventPile *createEventPile(void) {
  struct EventPile *pile = (struct EventPile *)malloc(sizeof(struct EventPile));
  pile->size = 0;
  pile->allocated = 10;
  pile->arr = (struct Event *)malloc(pile->allocated * sizeof(struct Event));
  return pile;
}

void destroyEventPile(struct EventPile *pile) {
  if (!pile)
    return;
  if (pile->arr) {
    free(pile->arr);
    pile->arr = NULL;
  }
  free(pile);
}

struct Event popEventPile(struct EventPile *pile) {
  if (!pile)
    exit(1);
  if (!pile->size)
    exit(1);

  struct Event var = pile->arr[--(pile->size)];
  return var;
}

struct Event topEventPile(struct EventPile *pile) {
  if (!pile)
    exit(1);
  return pile->arr[pile->size - 1];
}

void printEventPile(struct EventPile *pile) {
  printf("Pilha de tamanho %d:\n", pile->size);
  for (int i = 0; i < pile->size; i++) {
    printf("Evento %s, %d, %f.\n", pile->arr[i].name,
           pile->arr[i].isAtrib, pile->arr[i].value.doubleValue);
  }
}
