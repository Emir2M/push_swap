/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:07:02 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/26 03:55:46 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a && a->head && a->head->next)
	{
		rotate_nodes(a);
		write(1, "ra\n", 3);
		count_op(a, OP_RA);
	}
}

void	rb(t_stack *b)
{
	if (b && b->head && b->head->next)
	{
		rotate_nodes(b);
		write(1, "rb\n", 3);
		count_op(b, OP_RB);
	}
}

void	rotate_nodes(t_stack *stack)
{
	t_node	*temp;

	if (stack && stack->head && stack->head->next)
	{
		temp = pop_front(stack);
		add_back(stack, temp);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if ((a && a->head && a->head->next) || (b && b->head && b->head->next))
	{
		rotate_nodes(a);
		rotate_nodes(b);
		write(1, "rr\n", 3);
		if (a && a->config)
			count_op(a, OP_RR);
		else
			count_op(b, OP_RR);
	}
}
