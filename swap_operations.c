/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 17:12:49 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/22 18:40:04 by emirhyil         ###   ########.fr       */
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
