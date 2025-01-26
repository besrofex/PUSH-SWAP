/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:13:59 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/26 20:29:16 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *small_value(t_stack *node)
{
    int     min;
    t_stack *small;

    if (node == NULL)
        return (NULL);
    min = INT_MAX;
    while (node)
    {
        if (node->value <= min)
        {
            small = node;
            min = node->value;
        }
        node = node->next;
    }
    return (small);
}