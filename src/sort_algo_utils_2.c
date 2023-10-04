/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:10:43 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 17:10:45 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lowest_a(t_stack *stx, int pos_lowest)
{
	int	i;
	int	low;

	i = stx->top_a;
	low = stx->a[i];
	while (++i < pos_lowest)
	{
		if (stx->a[i] < low)
			low = stx->a[i];
	}
	return (low);
}

int	get_lowest_b(t_stack *stx)
{
	int	i;
	int	low;

	i = stx->top_b;
	low = stx->b[i];
	while (++i < stx->size)
	{
		if (stx->b[i] < low)
			low = stx->b[i];
	}
	return (low);
}

int	get_next_up(t_stack *stx, int nbr, int limit)
{
	int	next;
	int	i;

	i = stx->top_a;
	next = 2147483647;
	while (stx->a[i] != limit)
	{
		if (stx->a[i] > nbr && stx->a[i] < next)
			next = stx->a[i];
		i++;
	}
	if (stx->a[i] == stx->a[stx->size - 1]
		&& stx->a[i] > nbr && stx->a[i] < next)
		next = stx->a[i];
	return (next);
}

int	get_next_up_b(t_stack *stx, int nbr)
{
	int	next;
	int	i;

	i = stx->top_b;
	next = 2147483647;
	while (i < stx->size)
	{
		if (stx->b[i] > nbr && stx->b[i] < next)
			next = stx->b[i];
		i++;
	}
	return (next);
}

int	get_highest_a(t_stack *stx)
{
	int	pos_high1;
	int	pos_high2;
	int	i;

	i = stx->top_a;
	pos_high1 = stx->top_a;
	while (++i < stx->size)
		if (stx->a[i] > stx->a[pos_high1])
			pos_high1 = i;
	if (pos_high1 == stx->size - 1)
		return (rra(stx), stx->a[stx->top_a]);
	if (stx->size - stx->top_a == 5)
	{
		pos_high2 = stx->top_a;
		if (pos_high2 == pos_high1)
			pos_high2++;
		while (i-- > stx->top_a)
			if (stx->a[i] > stx->a[pos_high2] && stx->a[i] < stx->a[pos_high1])
				pos_high2 = i;
		if (pos_high2 < pos_high1)
			return (stx->a[pos_high2]);
	}
	return (stx->a[pos_high1]);
}
