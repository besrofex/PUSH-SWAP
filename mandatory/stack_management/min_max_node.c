/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:13:59 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 16:30:00 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*small_value(t_stack *node)
{
	int		min;
	t_stack	*small;

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

t_stack	*find_highest(t_stack *head)
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
