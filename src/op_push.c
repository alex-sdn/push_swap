/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:10:23 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 16:10:24 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stx)
{
	if (stx->top_b < stx->size)
	{
		stx->top_a -= 1;
		stx->a[stx->top_a] = stx->b[stx->top_b];
		stx->top_b += 1;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stx)
{
	if (stx->top_a < stx->size)
	{
		stx->top_b -= 1;
		stx->b[stx->top_b] = stx->a[stx->top_a];
		stx->top_a += 1;
		write(1, "pb\n", 3);
	}
}
