#include "../push_swap.h"

static char *join_args(char **av, int ac)
{
   int i;
   char  *argsjoin = NULL;

   i = 1;
   while (i < ac)
   {
      if(is_empty(av[i]))
		{
			argsjoin = NULL;
			write(1, "Error\n", 6);
			exit(1);
		}
      argsjoin = ft_strjoin(argsjoin, av[i]);
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