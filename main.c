/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:37:08 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/24 19:28:28 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack    *a;
    t_stack    *b;

    a = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    creat_stack(&a, argv + 1);
    if (!check_sort(a))
    {
        if (ft_lstsize(a) == 2)
            sa(&a);
        else if (ft_lstsize(a) == 3)
            Quick_sort(&a);
        else
            push_swap(&a, &b);
    }
}
