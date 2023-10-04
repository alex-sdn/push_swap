/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:17 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/16 16:11:31 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_format(int ac, char **av, int i)
{
	int	j;

	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] == '-' && j == 0)
				j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		if (j == 0)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stx)
{
	int	i;
	int	j;

	i = 0;
	while (i < stx->size)
	{
		j = i;
		while (j-- > 0)
			if (stx->a[j] == stx->a[i])
				return (1);
		i++;
	}
	return (0);
}

int	check_int_max(t_stack *stx, int ac, char **av, char **args)
{
	char	*nbr;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	if (ac == 2)
		return (check_int_max_2(stx, args));
	else
	{
		while (++i < ac)
		{
			nbr = ft_itoa(stx->a[i - 1]);
			len1 = ft_strlen(av[i]);
			len2 = ft_strlen(nbr);
			if (len2 != no_zero_strlen(av[i]))
				return (free(nbr), 1);
			while (len2-- > 0)
				if (av[i][--len1] != nbr[len2] && nbr[len2] != '-')
					return (free(nbr), 1);
			free(nbr);
		}
	}
	return (0);
}

int	check_int_max_2(t_stack *stx, char **args)
{
	char	*nbr;
	int		len1;
	int		len2;
	int		args_count;
	int		i;

	i = -1;
	args_count = 0;
	while (args[args_count] != 0)
		args_count++;
	while (++i < args_count)
	{
		nbr = ft_itoa(stx->a[i]);
		len1 = ft_strlen(args[i]);
		len2 = ft_strlen(nbr);
		if (len2 != no_zero_strlen(args[i]))
			return (free(nbr), 1);
		while (len2-- > 0)
			if (args[i][--len1] != nbr[len2] && nbr[len2] != '-')
				return (free(nbr), 1);
		free(nbr);
	}
	free_args(args);
	return (0);
}

int	no_zero_strlen(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (s[i] == '-')
	{
		i++;
		len++;
	}
	while (s[i] == '0' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		i++;
		len++;
	}
	return (len);
}
