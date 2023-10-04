/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:51 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 16:11:52 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stx)
{
	int	tmp;

	if (stx->size - stx->top_a > 1 && stx->top_a < stx->size)
	{
		tmp = stx->a[stx->top_a];
		stx->a[stx->top_a] = stx->a[stx->top_a + 1];
		stx->a[stx->top_a + 1] = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *stx)
{
	int	tmp;

	if (stx->size - stx->top_b > 1 && stx->top_b < stx->size)
	{
		tmp = stx->b[stx->top_b];
		stx->b[stx->top_b] = stx->b[stx->top_b + 1];
		stx->b[stx->top_b + 1] = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *stx)
{
	sa(stx);
	sb(stx);
}
