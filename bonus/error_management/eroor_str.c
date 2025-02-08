/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eroor_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabser <ylabser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:44:53 by ylabser           #+#    #+#             */
/*   Updated: 2025/02/08 14:35:03 by ylabser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void  free_matrix(char **str)
{
   int i;

   i = 0;
   while (str[i])
      i++;
   while (i > 0)
      free(str[i--]);
   free(str[i]);
}

void  ft_error(char *str)
{
   write(2, "Error\n", 6);
   free(str);
   exit(1);
}