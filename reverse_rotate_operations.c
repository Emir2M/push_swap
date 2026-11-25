/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 19:42:03 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 19:42:05 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_nodes(t_stack *stack)
{
	t_node	*temp;

	if (stack && stack->head && stack->head->next)
	{
		temp = pop_back(stack);
		add_front(stack, temp);
	}
}

void	rra(t_stack *a)
{
	if (a && a->head && a->head->next)
	{
		reverse_rotate_nodes(a);
		write(1, "rra\n", 4);
		if (a->bench)
		{
			a->bench->rra++;
			a->bench->total++;
		}
	}
}

void	rrb(t_stack *b)
{
	if (b && b->head && b->head->next)
	{
		reverse_rotate_nodes(b);
		write(1, "rrb\n", 4);
		if (b->bench)
		{
			b->bench->rrb++;
			b->bench->total++;
		}
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if ((a && a->head && a->head->next) || (b && b->head && b->head->next))
	{
		reverse_rotate_nodes(a);
		reverse_rotate_nodes(b);
		write(1, "rrr\n", 4);
		if (a && a->bench)
		{
			a->bench->rrr++;
			a->bench->total++;
		}
		else if (b && b->bench)
		{
			b->bench->rrr++;
			b->bench->total++;
		}
	}
}
