/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:41:21 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 18:44:10 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*last_node;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	last_node = ft_lstlast(*head);
	last_node->next = *head;
	(*head)->prev = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*head = last_node;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
