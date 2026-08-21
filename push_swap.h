#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

typedef struct s_bench {
  int display;
  double disorder;
  char *strategy;
  char *big_o;
  int moves[11];
} t_bench;

typedef struct s_stack {
  int value;
  int index;
  struct s_stack *prev;
  struct s_stack *next;
} t_stack;

int main(int argc, char **argv);

t_bench *init_bench(void);
#endif
