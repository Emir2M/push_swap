/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 15:49:37 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/23 01:22:05 by mmetin           ###   ########.fr       */
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
	count_op(a, OP_PB);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = pop_front(b);
	if (temp == NULL)
		return ;
	add_front(a, temp);
	write(1, "pa\n", 3);
	count_op(a, OP_PA);
}
