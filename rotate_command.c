/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:18:34 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/27 12:39:30 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack *last_node;
	
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
		write(1,"ra\n",3);
}

void	rb(t_stack **b, bool checker)
{
	rotate(b);
	if (!checker)
		write(1,"rb\n",3);
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1,"rra\n",4);
}
