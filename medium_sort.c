/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:42:26 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 17:56:36 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while ((chunk + 1) <= size / (chunk + 1))
		chunk++;
	return (chunk);
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (a->size > 0)
	{
		if (a->head->index < pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if (a->head->index - pushed < chunk)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

static int	find_max_position(t_stack *b)
{
	t_node	*current;
	int		max;
	int		max_pos;
	int		pos;

	if (!b || !b->head)
		return (-1);
	current = b->head;
	max = current->index;
	max_pos = 0;
	pos = 0;
	while (current != NULL)
	{
		if (current->index > max)
		{
			max = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

static void	move_max_to_top(t_stack *b)
{
	int	pos;

	pos = find_max_position(b);
	if (pos < 0)
		return ;
	if (pos <= b->size / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		while (pos < b->size)
		{
			rrb(b);
			pos++;
		}
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int	chunk;

	if (!a || !b || a->size < 2)
		return ;
	assign_indices(a);
	chunk = get_chunk_size(a->size);
	push_chunks(a, b, chunk);
	while (b->size > 0)
	{
		move_max_to_top(b);
		pa(a, b);
	}
}
