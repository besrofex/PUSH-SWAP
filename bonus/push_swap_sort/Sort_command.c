/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:28:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 14:34:37 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	check_sort(t_stack *a)
{
	int	i;
	int	size;

	i = 1;
	if (a == NULL)
		return (1);
	size = ft_lstsize(a);
	while (a->next)
	{
		if (a->value < a->next->value)
			i++;
		a = a->next;
	}
	if (i == size)
		return (1);
	return (0);
}

void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
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
	if (min_position(a) == 1)
		ra(a);
	else if (min_position(a) == 2)
	{
		rra(a);
		rra(a);
	}
	else if (min_position(a) == 3)
		rra(a);
	pb(b, a);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack*	min;

	min = small_value(*a);
	while (*a != min)
	{
		if (min_position(a) < ft_lstsize(*a) / 2)
			ra(a);
		else
			rra(a);	
	}
	pb(b, a);
	sort_4(a, b);
	pa(a, b);
	pa(a, b);
}
