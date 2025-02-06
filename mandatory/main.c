/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:37:08 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/06 16:55:48 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
		printf("----->0");
	if (argc > 1)
	{
		printf("----->1");
		parse(&a, argv, argc);
		printf("----->2");
		sort(&a, &b);
		printf("----->3");
		free_stack(&a);
	}
	return (0);
}
