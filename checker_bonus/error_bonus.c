/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:42:28 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 18:43:45 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_matrix(char **str)
{
	int	i;

	if (str == NULL || *str == NULL)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	error_free(t_stack **a, char **argv, bool checker)
{
	free_stack(a);
	if (checker)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
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

int	error_sytax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	free_stack(t_stack **a)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = *a;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*a = NULL;
}
