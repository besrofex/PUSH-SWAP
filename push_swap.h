/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:36:45 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/23 22:00:30 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <limit>

typedef struct  s_stack
{
    int                 value;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}               t_stack;


// stack management
int	    ft_atoi(const char *str);
void    creat_stack(t_stack **a, char **argv);
void    append_node(t_stack **a, int nbr);
t_list	*ft_lstlast(t_list *lst);

// error management
int     error_sytax(char *str);
void    error_free(t_stack **a, char  **argv);
void    free_stack(t_stack **a);

// main
char	**ft_split(char const *s, char c);


#endif
