#include "stack.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int stackPush(struct Stack *stack, double data) {
  if (!stack)
    return -1;

  if (stack->size < stack->allocated - 1) {
    stack->arr[stack->size] = data;
    stack->size++;
    return 0;
  }
  stack->allocated = 3 / 2 * stack->allocated;
  stack->arr = (double *)realloc(stack->arr, stack->allocated * sizeof(double));
  if (!stack->arr)
    return -1;

  stack->arr[stack->size] = data;
  stack->size++;
  return 0;
}

struct Stack *createStack(void) {
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->size = 0;
  stack->allocated = 10;
  stack->arr = (double *)malloc(stack->allocated * sizeof(double));
  return stack;
}

void destroyStack(struct Stack *stack) {
  if (!stack)
    return;
  if (stack->arr) {
    free(stack->arr);
    stack->arr = NULL;
  }
  free(stack);
}

double popStack(struct Stack *stack) {
  if (!stack)
    exit(1);
  if (!stack->size)
    exit(1);

  double var = stack->arr[--(stack->size)];
  return var;
}

double topStack(struct Stack *stack) {
  if (!stack)
    exit(1);
  return stack->arr[stack->size - 1];
}

int eventStackPush(struct EventStack *stack, struct Event data) {
  if (!stack)
    return -1;

  if (stack->size < stack->allocated - 1) {
    stack->arr[stack->size] = data;
    stack->size++;
    return 0;
  }
  stack->allocated = 3 / 2 * stack->allocated;
  stack->arr = (struct Event *)realloc(stack->arr,
                                      stack->allocated * sizeof(struct Event));
  if (!stack->arr)
    return -1;

  stack->arr[stack->size] = data;
  stack->size++;
  return 0;
}

struct EventStack *createEventStack(void) {
  struct EventStack *stack = (struct EventStack *)malloc(sizeof(struct EventStack));
  stack->size = 0;
  stack->allocated = 10;
  stack->arr = (struct Event *)malloc(stack->allocated * sizeof(struct Event));
  return stack;
}

void destroyEventStack(struct EventStack *stack) {
  if (!stack)
    return;
  if (stack->arr) {
    free(stack->arr);
    stack->arr = NULL;
  }
  free(stack);
}

struct Event popEventStack(struct EventStack *stack) {
  if (!stack)
    exit(1);
  if (!stack->size)
    exit(1);

  struct Event var = stack->arr[--(stack->size)];
  return var;
}

struct Event topEventStack(struct EventStack *stack) {
  if (!stack)
    exit(1);
  return stack->arr[stack->size - 1];
}

void printEventStack(struct EventStack *stack) {
  printf("Stack de tamanho %d:\n", stack->size);
  for (int i = 0; i < stack->size; i++) {
    printf("Evento %s, %d, %f.\n", stack->arr[i].name,
           stack->arr[i].isAtrib, stack->arr[i].value.doubleValue);
  }
}
