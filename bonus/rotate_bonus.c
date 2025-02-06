/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:41:06 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 18:44:14 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate(t_stack **head)
{
	t_stack	*last_node;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	last_node = ft_lstlast(*head);
	*head = (*head)->next;
	last_node->next = (*head)->prev;
	(*head)->prev->prev = last_node;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
