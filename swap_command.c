/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:02:59 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/26 21:24:47 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	int	len;

	len = ft_lstsize(*head);
	if (len == 1 || head == NULL || *head == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->next = (*head)->next;
	(*head)->prev->prev = (*head);
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void    sa(t_stack **a, bool checker)
{
   swap(a);
	if (!checker)
		write(1,"sa\n",3);
}

void    sb(t_stack **b, bool checker)
{
   swap(b);
	if (!checker)
		write(1,"sb\n",3);
}

void    ss(t_stack **b, t_stack **a, bool checker)
{
	swap(a);
   swap(b);
	if (!checker)
		write(1,"ss\n",3);
}
