/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:01:07 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/25 22:04:09 by mmetin           ###   ########.fr       */
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
int	handle_flag(char *str, t_config *config)
{
	if (!ft_strcmp(str, "--simple"))
		config->strategy = SIMPLE;
	else if (!ft_strcmp(str, "--medium"))
		config->strategy = MEDIUM;
	else if (!ft_strcmp(str, "--complex"))
		config->strategy = COMPLEX;
	else if (!ft_strcmp(str, "--adaptive"))
		config->strategy = ADAPTIVE;
	else if (!ft_strcmp(str, "--bench"))
		config->bench_mode = 1;
	else
		return (0);
	return 1;
}
int	parse_args(int argc, char **argv, t_stack *stack, t_config *config)
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
			printf("argv[%d] : %s\n", j, numbers[j]);
			if (numbers[j][0] == '-' && numbers[j][1] == '-')
			{
				if (!handle_flag(numbers[j], config))
					error(stack, numbers);
				j++;
				continue ;
			}
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
	t_stack		a;
	t_stack		b;
	t_config	config;

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
	parse_args(argc, argv, &a, &config);
	return (0);
}
