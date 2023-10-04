/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_utils_opti.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:47:16 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/20 15:47:23 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rotate_5(t_stack *stx, int pos_lowest)
{
	int	low;

	if (pos_lowest == stx->size)
	{
		sort_rotate_5_solo(stx);
		return ;
	}
	while (pos_lowest != stx->top_a)
	{
		low = get_lowest_a(stx, pos_lowest);
		if (stx->a[stx->top_a] == get_next_up(stx, low, stx->a[pos_lowest]))
			sa(stx);
		else if (stx->a[stx->top_a] == low && (stx->top_b == stx->size
				|| (stx->b[stx->top_b] > stx->a[stx->top_a]
					&& stx->b[stx->size - 1] > stx->a[stx->top_a])))
		{
			ra(stx);
			pos_lowest--;
		}
		else
			pb(stx);
	}
	if (stx->top_b < stx->size)
		push_3(stx);
}

void	sort_rotate_5_solo(t_stack *stx)
{
	while (stx->size - stx->top_a > 3)
	{
		if (get_highest_a(stx) == stx->a[stx->top_a])
			pb(stx);
		else
			ra(stx);
	}
	if (stx->size - stx->top_b == 2)
		if (stx->b[stx->top_b] > stx->b[stx->top_b + 1])
			sb(stx);
	if (get_lowest_a(stx, stx->size) == stx->a[stx->top_a])
		ra(stx);
	else if (get_lowest_a(stx, stx->size) == stx->a[stx->top_a + 1])
		rra(stx);
	if (stx->a[stx->top_a] > stx->a[stx->top_a + 1])
		sa(stx);
	if (get_lowest_a(stx, stx->size) == stx->a[stx->size - 1])
		rra(stx);
	while (stx->top_b < stx->size)
	{
		pa(stx);
		ra(stx);
	}
}

int	push_3(t_stack *stx)
{
	int	size;

	size = stx->size - stx->top_b;
	if (size < 3)
		return (push_3_small(stx, size));
	else
	{
		if (stx->b[stx->top_b] > stx->b[stx->top_b + 2])
			rb(stx);
		while (stx->top_b < stx->size - 1)
		{
			if (stx->b[stx->top_b] > stx->b[stx->top_b + 1])
				sb(stx);
			pa(stx);
			ra(stx);
		}
		pa(stx);
		ra(stx);
	}
	return (size);
}

int	push_3_small(t_stack *stx, int size)
{
	if (size == 1)
	{
		pa(stx);
		ra(stx);
	}
	else if (size == 2)
	{
		if (stx->b[stx->top_b] > stx->b[stx->top_b + 1])
			rb(stx);
		pa(stx);
		ra(stx);
		pa(stx);
		ra(stx);
	}
	return (size);
}
