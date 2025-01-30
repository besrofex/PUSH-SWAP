/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:42:44 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 18:42:44 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				curr_position;
	int				push_price;
	bool			above;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2, int size);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *s);
int			found_newline(char	*str);
char		*ft_init(char *str);
int			main(int argc, char **argv);
void		creat_stack(t_stack **a, char **argv, bool checker);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);

// swap
void		sa(t_stack **a, bool checker);
void		sb(t_stack **b, bool checker);
void		ss(t_stack **b, t_stack **a, bool checker);

// rotate
void		ra(t_stack **a, bool checker);
void		rb(t_stack **b, bool checker);
void		rr(t_stack **a, t_stack **b, bool checker);

// reverse rotate
void		rra(t_stack **a, bool checker);
void		rrb(t_stack **b, bool checker);
void		rrr(t_stack **a, t_stack **b, bool checker);

// push
void		pa(t_stack **a, t_stack **b, bool checker);
void		pb(t_stack **b, t_stack **a, bool checker);

// error
void		free_stack(t_stack **a);
int			error_sytax(char *str);
int			error_repetition(t_stack *a, int nbr);
void		error_free(t_stack **a, char **argv, bool checker);
void		free_matrix(char **str);
int			ft_atoi(char *str);
char		**ft_split(char *str, char c);

#endif
