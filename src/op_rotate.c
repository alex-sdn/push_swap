/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:10:27 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 16:13:21 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stx)
{
	int	tmp;
	int	i;

	if (stx->top_a < stx->size)
	{
		i = stx->top_a;
		tmp = stx->a[stx->top_a];
		while (i < stx->size - 1)
		{
			stx->a[i] = stx->a[i + 1];
			i++;
		}
		stx->a[i] = tmp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *stx)
{
	int	tmp;
	int	i;

	if (stx->top_b < stx->size)
	{
		i = stx->top_b;
		tmp = stx->b[stx->top_b];
		while (i < stx->size - 1)
		{
			stx->b[i] = stx->b[i + 1];
			i++;
		}
		stx->b[i] = tmp;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *stx)
{
	ra(stx);
	rb(stx);
}
