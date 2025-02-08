/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:02:59 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 14:35:31 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static void	swap(t_stack **head)
{
	int	tmp;

	if (!head || !(*head)->next)
		return ;
	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	sa(t_stack **a)
{
	swap(a);
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack **b, t_stack **a)
{
	swap(a);
	swap(b);
}
