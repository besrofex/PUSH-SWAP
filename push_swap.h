/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:36:45 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/24 19:28:28 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct  s_stack
{
    int                 value;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}               t_stack;


// stack management
int	    ft_atoi(char *str);
int	    ft_lstsize(t_stack *lst);
int     check_sort(t_stack *a);
t_stack	*ft_lstlast(t_stack *lst);
t_stack *small_value(t_stack *node);
void    creat_stack(t_stack **a, char **argv);
void    append_node(t_stack **a, int nbr);



// error management
int     error_sytax(char *str);
int     error_repetiton(t_stack *a, int nbr);
void    error_free(t_stack **a, char  **argv);
void    free_stack(t_stack **a);


// main
int     main(int argc, char **argv);
char	**ft_split(char *s, char c);
void    push_swap(t_stack **a, t_stack **b);


#endif
