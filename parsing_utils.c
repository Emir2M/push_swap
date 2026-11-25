/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 22:17:31 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/25 22:17:32 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

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

int	has_duplicate(t_stack *stack, int num)
{
	t_node	*curr;

	if (!stack || !stack->head)
		return (0);
	curr = stack->head;
	while (curr)
	{
		if (curr->value == num)
			return (1);
		curr = curr->next;
	}
	return (0);
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
	return (1);
}
