#include "push_swap.h"

void    sa(t_stack **a)
{
    t_stack *fisrt_node;

    fisrt_node = *a;
    a->next->prev = NULL;
}