/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:45:00 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/26 03:54:23 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define OP_COUNT 11

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}					t_op;
typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}					t_strategy;

typedef struct s_config
{
	t_strategy		strategy;
	int				bench_mode;
	double			disorder;
	int				total_operations;
	int				op_count[OP_COUNT];
}					t_config;

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
	t_config		*config;
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

/* Free operations */
void				free_stack(t_stack *stack);
void				free_split(char **split);
void				error(t_stack *stack, char **numbers);

/* Split & Strcmp */
char				**ft_split(char const *s, char c);
int					ft_strcmp(char *s1, char *s2);

/* Sorting & Index */
void				assign_indices(t_stack *a);
void				simple_sort(t_stack *a, t_stack *b);
void				medium_sort(t_stack *a, t_stack *b);
void				complex_sort(t_stack *a, t_stack *b);
void				adaptive_sort(t_stack *a, t_stack *b);
void				execute_sort(t_stack *a, t_stack *b, t_config *config);

/* Config & Parsing operations */
void				init_config(t_config *config);
void				count_op(t_stack *stack, t_op op);
void				putstr_err(const char *s);
void				putnbr_err(int n);
void				print_op_err(const char *name, int count, int sep);
void				print_bench(t_config *config);
int					is_valid_number(char *number);
int					get_number(const char *number);
int					has_duplicate(t_stack *stack, int num);
int					handle_flag(char *str, t_config *config);
int					parse_args(int argc, char **argv, t_stack *stack,
						t_config *config);

#endif
