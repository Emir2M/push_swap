/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:01:07 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/23 17:08:43 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_args(int argc, char **argv, t_stack *stack)
{
	int	i;

	(void)stack;
	printf("Toplam argc: %d\n", argc);
	i = 1;
	while (i < argc)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
}

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (!parse_args(argc, argv, &a))
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
}