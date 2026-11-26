/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 22:17:15 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/26 02:51:07 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

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
	config.disorder = compute_disorder(&a);
	execute_sort(&a, &b, &config);
	print_bench(&config);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
