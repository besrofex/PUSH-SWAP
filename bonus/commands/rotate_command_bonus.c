/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:29:31 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 16:29:33 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last = ft_lstlast(*head);
	tmp = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = tmp;
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
