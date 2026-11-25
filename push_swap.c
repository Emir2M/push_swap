/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:01:07 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/25 21:01:52 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_number(const char *number)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	if (*number == '-')
		sign = -1;
	if (*number == '+' || *number == '-')
		number++;
	while (*number >= '0' && *number <= '9')
	{
		nb = nb * 10 + (*number - '0');
		number++;
	}
	return (sign * nb);
}
int	is_valid_number(char *number)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	if (*number == '-')
		sign = -1;
	if (*number == '+' || *number == '-')
		number++;
	if (*number < '0' || *number > '9')
		return (0);
	while (*number >= '0' && *number <= '9')
	{
		nb = nb * 10 + *number - '0';
		number++;
	}
	if (*number != '\0')
		return (0);
	nb = sign * nb;
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}
int	parse_args(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		j;
	char	**numbers;
	t_node	*new_node;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		j = 0;
		while (numbers[j])
		{
			if (!is_valid_number(numbers[j]))
				error(stack, numbers);
			new_node = create_node(get_number(numbers[j]));
			if (!new_node)
				error(stack, numbers);
			add_back(stack, new_node);
			j++;
		}
		free_split(numbers);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_config config;
	if (argc < 2)
		return (0);
	init_stack(&a);
	init_stack(&b);
	init_config(&config);
	// if (!parse_args(argc, argv, &a))
	// {
	// 	free_stack(&a);
	// 	write(2, "Error\n", 6);
	// 	return (1);
	// }
	parse_args(argc, argv, &a);
	return (0);
}
