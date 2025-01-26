/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:04:04 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/26 20:37:32 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_matrix(char	**str)
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

void    error_free(t_stack **a, char  **argv)
{
    free_stack(a);
	 free_matrix(argv);
    write(2,"Error\n",6);
    exit(1);
}