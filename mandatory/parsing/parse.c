#include "../push_swap.h"

static char *join_args(char **av, int ac)
{
   int i;
   char  *argsjoin;
   char  *tmp;

   i = 1;
   while (i < ac)
   {
      tmp = argsjoin;
      if(is_empty(av[i]))
		{
			tmp = NULL;
			write(2, "Error\n", 6);
			exit(1);
		}
      argsjoin = ft_strjoin(argsjoin, av[i]);
		tmp = NULL;
      i++;
   }
	return (argsjoin);
}

void  parse(t_stack **a, char **av, int ac)
{
   char *argsjoin;
   char **argssplit;

   argsjoin = join_args(av, ac);
   argssplit = ft_split(argsjoin, ' ');
   free(argsjoin);
   creat_stack(a, argssplit);
   free_matrix(argssplit);
}