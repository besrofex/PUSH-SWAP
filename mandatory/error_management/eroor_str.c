#include "../push_swap.h"

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