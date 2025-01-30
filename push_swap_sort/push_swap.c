/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:48:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 17:58:26 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_a(t_stack **a)
{
	t_stack	*small;

	small = small_value(*a);
	if (small->above)
	{
		while (*a != small)
			ra(a, false);
	}
	else
	{
		while (*a != small)
			rra(a, false);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		len_a;

	len_a = ft_lstsize(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	quick_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_curr_pos(*a);
	set_a(a);
}
