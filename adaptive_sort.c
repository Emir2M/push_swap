/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:53:54 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 20:21:57 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b)
{
	double	disorder;
	int		strategy;

	if (!a || !b || a->size < 2)
		return ;
	disorder = compute_disorder(a);
	if (disorder == 0.0)
		return ;
	strategy = select_strategy(MODE_ADAPTIVE, disorder);
	if (strategy == MODE_SIMPLE)
		simple_sort(a, b);
	else if (strategy == MODE_MEDIUM)
		medium_sort(a, b);
	else if (strategy == MODE_COMPLEX)
		complex_sort(a, b);
}
