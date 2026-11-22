/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 17:12:49 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/23 01:22:10 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_stack *stack)
{
	t_node *temp_node1;
	t_node *temp_node2;

	if (!stack || stack->head == NULL || stack->head->next == NULL)
		return ;

	temp_node1 = stack->head;
	temp_node2 = stack->head->next;
	temp_node1->next = temp_node2->next;
	temp_node2->next = temp_node1;
	temp_node2->prev = NULL;
	temp_node1->prev = temp_node2;
	stack->head = temp_node2;
	if (temp_node1->next != NULL)
		temp_node1->next->prev = temp_node1;
	else
		stack->tail = temp_node1;
}

void	sa(t_stack *a)
{
	if (!a || !a->head || !a->head->next)
		return ;
	swap_nodes(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (!b || b->head == NULL || b->head->next == NULL)
		return ;
	swap_nodes(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if ((a && a->head && a->head->next) || (b && b->head && b->head->next))
	{
		swap_nodes(a);
		swap_nodes(b);
		write(1, "ss\n", 3);
	}
}
