/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:45:00 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 20:20:49 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define MODE_ADAPTIVE 0
# define MODE_SIMPLE 1
# define MODE_MEDIUM 2
# define MODE_COMPLEX 3

typedef struct s_options
{
	int				strategy;
	int				bench;
	int				start;
}					t_options;

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
	double			disorder;
}					t_bench;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
	t_bench			*bench;
}					t_stack;

t_node				*create_node(int value);
void				init_stack(t_stack *stack);
void				add_back(t_stack *stack, t_node *new_node);
t_node				*pop_front(t_stack *stack);
t_node				*pop_back(t_stack *stack);
void				add_front(t_stack *stack, t_node *new_node);
double				compute_disorder(t_stack *stack_a);
void				swap_nodes(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				rotate_nodes(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				reverse_rotate_nodes(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
int					find_min_position(t_stack *a);
void				move_min_to_top(t_stack *a);
void				simple_sort(t_stack *a, t_stack *b);
void				free_split(char **split);
void				error(t_stack *stack, char **numbers);
char				**ft_split(char const *s, char c);
void				free_stack(t_stack *stack);
void				assign_indices(t_stack *a);
void				medium_sort(t_stack *a, t_stack *b);
void				complex_sort(t_stack *a, t_stack *b);
void				adaptive_sort(t_stack *a, t_stack *b);
void				init_bench(t_bench *bench);
void				bench_putnbr(int n);
void				bench_putop(char *name, int count);
void				bench_print_ops(t_bench *bench);
void				bench_print_disorder(double disorder);
void				bench_print_strategy(int strategy);
void				print_benchmark(t_bench *bench, int strategy);
void				init_options(t_options *options);
int					parse_options(int argc, char **argv, t_options *options);
int					select_strategy(int strategy, double disorder);

#endif
