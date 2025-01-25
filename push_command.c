/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:38:30 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/25 18:01:46 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    push(t_stack **dest, t_stack **src)
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
		*dest = push_node;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(&a, &b);
	write(1,"pa\n",3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(&b, &a);
	write(1,"pb\n",3);
}