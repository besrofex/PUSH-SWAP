/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:28:34 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/22 20:28:34 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	int	i;
	int	count;
	int	len;
	char	*next_str;

	i = 0;
	count = 0;
	len = 0;
	while (*str == c)
		count++;
	while ((str[count + len] != c) && str[count + len])
		len++;
	next_str= malloc(sizeof(char) *(len+ 1));
	if (!next_str)
		return (NULL);
	while ((str[count] != c) && str[count])
		next_str[i++] = str[count++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int 	words_nbr;
	int		i;

	i = 0;
	words_nbr = count_words(str, c);
	if (!words_nbr)
		exit(1);
	arr = malloc(sizeof(char *) * (words_nbr + 2));
	if (!arr)
		return (NULL);
	while (0 <= words_nbr--)
	{
		if (i == 0)
		{
			arr[i] = malloc(sizeof(char));
			if (!arr)
				return (NULL);
			arr[i++] = '\0';
			continue;
		}
		arr[i++] = get_next_word(str, c);
	}
	arr[i] = '\0';
	return (arr);
}
