/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:20:31 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 17:22:42 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ra(t_stack **a, bool checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rra\n", 4);
}
