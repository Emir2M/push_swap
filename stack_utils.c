/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:04:06 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/22 19:05:47 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_stack *stack, t_node *new_node)
{
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->tail->next = new_node;
		new_node->prev = stack->tail;
		stack->tail = new_node;
	}
	stack->size += 1;
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->head)
		return (NULL);
	temp = stack->head;
	stack->head = stack->head->next;
	if (stack->head != NULL)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	temp->next = NULL;
	stack->size -= 1;
	return (temp);
}

void	add_front(t_stack *stack, t_node *new_node)
{
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size += 1;
}

double	compute_disorder(t_stack *stack_a)
{
	int stack_size;
	int mistakes;
	int total_pairs;
	t_node *curr_node;
	t_node *next_node;

	stack_size = stack_a->size;
	
	if(!stack_a || stack_a ->size <2)
		return(0.0);
	mistakes = 0;
	total_pairs = 0;

	curr_node = stack_a->head;

	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		while (next_node != NULL)
		{
			if (curr_node->value > next_node->value)
				mistakes++;
			next_node = next_node->next;
		}
		curr_node = curr_node->next;
	}
	total_pairs = (stack_size * (stack_size - 1)) / 2;
	return ((double)mistakes / total_pairs);
}
