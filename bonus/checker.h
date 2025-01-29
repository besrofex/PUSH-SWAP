/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:08:51 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/27 21:48:16 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../push_swap.h"

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2, int size);
size_t		ft_strlen(char *str);
char		*ft_strdup(char *s);
int			found_newline(char	*str);
char		*ft_init(char *str);
int         main(int argc, char **argv);

#endif
