/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:04:04 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 14:35:10 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	error_free(t_stack **a, char **str)
{
	free_stack(a);
	free_matrix(str);
	write(2, "Error\n", 6);
	exit(1);
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
