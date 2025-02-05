/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:41:40 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 16:43:51 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	index(t_stack *a, t_stack *b)
{
	if (a->curr_position > b->curr_position)
		a->curr_position++;
	else
		b->curr_position++;
}

static void	append_node(t_stack **a, int nbr)
{
	t_stack	*new_node;
	t_stack	*tmp;

	tmp = *a;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = nbr;
	new_node->next = NULL;
	if (tmp == NULL)
		tmp = new_node;
	while (tmp && tmp->next)
	{
		index(tmp, new_node);
		tmp = tmp->next;
	}
	index(tmp, new_node);
	tmp->next = new_node;
}

void	creat_stack(t_stack **a, char *str)
{
	long	nbr;
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(error_sytax(str[i])))
			error_free(a, str);
		if (ft_atoi(str[i]) < INT_MIN || ft_atoi(str[i]) > INT_MAX)
			error_free(a, str);
		if (error_repetition(*a, ft_atoi(str[i])))
			error_free(a, str);
		append_node(a, (int)ft_atoi(str[i]));
		i++;
	}
}
