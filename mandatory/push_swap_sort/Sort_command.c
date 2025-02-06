/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:28:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/06 16:20:22 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->value < a->next->value)
			return (1);
		a = a->next;
	}
	return (0);
}

void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		ra(a);
}

void	sort_3(t_stack **a)
{
	t_stack	*max;

	max = find_highest(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*tmp;

	min = small_value(*a);
	tmp = (*a)->next;
	if (tmp == min)
		ra(a);
	else if (tmp->next == min)
	{
		rra(a);
		rra(a);
	}
	else
		rra(a);
	pb(b, a);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*min;
	int i;

	min = small_value(*a);
	tmp = (*a)->next;
	i = 5;
	while (i > 0)
	{
		if (*a != min)
		{
			ra(a);
			i--;
		}
	}
	pb(b, a);
	sort_4(a, b);
	pa(a, b);
}
