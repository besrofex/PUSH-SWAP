/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:18:34 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/25 16:38:51 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack *last_node;
	
	last_node = ft_lstlast(*head);
	*head = (*head)->next;
	last_node->next = (*head)->prev;
	(*head)->prev->prev = last_node;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_stack **a)
{
	rotate(&a);
	write(1,"ra\n",3);
}

void	rb(t_stack **b)
{
	rotate(&b);
	write(1,"rb\n",3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(&a);
	rotate(&b);
	write(1,"rra\n",4);
}