/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:37:23 by asadanow          #+#    #+#             */
/*   Updated: 2022/12/01 18:09:01 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_strings(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			count++;
		}
		while (str[i] == c && str[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_dup_string(int i, int j, char *dest, char const *str)
{
	int	pos;

	pos = 0;
	while (j < i)
	{
		dest[pos] = str[j];
		j++;
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

static void	ft_secure_malloc(char **dest, int pos, int i, int j)
{
	dest[pos] = malloc(sizeof(char) * (i - j + 1));
	if (!dest[pos])
	{
		while (pos-- > 0)
			free(dest[pos]);
		free(dest);
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		pos;
	char	**dest;

	i = 0;
	pos = 0;
	dest = malloc(sizeof(char *) * (ft_count_strings(s, c) + 1));
	if (!dest)
		return (NULL);
	while (pos < (ft_count_strings(s, c)))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		ft_secure_malloc(dest, pos, i, j);
		if (!dest)
			return (NULL);
		ft_dup_string(i, j, dest[pos], s);
		pos++;
	}
	dest[pos] = 0;
	return (dest);
}
