/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:35:47 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/23 22:00:30 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    append_node(t_stack **a, int nbr)
{
    t_stack *new_node;
    t_stack *last_node;

    if (!a)
        return ;
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return ;
    new_node->value = nbr;
    new_node->next = NULL;
    if (*a == NULL)
    {
        *a = new_node;
        new_node->prev= NULL;
    }
    else
    {
        last_node = ft_lstlast(*a);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}