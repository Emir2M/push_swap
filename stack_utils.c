/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:04:06 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/23 02:06:51 by mmetin           ###   ########.fr       */
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

t_node	*pop_back(t_stack *stack)
{
	t_node	*temp;

	if (!stack || !stack->tail)
		return (NULL);
	temp = stack->tail;
	stack->tail = stack->tail->prev;
	if (stack->tail != NULL)
		stack->tail->next = NULL;
	else
		stack->head = NULL;
	temp->prev = NULL;
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
	int mistakes;
	t_node *curr;
	t_node *next;

	if (!stack_a || stack_a->size < 2)
		return (0.0);
	mistakes = 0;
	curr = stack_a->head;
	while (curr)
	{
		next = curr->next;
		while (next)
		{
			if (curr->value > next->value)
				mistakes++;
			next = next->next;
		}
		curr = curr->next;
	}
	return ((double)mistakes / ((stack_a->size * (stack_a->size - 1)) / 2));
}