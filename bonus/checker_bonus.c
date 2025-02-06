/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:43:08 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 18:43:08 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static void	error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_stack **a, t_stack **b, char *comand)
{
	if (!ft_strcmp(comand, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(comand, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(comand, "sa\n"))
		sa(a);
	else if (!ft_strcmp(comand, "sb\n"))
		sb(b);
	else if (!ft_strcmp(comand, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(comand, "ra\n"))
		ra(a);
	else if (!ft_strcmp(comand, "rb\n"))
		rb(b);
	else if (!ft_strcmp(comand, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(comand, "rra\n"))
		rra(a);
	else if (!ft_strcmp(comand, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(comand, "rrr\n"))
		rrr(a, b);
	else
		error(a, b);
}

static int	check_sort(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if (a->value < a->next->value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*next_ligne;
	int		len;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		parse(&a, argv, argc);
		creat_stack(&a, argv);
		len = ft_lstsize(a);
		next_ligne = get_next_line(STDIN_FILENO);
		while (next_ligne)
		{
			parse_command(&a, &b, next_ligne);
			next_ligne = get_next_line(STDIN_FILENO);
		}
		if (check_sort(a) && ft_lstsize(a) == len)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_stack(&a);
		free_stack(&b);

	}
	return (0);
}
