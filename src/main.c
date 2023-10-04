/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:41 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 16:11:42 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_exit(t_stack *stx, int i)
{
	if (stx->a)
		free(stx->a);
	if (stx->b)
		free(stx->b);
	free(stx);
	if (i == 1)
		write(2, "Error\n", 6);
	return (NULL);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (args == NULL)
		return ;
	while (args[i] != 0)
	{
		free(args[i]);
		i++;
	}
	free(args[i]);
	free(args);
}

t_stack	*create_stx_mult(int ac, char **av)
{
	int		i;
	t_stack	*stx;

	i = 0;
	if (check_format(ac, av, 1) == 0)
		return (write(2, "Error\n", 6), NULL);
	stx = malloc(sizeof(t_stack));
	if (!stx)
		return (write(2, "Error\n", 6), NULL);
	stx->a = malloc(sizeof(int) * ac - 1);
	stx->b = malloc(sizeof(int) * ac - 1);
	if (!stx->a || !stx->b)
		return (free_exit(stx, 1));
	stx->size = ac - 1;
	stx->top_a = 0;
	stx->top_b = ac - 1;
	while (++i < ac)
		stx->a[i - 1] = ft_atoi(av[i]);
	return (stx);
}

t_stack	*create_stx_2(char **args)
{
	int		i;
	int		j;
	t_stack	*stx;

	i = 0;
	j = 0;
	while (args[j] != 0)
		j++;
	if (check_format(j, args, 0) == 0)
		return (write(2, "Error\n", 6), NULL);
	stx = malloc(sizeof(t_stack));
	if (!stx)
		return (write(2, "Error\n", 6), NULL);
	stx->a = malloc(sizeof(int) * j);
	stx->b = malloc(sizeof(int) * j);
	if (!stx->a || !stx->b)
		return (free_exit(stx, 1));
	stx->size = j;
	stx->top_a = 0;
	stx->top_b = j;
	while (i++ < j)
		stx->a[i - 1] = ft_atoi(args[i - 1]);
	return (stx);
}

int	main(int ac, char **av)
{
	char	**args;
	t_stack	*stx;

	args = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (args == NULL)
			return (write(2, "Error\n", 6), 1);
		stx = create_stx_2(args);
	}
	else
		stx = create_stx_mult(ac, av);
	if (stx == NULL)
		return (free_args(args), 1);
	if (check_duplicates(stx) == 1 || check_int_max(stx, ac, av, args) == 1)
		return (free_exit(stx, 1), free_args(args), 1);
	if (check_sorted(stx) == 0)
		sort_algo(stx, stx->size);
	free_exit(stx, 0);
	return (0);
}
