/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmetin <mmetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 03:20:00 by mmetin            #+#    #+#             */
/*   Updated: 2026/11/26 03:20:00 by mmetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr_err(const char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

void	putnbr_err(int n)
{
	char	c;

	if (n >= 10)
		putnbr_err(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

void	print_op_err(const char *name, int count, int sep)
{
	putstr_err(name);
	putstr_err(": ");
	putnbr_err(count);
	if (sep == 1)
		putstr_err("  ");
	else if (sep == 2)
		putstr_err("\n[bench] ");
	else
		putstr_err("\n");
}
