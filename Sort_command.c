/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:28:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/26 21:25:07 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack *a)
{
	if (a == NULL)
		return (1);
    while(a->next)
    {
        if  (a->value > a->next->value)
            return (1);
        a = a->next;
    }
    return (0);
}

void	Quick_sort(t_stack **a)
{
	t_stack	*min;

	min = small_value(*a); // small_value file (used or not ?????)
	if (*a == min)
		ra(a, false);
	else if ((*a)->next == min)
		rra(a, false);
	if ((*a)->value < (*a)->next->value)
		sa(a, false);
}