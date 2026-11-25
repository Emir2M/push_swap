/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 19:51:51 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/25 20:05:41 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_putnbr(int n)
{
	char	c;

	if (n >= 10)
		bench_putnbr(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

void	bench_putop(char *name, int count)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	write(2, name, i);
	write(2, ": ", 2);
	bench_putnbr(count);
	write(2, "\n", 1);
}

void	bench_print_ops(t_bench *bench)
{
	bench_putop("sa", bench->sa);
	bench_putop("sb", bench->sb);
	bench_putop("ss", bench->ss);
	bench_putop("pa", bench->pa);
	bench_putop("pb", bench->pb);
	bench_putop("ra", bench->ra);
	bench_putop("rb", bench->rb);
	bench_putop("rr", bench->rr);
	bench_putop("rra", bench->rra);
	bench_putop("rrb", bench->rrb);
	bench_putop("rrr", bench->rrr);
	bench_putop("Total", bench->total);
}

void	bench_print_disorder(double disorder)
{
	int	percentage;

	percentage = (int)(disorder * 10000.0 + 0.5);
	write(2, "Disorder: ", 10);
	bench_putnbr(percentage / 100);
	write(2, ".", 1);
	if (percentage % 100 < 10)
		write(2, "0", 1);
	bench_putnbr(percentage % 100);
	write(2, "%\n", 2);
}

void	bench_print_strategy(int strategy)
{
	if (strategy == 1)
		write(2, "Strategy: Simple / O(n^2)\n",
			sizeof("Strategy: Simple / O(n^2)\n") - 1);
	else if (strategy == 2)
		write(2, "Strategy: Medium / O(n*sqrt(n))\n",
			sizeof("Strategy: Medium / O(n*sqrt(n))\n") - 1);
	else if (strategy == 3)
		write(2, "Strategy: Complex / O(n log n)\n",
			sizeof("Strategy: Complex / O(n log n)\n") - 1);
}
