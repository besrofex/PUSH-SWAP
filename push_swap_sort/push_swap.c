/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:48:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/26 21:29:34 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (!(stack->cheapest))
		{
			return(stack);
		}
		stack = stack->next;
	}
	return (NULL);
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	set_curr_pos(*a);
	set_curr_pos(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	set_curr_pos(*a);
	set_curr_pos(*b);
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
	if (cheapest_node->above && cheapest_node->target_node->above)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above) && !(cheapest_node->target_node->above))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pb(b, a, false);
}


void	push_swap(t_stack	**a, t_stack **b)
{
	int		len_a;
	t_stack	*small;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !check_sort(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !check_sort(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !check_sort(*a))
	{
		init_nodes(*b, *a);
		move_nodes(b, a);
	}
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