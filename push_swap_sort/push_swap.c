/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:48:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/29 20:37:42 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return(stack);
		stack = stack->next;
	}
	return (NULL);
}

static void	finish_rotation(t_stack **stack, t_stack *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->above)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (node->above)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		len_a;
	t_stack	*small;

	len_a = ft_lstsize(*a);
	while (len_a-- > 3)
		pb(b, a, false);
	Quick_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_curr_pos(*a);
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
