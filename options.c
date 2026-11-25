/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 20:17:21 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 20:20:34 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_options(t_options *options)
{
	options->strategy = MODE_ADAPTIVE;
	options->bench = 0;
	options->start = 1;
}

static int	str_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}

static int	set_option(t_options *options, char *arg)
{
	if (str_equal(arg, "--simple"))
		options->strategy = MODE_SIMPLE;
	else if (str_equal(arg, "--medium"))
		options->strategy = MODE_MEDIUM;
	else if (str_equal(arg, "--complex"))
		options->strategy = MODE_COMPLEX;
	else if (str_equal(arg, "--adaptive"))
		options->strategy = MODE_ADAPTIVE;
	else if (str_equal(arg, "--bench"))
		options->bench = 1;
	else
		return (0);
	return (1);
}

int	parse_options(int argc, char **argv, t_options *options)
{
	init_options(options);
	while (options->start < argc)
	{
		if (!set_option(options, argv[options->start]))
			break ;
		options->start++;
	}
	return (1);
}

int	select_strategy(int strategy, double disorder)
{
	if (strategy != MODE_ADAPTIVE)
		return (strategy);
	if (disorder < 0.2)
		return (MODE_SIMPLE);
	if (disorder < 0.5)
		return (MODE_MEDIUM);
	return (MODE_COMPLEX);
}
