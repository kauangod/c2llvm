#ifndef STACK
#define STACK
struct Stack {
  double *arr;
  int size;
  int allocated;
};

int stackPush(struct Stack *stack, double data);

struct Stack *createStack(void);

void destroyStack(struct Stack *stack);

double popStack(struct Stack *stack);

double topStack(struct Stack *stack);

struct EventStack {
  struct Event *arr;
  int size;
  int allocated;
};

int eventStackPush(struct EventStack *stack, struct Event data);

struct EventStack *createEventStack(void);

void destroyEventStack(struct EventStack *stack);

struct Event popEventStack(struct EventStack *stack);

struct Event topEventStack(struct EventStack *stack);

void printEventStack(struct EventStack *stack);

#endif // !STACK
