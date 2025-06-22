#ifndef PILE
#define PILE
struct Pile {
  double *arr;
  int size;
  int allocated;
};

int pilePush(struct Pile *pile, double data);

struct Pile *createPile(void);

void destroyPile(struct Pile *pile);

double popPile(struct Pile *pile);

double topPile(struct Pile *pile);

struct EventPile {
  struct Event *arr;
  int size;
  int allocated;
};

int eventPilePush(struct EventPile *pile, struct Event data);

struct EventPile *createEventPile(void);

void destroyEventPile(struct EventPile *pile);

struct Event popEventPile(struct EventPile *pile);

struct Event topEventPile(struct EventPile *pile);

void printEventPile(struct EventPile *pile);

#endif // !PILE
