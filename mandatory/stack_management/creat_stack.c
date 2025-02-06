/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:41:40 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/06 20:58:28 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	index(t_stack *a, t_stack *b)
{
	if (a->value > b->value)
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
	new_node->curr_position = 0;
	new_node->next = NULL;
	if (!(*a))
	{
		*a = new_node;
		return ;
	}
	while (tmp->next)
	{
		index(tmp, new_node);
		tmp = tmp->next;
	}
	index(tmp, new_node);
	tmp->next = new_node;
}

void	creat_stack(t_stack **a, char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (error_sytax(str[i]) == 1)
			error_free(a, str);
		if (ft_atoi(str[i]) < INT_MIN || ft_atoi(str[i]) > INT_MAX)
			error_free(a, str);
		if (error_repetition(*a, ft_atoi(str[i])))
			error_free(a, str);
		append_node(a, (int)ft_atoi(str[i]));
		i++;
	}
}
