/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 18:53:54 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 19:08:49 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b)
{
	double	disorder;

	if (!a || !b || a->size < 2)
		return ;
	disorder = compute_disorder(a);
	if (disorder == 0.0)
		return ;
	if (disorder < 0.2)
		simple_sort(a, b);
	if (disorder < 0.5)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}
