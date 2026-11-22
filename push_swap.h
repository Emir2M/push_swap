/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:45:00 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/22 19:03:14 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>

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
t_node				*create_node(int value);
void				init_stack(t_stack *stack);
void				add_back(t_stack *stack, t_node *new_node);

#endif