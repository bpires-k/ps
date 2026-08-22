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

//main.c
int main(int argc, char **argv);
void sort_stact(t_bench *bm, t_stack **a, t_stack **b, int size);
double	compute_disorder(t_stack *stack);

//init_bench.c
t_bench *init_bench(void);

//clean.c
int free_all(t_bench *bm, t_stack **a, t_stack **b);
int error(t_bench *bm, t_stack **a, t_stack **b);

//input.c
int set_value(t_stack **a, char *av);
int set_flag(t_bench *benchmark, char *av);
int set_input(t_bench *benchmark, t_stack **a, char *av);
int	set_inputs(t_bench *benchmark, t_stack **a, char **av);
int	input_checker(t_bench *benchmark, t_stack **a,int ac, char **av);
void init_index(t_stack **a);

//helper01.c
long ft_atol(char *nb);
int ft_strcmp(char *s1, char *s2);
int	ft_sqrt(int nb);
int is_sorted(t_stack **a, t_stack **b);
//helperlst01.c
t_stack *ft_lstnew(int value);
void ft_lstadd_front(t_stack **stack, t_stack *new);
void ft_lstadd_back(t_stack **stack, t_stack *new);
void ft_lstclear(t_stack **stack);
int add_value(t_stack **a, int value);

//helperlst02.c
t_stack *ft_lstmin(t_stack *stack);
t_stack *ft_lstmax(t_stack *stack);
//moves01.c
void swap(t_stack **stack);
void rotate(t_stack **stack);
void r_rotate(t_stack **stack);
void push(t_stack **stack1, t_stack **stack2);

//moves_a.c
void sa(t_bench *bm, t_stack **a, t_stack **b);
void ra(t_bench *bm, t_stack **a, t_stack **b);
void rra(t_bench *bm, t_stack **a, t_stack **b);
void pa(t_bench *bm, t_stack **a, t_stack **b);

//moves_b.c
void sb(t_bench *bm, t_stack **a, t_stack **b);
void rb(t_bench *bm, t_stack **a, t_stack **b);
void rrb(t_bench *bm, t_stack **a, t_stack **b);
void pb(t_bench *bm, t_stack **a, t_stack **b);

//moves_both.c
void ss(t_bench *bm, t_stack **a, t_stack **b);
void rr(t_bench *bm, t_stack **a, t_stack **b);
void rrr(t_bench *bm, t_stack **a, t_stack **b);

//small_sort.c
void small_sort(t_bench *bm, t_stack **a, t_stack **b, int size);
void sort_mt3(t_bench *bm, t_stack **a, t_stack **b, int size);
void sort_3(t_bench *bm, t_stack **a, t_stack **b);
void sort_2(t_bench *bm, t_stack **a, t_stack **b);

//simple.c
void findmin_sort(t_bench *bm, t_stack **a, t_stack **b, int size);
int find_position(t_stack *stack, int value);

//medium.c
void bucket_sort(t_bench *bm, t_stack **a, t_stack **b, int size);
void bucket_to_b(t_bench *bm, t_stack **a, t_stack **b, int size);
void select_sort(t_bench *bm, t_stack **a, t_stack **b, int size);

//complex.c
void LSD_sort(t_bench *bm, t_stack **a, t_stack **b, int size);
void index_to_binary(t_stack *stack);
#endif
