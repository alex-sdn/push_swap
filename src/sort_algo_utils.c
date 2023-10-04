/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:10:53 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 17:10:54 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stx)
{
	int	i;

	i = 0;
	if (stx->top_a != stx->size && stx->top_b != stx->size)
		return (0);
	if (stx->top_a == 0)
	{
		while (i < stx->size - 1)
		{
			if (stx->a[i] > stx->a[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i < stx->size - 1)
		{
			if (stx->b[i] > stx->b[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int	check_sorted_b(t_stack *stx)
{
	int	i;

	i = stx->top_b;
	while (i < stx->size - 1)
	{
		if (stx->b[i] > stx->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	fix_order(t_stack *stx, int pos_lowest)
{
	int	i;
	int	low;

	i = stx->size - 1;
	low = get_lowest_a(stx, stx->size);
	while (stx->a[i] != low)
		i--;
	i = pos_lowest - i;
	while (i-- > 0)
		rra(stx);
}

int	get_median_a(t_stack *stx, int pos_lowest)
{
	int	median;
	int	exp_size;

	exp_size = (pos_lowest - stx->top_a) / 2;
	median = get_lowest_a(stx, pos_lowest);
	while (exp_size > 0)
	{
		median = get_next_up(stx, median, stx->a[stx->size - 1]);
		exp_size--;
	}
	return (median);
}

int	get_median_b(t_stack *stx)
{
	int	median;
	int	exp_size;

	exp_size = (stx->size - stx->top_b) / 2;
	if ((stx->size - stx->top_b) % 2 != 0)
		exp_size++;
	median = get_lowest_b(stx);
	while (exp_size > 0)
	{
		median = get_next_up_b(stx, median);
		exp_size--;
	}
	return (median);
}
