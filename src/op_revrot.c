/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:47 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 16:13:04 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stx)
{
	int	tmp;
	int	i;

	if (stx->top_a < stx->size)
	{
		i = stx->size - 1;
		tmp = stx->a[stx->size - 1];
		while (i > stx->top_a)
		{
			stx->a[i] = stx->a[i - 1];
			i--;
		}
		stx->a[stx->top_a] = tmp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *stx)
{
	int	tmp;
	int	i;

	if (stx->top_b < stx->size)
	{
		i = stx->size - 1;
		tmp = stx->b[stx->size - 1];
		while (i > stx->top_b)
		{
			stx->b[i] = stx->b[i - 1];
			i--;
		}
		stx->b[stx->top_b] = tmp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *stx)
{
	rra(stx);
	rrb(stx);
}
