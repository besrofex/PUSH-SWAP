/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:44:07 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 16:03:43 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	decide(t_stack **a)
{
	int		count;
	t_stack	*tmp;
	int		size;

	size = ft_lstsize(*a);
	count = 0;
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->curr_position - tmp->next->curr_position <= 4)
			count++;
		tmp = tmp->next;
	}
	if (count * 10 >= 6 * size)
		return (0);
	return (1);
}

void	sort(t_stack **a, t_stack **b)
{
	int	size;
	int	d;

	d = decide(a);
	size = ft_lstsize(*a);
	if (check_sort(*a))
		return ;
	else if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else if (size > 5)
	{
		move_to_b(a, b, d);
		move_to_a(a, b);
	}
}
