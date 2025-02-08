/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:59:10 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 16:54:12 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	error_sytax(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (is_number(str[1]) == 0)
			return (1);
		i++;
	}
	while (str[i])
	{
		if (is_number(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	error_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
