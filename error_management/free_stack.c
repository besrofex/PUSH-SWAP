/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:07:07 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/23 22:00:30 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack **a)
{
    t_stack *curr;
    t_stack *tmp;

    curr = *a;
    while (curr)
    {
        tmp = curr->next;
        free(curr);
        curr = tmp
    }
    *a = NULL;
}