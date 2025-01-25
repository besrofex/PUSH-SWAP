/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:21:23 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/25 15:48:28 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack	**head)
{
	t_stack	*last_node;

	last_node = ft_lstlast(*head);
	last_node->next = *head;
	(*head)->prev = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*head = last_node;
}

void	rra(t_stack **a)
{
	reverse_rotate(&a);
	write(1,"rra\n",4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(&b);
	write(1,"rrb\n",4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(&a);
	reverse_rotate(&b);
	write(1,"rrr\n",4);
}