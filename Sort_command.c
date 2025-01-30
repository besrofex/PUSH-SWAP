/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:28:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 15:15:11 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sort(t_stack *a)
{
	if (a == NULL)
		return (1);
    while(a->next)
    {
        if  (a->value < a->next->value)
            return (1);
        a = a->next;
    }
    return (0);
}

static t_stack	*find_highest(t_stack *head)
{
	int		hightest;
	t_stack	*hight_node;
	
	if (head == NULL)
		return (NULL);
	hightest = INT_MIN;
	while (head)
	{
		if (head->value > hightest)
		{
			hightest = head->value;
			hight_node = head;
		}
		head = head->next;
	}
	return (hight_node);
}

void	Quick_sort(t_stack **a)
{
	t_stack	*max;

	max = find_highest(*a);
	if (*a == max)
		ra(a, false);
	else if ((*a)->next == max)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	handle_five(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, small_value(*a), 'a');
		pb(b, a, false);
	}
}