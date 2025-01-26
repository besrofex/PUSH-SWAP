/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_repetition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:13:13 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/26 20:32:28 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int error_repetition(t_stack *a, int nbr)
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