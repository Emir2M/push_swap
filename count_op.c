/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 02:25:06 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/26 02:26:14 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_op(t_stack *stack, t_op op)
{
	if (!stack || !stack->config)
		return ;
	stack->config->op_count[op]++;
	stack->config->total_operations++;
}
