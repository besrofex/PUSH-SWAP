/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:23:29 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 17:23:55 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;

	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = NULL;
	if (*dest == NULL)
		*dest = push_node;
	else
	{
		push_node->next = (*dest);
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
