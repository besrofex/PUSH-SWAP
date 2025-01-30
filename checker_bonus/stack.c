/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:09:58 by ylabser           #+#    #+#             */
/*   Updated: 2025/01/30 15:20:05 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void    append_node(t_stack **a, int nbr)
{
    t_stack *new_node;
    t_stack *last_node;

    if (!a)
        return ;
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return ;
    new_node->value = nbr;
    new_node->next = NULL;
    if (*a == NULL)
    {
		new_node->prev= NULL;
      *a = new_node;  
    }
    else
    {
        last_node = ft_lstlast(*a);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

void    creat_stack(t_stack **a, char **argv, bool checker)
{
    long    nbr;
    int     i;

    i = 1;
	 if (*argv == NULL)
	 	return ;
    while (argv[i])
    {
        if (error_sytax(argv[i]))
            error_free(a, argv, checker);
        nbr = ft_atoi(argv[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            error_free(a, argv, checker);
        if (error_repetition(*a, (int)nbr))
            error_free(a, argv, checker);
        append_node(a, (int)nbr);
        i++;
    }
	if (checker)
        free_matrix(argv);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*current;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

int	ft_lstsize(t_stack *lst)
{
	int		count;
	t_stack	*current;

	current = lst;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static int	is_space(char c)
{
	if (c == 32 || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

static int	check_signe(int signe)
{
	if (signe < 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		signe;
	long	nb;
	long	valeur_precedente;

	i = 0;
	nb = 0;
	signe = 1;
	while (is_space(str[i]) == 1)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		valeur_precedente = nb;
		nb = nb * 10 + str[i] - 48;
		if (nb / 10 != valeur_precedente)
			return (check_signe(signe));
		i++;
	}
	return ((int)(nb * signe));
}

static int	count_words(char *s, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*get_next_word(char *str, char c)
{
	int	i;
	int	count;
	int	len;
	char	*next_str;

	i = 0;
	count = 0;
	len = 0;
	while (*str == c)
		count++;
	while ((str[count + len] != c) && str[count + len])
		len++;
	next_str= malloc(sizeof(char) *(len+ 1));
	if (!next_str)
		return (NULL);
	while ((str[count] != c) && str[count])
		next_str[i++] = str[count++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char c)
{
	char	**arr;
	int 	words_nbr;
	int		i;

	i = 0;
	words_nbr = count_words(str, c);
	if (!words_nbr)
		exit(1);
	arr = malloc(sizeof(char *) * (words_nbr + 2));
	if (!arr)
		return (NULL);
	while (0 <= words_nbr--)
	{
		if (i == 0)
		{
			arr[i] = malloc(sizeof(char));
			if (!arr)
				return (NULL);
			arr[i++] = '\0';
			continue;
		}
		arr[i++] = get_next_word(str, c);
	}
	arr[i] = '\0';
	return (arr);
}

