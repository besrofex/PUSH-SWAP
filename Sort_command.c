/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:28:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/25 16:31:36 by ylabser          ###   ########.fr       */
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

// static t_stack	*highest_node(t_stack *a)
// {
// 	int	max;
// 	t_stack	*hight_node;

// 	if (!a)
// 		return (NULL);
// 	max = INT_MIN;
// 	while(a)
// 	{
// 		if (a->value > max)
// 		{
// 			max = a->value;
// 			hight_node = a;
// 		}
// 		a = a->next;
// 	}
// 	return (hight_node);
// }

static	t_stack *small_value(t_stack *node)
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

void	Quick_sort(t_stack **a)
{
	t_stack	*min;

	min = small_value(*a);
	if (*a == min)
		ra(&a);
	else if ((*a)->next == min)
		rra(&a);
	if ((*a)->value < (*a)->next->value)
		sa(&a);
}