#include "push_swap.h"

int   ft_strlen(char *str)
{
   int i;

   i = 0;
   while (str[i])
      i++;
   return (i);
}

int   is_empty(char *str)
{
   int i;

   if (ft_strlen(str) == 0)
      return(1);
   i = 0;
   while (str[i])
   {
      if (str[i] <= 32)
         return (1);
      i++;
   }
   return (0);
}