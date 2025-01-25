/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:36:45 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/25 21:57:55 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct  s_stack
{
    int              value;
	 int					curr_position;
	 int					push_price;
	 bool					above;
    struct s_stack	*target_node;
    struct s_stack	*next;
    struct s_stack	*prev;
}               t_stack;


// stack management
int	    ft_atoi(char *str);
int	    ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
t_stack *small_value(t_stack *node);
void    creat_stack(t_stack **a, char **argv);
void    append_node(t_stack **a, int nbr);

// sort
void	Quick_sort(t_stack **a);
int	check_sort(t_stack *a);

// error management
int     error_sytax(char *str);
int     error_repetiton(t_stack *a, int nbr);
void    error_free(t_stack **a, char  **argv);
void    free_stack(t_stack **a);

// main
int	main(int argc, char **argv);
char	**ft_split(char *s, char c);
void	push_swap(t_stack **a, t_stack **b);

// swap
void  sa(t_stack **a);
void  sb(t_stack **b);
void  ss(t_stack **b, t_stack **a);

// rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// push

#endif
