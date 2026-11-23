/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:45:00 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/23 18:26:21 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				size;
}					t_stack;

/* Node & Stack initialization */
t_node				*create_node(int value);
void				init_stack(t_stack *stack);

/* Stack utilities */
void				add_back(t_stack *stack, t_node *new_node);
t_node				*pop_front(t_stack *stack);
t_node				*pop_back(t_stack *stack);
void				add_front(t_stack *stack, t_node *new_node);
double				compute_disorder(t_stack *stack_a);

/* Swap operations */
void				swap_nodes(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

/* Push operations */
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

/* Rotate operations */
void				rotate_nodes(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

/* Reverse rotate operations */
void				reverse_rotate_nodes(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// emirhyil ekledikleri 
int find_min_position(t_stack *a);
void	move_min_to_top(t_stack *a);
void	simple_sort(t_stack *a, t_stack *b);

/* free stack  */
void	free_stack(t_stack *stack)

#endif
