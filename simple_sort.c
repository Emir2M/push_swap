/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:43:20 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/23 17:09:46 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_stack *a)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	min_pos = 0;
	pos = 0;
	if (!a || a->head == NULL)
		return (-1);
	min = a->head->value;
	current = a->head;
	while (current != NULL)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack *a)
{
	int	min_pos;
	int	count;

	if (!a || a->head == NULL)
		return ;
	min_pos = find_min_position(a);
	if (min_pos <= (a->size / 2))
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
	else
	{
		count = a->size - min_pos;
		while (count > 0)
		{
			rra(a);
			count--;
		}
	}
}

void	simple_sort(t_stack *a, t_stack *b)
{
	while (a->head != NULL)
	{
		move_min_to_top(a);
		pb(a, b);
	}
	while (b->head != NULL)
	{
		pa(a, b);
	}
}
