/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 18:42:26 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/23 19:22:59 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *a, int value)
{
	int		index;
	t_node	*current;

	index = 0;
	current = a->head;
	while (current != NULL)
	{
		if (current->value < value)
			index++;
		current = current->next;
	}
	return (index);
}

void	copy_values(t_stack *a, int *arr)
{
	t_node	*current;
	int		i;

	i = 0;
	current = a->head;
	while (current != NULL)
	{
		arr[i] = current->value;
		i++;
		current = current->next;
	}
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	get_sorted_index(int *arr, int size, int value)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}