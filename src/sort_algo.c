/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:10:39 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 17:10:39 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo(t_stack *stx, int lowest)
{
	int	limit_up_a;

	partition_a(stx, lowest);
	limit_up_a = stx->a[stx->top_a];
	if (check_sorted(stx) == 1)
		return ;
	lowest -= partition_b(stx);
	while (stx->a[stx->top_a] != limit_up_a)
	{
		partition_a_2(stx, limit_up_a);
		lowest -= partition_b(stx);
	}
	if (check_sorted(stx) == 0)
		sort_algo(stx, lowest);
}

void	partition_a(t_stack *stx, int lowest)
{
	int	median;
	int	exp_size;
	int	count;

	count = 0;
	median = get_median_a(stx, lowest);
	exp_size = (lowest - stx->top_a) / 2;
	if (exp_size < 3)
	{
		sort_rotate_5(stx, lowest);
		return ;
	}
	while (count < exp_size)
	{
		if (stx->a[stx->top_a] < median)
		{
			pb(stx);
			count++;
		}
		else
			ra(stx);
	}
	if (lowest != stx->size)
		fix_order(stx, lowest);
}

int	partition_b(t_stack *stx)
{
	int	median;
	int	exp_size;

	median = get_median_b(stx);
	exp_size = (stx->size - stx->top_b) / 2;
	if (exp_size <= 1)
		return (push_3(stx));
	if ((stx->size - stx->top_b) % 2 != 0)
		exp_size++;
	while ((stx->size - stx->top_b) > exp_size)
	{
		if (stx->b[stx->top_b] >= median)
			pa(stx);
		else
			rb(stx);
	}
	return (partition_b(stx));
}

void	partition_a_2(t_stack *stx, int limit)
{
	int	a;
	int	b;
	int	c;
	int	count;

	a = get_next_up(stx, stx->a[stx->size - 1], limit);
	b = get_next_up(stx, a, limit);
	c = get_next_up(stx, b, limit);
	count = 3;
	while (count > 0 && stx->a[stx->top_a] != limit)
	{
		pb(stx);
		if (stx->b[stx->top_b] == a || stx->b[stx->top_b] == b
			|| stx->b[stx->top_b] == c)
			count--;
	}
}
