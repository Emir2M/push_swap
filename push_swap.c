/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:01:07 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/23 19:03:57 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	parse_args(int argc, char **argv, t_stack *stack)
{
	int	i;
	int j;
	char **numbers;
	(void)stack;
	printf("Toplam argc: %d\n", argc);
	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i],' ');
		j = 0;
		while (numbers[j])
		{
			printf("Ayrıştırılan Sayı: %s\n", numbers[j]); 
			j++;
		}
		
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	// if (!parse_args(argc, argv, &a))
	// {
	// 	free_stack(&a);
	// 	write(2, "Error\n", 6);
	// 	return (1);
	// }
	parse_args(argc,argv,&a);
	return (0);
}
