/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 22:17:24 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/25 22:21:23 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

static void	validate_args(t_stack *stack, t_config *config, char **numbers)
{
	int		j;
	int		num;
	t_node	*new_node;

	j = 0;
	while (numbers[j])
	{
		if (numbers[j][0] == '-' && numbers[j][1] == '-')
		{
			if (!handle_flag(numbers[j], config))
				error(stack, numbers);
			j++;
			continue ;
		}
		if (!is_valid_number(numbers[j]))
			error(stack, numbers);
		num = get_number(numbers[j]);
		if (has_duplicate(stack, num))
			error(stack, numbers);
		new_node = create_node(num);
		if (!new_node)
			error(stack, numbers);
		add_back(stack, new_node);
		j++;
	}
}

int	parse_args(int argc, char **argv, t_stack *stack, t_config *config)
{
	int		i;
	char	**numbers;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		validate_args(stack, config, numbers);
		free_split(numbers);
		i++;
	}
	return (1);
}
