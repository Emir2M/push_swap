/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 15:49:37 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/22 18:39:57 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = pop_front(a);
	if (temp == NULL)
		return ;
	add_front(b, temp);
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = pop_front(b);
	if (temp == NULL)
		return ;
	add_front(a, temp);
	write(1, "pa\n", 3);
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
