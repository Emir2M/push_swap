/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 17:03:42 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 17:56:59 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->head;
	while (current != NULL)
	{
		compare = a->head;
		index = 0;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}
