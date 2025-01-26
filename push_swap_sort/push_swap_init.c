/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:07:12 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/26 20:29:56 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_curr_pos(t_stack *stack)
{
	int	centre;
	int	i;

	if (stack == NULL)
		return ;
	centre = ft_lstsize(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->curr_position = i;
		if (stack->curr_position <= centre)
			stack->above = true;
		else
			stack->above = false;
		stack = stack->next;
		i++;
	}
}

static void set_taregt_node(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target_node;
	long		best_value;
	
	curr_a = a;
	while (b)
	{
		best_value = LONG_MAX;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < best_value)
			{
				best_value = curr_a->value;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_value == LONG_MAX)
			b->target_node = small_value(a);
		else
			b->target_node = target_node;
		b = b->next;
	}	
}

static void	set_price(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_lstsize(a);
	b_len = ft_lstsize(b);
	while (b)
	{
		b->push_price = b->curr_position;
		if (!(b->above))
			b->push_price = b_len - (b->curr_position);
		if (b->target_node->above)
			b->push_price += b->target_node->curr_position;
		else
			b->push_price += a_len - (b->target_node->curr_position);
		b = b->next;
	}
}

static void	set_cheapest(t_stack *b)
{
	long		best_value;
	t_stack	*best_node;

	best_value =  LONG_MAX;
	while (b)
	{
		if (b->push_price < best_value)
		{
			best_value = b->push_price;
			best_node = b;
		}
		b = b->next;
	}
	best_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_curr_pos(a);
	set_curr_pos(b);
	set_taregt_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}