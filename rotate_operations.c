/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:07:02 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 19:41:25 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_nodes(t_stack *stack)
{
	t_node	*temp;

	if (stack && stack->head && stack->head->next)
	{
		temp = pop_front(stack);
		add_back(stack, temp);
	}
}

void	ra(t_stack *a)
{
	if (a && a->head && a->head->next)
	{
		rotate_nodes(a);
		write(1, "ra\n", 3);
		if (a->bench)
		{
			a->bench->ra++;
			a->bench->total++;
		}
	}
}

void	rb(t_stack *b)
{
	if (b && b->head && b->head->next)
	{
		rotate_nodes(b);
		write(1, "rb\n", 3);
		if (b->bench)
		{
			b->bench->rb++;
			b->bench->total++;
		}
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if ((a && a->head && a->head->next) || (b && b->head && b->head->next))
	{
		rotate_nodes(a);
		rotate_nodes(b);
		write(1, "rr\n", 3);
		if (a && a->bench)
		{
			a->bench->rr++;
			a->bench->total++;
		}
		else if (b && b->bench)
		{
			b->bench->rr++;
			b->bench->total++;
		}
	}
}
