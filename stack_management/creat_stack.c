/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:41:40 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/24 19:28:28 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    creat_stack(t_stack **a, char **argv)
{
    long    nbr;
    int     i;

    i = 1;
    while (argv[i])
    {
        if (error_sytax(argv[i]))
            error_free(a, argv);
        nbr = ft_atoi(argv[i]);
        if (nbr < INT_MAX || nbr > INT_MAX)
            error_free(a, argv);
        if (error_repetition(*a, (int)nbr))
            error_free(a, argv);
        append_node(a, (int)nbr);
        i++;
    }
}