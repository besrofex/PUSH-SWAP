/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:31:10 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/06 22:30:49 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_space(char c)
{
	if (c == 32 || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

// static int	check_signe(int signe)
// {
// 	if (signe < 0)
// 		return (0);
// 	else
// 		return (-1);
// }

long	ft_atoi(char *str)
{
	int		i;
	int		signe;
	unsigned long long	nb;

	i = 0;
	nb = 0;
	signe = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if(nb>nb*10 + str[i] - '0')
			return LONG_MAX; 
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	return ((long)nb * signe);
}
