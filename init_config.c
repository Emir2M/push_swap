/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 20:59:02 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/25 21:04:23 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_config(t_config *config)
{
	if (!config)
		return ;
	config->strategy = ADAPTIVE;
	config->bench_mode = 0;
	config->disorder = 0.0;
	config->total_operations = 0;
}
