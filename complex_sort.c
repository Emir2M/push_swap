/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:09:43 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 18:31:34 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		max = max >> 1;
		bits++;
	}
	return (bits);
}

void	complex_sort(t_stack *a, t_stack *b)
{
	int	bits;
	int	bit;
	int	size;
	int	i;

	if (!a || !b || a->size < 2)
		return ;
	assign_indices(a);
	size = a->size;
	bits = get_max_bits(size);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i++ < size)
		{
			if ((a->head->index >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
