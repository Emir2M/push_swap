/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:45:00 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/23 01:17:06 by mmetin           ###   ########.fr       */
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
t_node				*create_node(int value);
void				init_stack(t_stack *stack);
void				add_back(t_stack *stack, t_node *new_node);

#endif