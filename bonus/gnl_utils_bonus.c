/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:42:14 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 18:42:14 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	found_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	int		len;
	char	*buffer;

	len = ft_strlen(s1) + size;
	buffer = malloc(len + 1);
	if (!buffer || !s2)
		return (NULL);
	if (!s1)
		s1 = ft_init(NULL);
	i = -1;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	j = 0;
	while (s2[j] != '\0' && j < size)
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	free(s1);
	return (buffer);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_init(char *str)
{
	char	*buffer;

	if (!str)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
		return (buffer);
	}
	return (str);
}
