/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:36:45 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 14:40:30 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int				value;
	int				curr_position;
	struct s_stack	*next;
}					t_stack;

// get_next_line
char	*get_next_line(int fd);
char	*ft_init(char *str);
char	*ft_strdup(char *s);
int	found_newline(char *str);
char	*ft_strnjoin(char *s1, char *s2, int size);

// stack management
void	creat_stack(t_stack **a, char **str);
long			ft_atoi(char *str);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*small_value(t_stack *node);
t_stack	*find_highest(t_stack *head);

// error management
int			error_sytax(char *str);
int			error_repetition(t_stack *a, int nbr);
void	error_free(t_stack **a, char **str);
void		free_stack(t_stack **a);
void		free_matrix(char	**str);
void  ft_error(char *str);

// main
int			main(int argc, char **argv);

// swap
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **b, t_stack **a);

// rotate
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

// reverse rotate
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// push
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);

// sort
void	sort(t_stack **a, t_stack **b);
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	move_to_b(t_stack **a, t_stack **b, int d);
void	move_to_a(t_stack **a, t_stack **b);
int			check_sort(t_stack *a);
int	min_position(t_stack **b);
int	max_position(t_stack **b);

// parsing
void  parse(t_stack **a, char **av, int ac);
char	*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const *s, char c);

// str utils
int   is_empty(char *str);
int   ft_strlen(char *str);

#endif
