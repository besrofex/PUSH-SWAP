/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:44:40 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 17:14:47 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;

	i = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	arr = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!arr)
		return (NULL);
	while (*s1)
		arr[i++] = *(s1++);
	arr[i++] = ' ';
	while (*s2)
		arr[i++] = *(s2++);
	arr[i] = '\0';
	return (arr);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_empty(char *str)
{
	int	i;
	int	count;

	if (ft_strlen(str) == 0)
		return (1);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] <= 32)
			count++;
		i++;
	}
	if (count == ft_strlen(str))
		return (1);
	return (0);
}
