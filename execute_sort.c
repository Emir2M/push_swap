/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 02:51:46 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/26 02:59:34 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_adaptive(t_stack *a, t_stack *b, double disorder)
{
	if (disorder < 0.2)
		simple_sort(a, b);
	else if (disorder < 0.5)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}

void	execute_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (!a || !b || !config || a->size < 2 || config->disorder == 0.0)
		return ;
	if (config->strategy == SIMPLE)
		simple_sort(a, b);
	else if (config->strategy == MEDIUM)
		medium_sort(a, b);
	else if (config->strategy == COMPLEX)
		complex_sort(a, b);
	else
		run_adaptive(a, b, config->disorder);
}
