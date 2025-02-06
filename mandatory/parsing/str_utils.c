#include "../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	arr = (char *) malloc (sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (NULL);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	return (arr);
}

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
