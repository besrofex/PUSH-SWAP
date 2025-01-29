/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:41:40 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/29 12:04:50 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void    append_node(t_stack **a, int nbr)
{
    t_stack *new_node;
    t_stack *last_node;

    if (!a) // check that ???????
        return ;
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return ;
    new_node->value = nbr;
    new_node->next = NULL;
    if (*a == NULL)
    {
		new_node->prev= NULL;
      *a = new_node;  
    }
    else
    {
        last_node = ft_lstlast(*a);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

void    creat_stack(t_stack **a, char **argv, bool checker)
{
    long    nbr;
    int     i;

    i = 1;
	 if (*argv == NULL)
	 	return ;
    while (argv[i])
    {
        if (error_sytax(argv[i]))
            error_free(a, argv, checker);
        nbr = ft_atoi(argv[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            error_free(a, argv, checker);
        if (error_repetition(*a, (int)nbr))
            error_free(a, argv, checker);
        append_node(a, (int)nbr);
        i++;
    }
}