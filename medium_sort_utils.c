/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emirhyil <emirhyil@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:31:32 by emirhyil          #+#    #+#             */
/*   Updated: 2026/11/23 19:51:23 by emirhyil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(int *arr, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
	}
}


void	merge(int *arr, int left, int mid, int right)
{
	int	size;
	int	*temp;
	int	i;
	int	j;
	int	k;

	i = left;
	j = mid + 1;
	k = 0;
	size = right - left + 1;
	temp = malloc(size * sizeof(int));
	if (!temp)
		return ;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
            temp[k] = arr[i];
            i++;
		}
	}
}
