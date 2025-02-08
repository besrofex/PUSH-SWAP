/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:28:34 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 16:35:27 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (count);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*copy(char const *start, char const *end)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(end - start + 1);
	if (!copy)
		return (NULL);
	while (start < end)
		copy[i++] = *start++;
	copy[i] = '\0';
	return (copy);
}

static char	**free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		i++;
	while (i > 0)
		free(splitted[--i]);
	free(splitted);
	return (NULL);
}

static char	**allocate(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (NULL);
	splitted = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char			**splitted;
	char const		*start;
	int				i;

	splitted = allocate(s, c);
	if (!splitted)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			start = s;
			while (*s && *s != c)
				s++;
			splitted[i++] = copy(start, s);
			if (!splitted[i - 1])
				return (free_splitted(splitted));
		}
	}
	splitted[i] = NULL;
	return (splitted);
}
