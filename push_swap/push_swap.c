/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:48:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/25 22:00:00 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void hhh(t_stack **a, t_stack **b)
// {
// 	t_stack	*push_node;
// 	t_stack	*last_node;
	
// 	while (*b)
// 	{
// 		*b = (*b)->next;
// 		push_node = (*b)->prev; 
// 		while (*a)
// 		{
// 			if (push_node->value > (*a)->value)
// 			{}
// 			else
// 			{
// 				// last_node = ft_lstlast(*a);
// 				// last_node->next = push_node;
// 				// push_node->prev = last_node;
// 				append_node(&a,(*b)->value);
// 				ra(&a);
// 			}
// 			*a = (*a)->next;
// 		}
// 		*b = (*b)->next;
// 	}
// }


static void	set_curr_pos(t_stack *stack)
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
	
}


void	push_swap(t_stack	**a, t_stack	**b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	while (len_a-- > 3)
		pb(&b,&a);
	Quick_sort(&a);
}