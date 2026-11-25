/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 22:17:15 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/26 02:22:31 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	config;

	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	init_config(&config);
	a.config = &config;
	b.config = &config;
	parse_args(argc, argv, &a, &config);
	free_stack(&a);
	free_stack(&b);
	printf("config %u",config.strategy);
	printf("config bench mode %u",config.bench_mode);

	return (0);
}
