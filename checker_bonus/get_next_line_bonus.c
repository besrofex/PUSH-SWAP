/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:42:00 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 18:42:00 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*ft_update(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	if (i == j)
		return (free(str), NULL);
	j++;
	tmp = ft_strdup(str + j);
	return (free(str), tmp);
}

static char	*get_line(char *str)
{
	int		i;
	char	*line;

	if (!(*str) || !str)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[++i] = '\0';
	return (line);
}

static char	*creat_array(char *str, int fd)
{
	size_t		read_count;
	char		*tmp;

	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	read_count = read(fd, tmp, BUFFER_SIZE);
	if (!str)
		str = ft_init(NULL);
	while (read_count > 0)
	{
		str = ft_strjoin(str, tmp, read_count);
		if (found_newline(tmp))
			break ;
		read_count = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*reserve;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > INT_MAX)
		return (free(reserve), reserve = NULL, NULL);
	reserve = creat_array(reserve, fd);
	if (!reserve)
		return (free(reserve), reserve = NULL, NULL);
	line = get_line(reserve);
	if (!line)
		return (free(reserve), reserve = NULL, NULL);
	reserve = ft_update(reserve);
	return (line);
}
