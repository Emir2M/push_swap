/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 20:59:02 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/26 02:24:23 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_config(t_config *config)
{
	int	i;

	if (!config)
		return ;
	config->strategy = ADAPTIVE;
	config->bench_mode = 0;
	config->disorder = 0.0;
	config->total_operations = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		config->op_count[i] = 0;
		i++;
	}
}
