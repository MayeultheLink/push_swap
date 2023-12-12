#include "push_swap.h"

void rotate_to_find_value_in_a(t_stacks* stacks, int value)
{
    t_list* list = stacks->a;
    int value_index = 0;

    while (list && list->content != value)
    {
        list = list->next;
        ++value_index;
    }

    if (value_index > ft_lstsize(stacks->a) / 2)
    {
        while (stacks->a->content != value)
            cmd_rra(stacks);
    }
    else
    {
        while (stacks->a->content != value)
            cmd_ra(stacks);
    }
}

void rotate_to_find_value_in_b(t_stacks* stacks, int value)
{
    t_list* list = stacks->b;
    int value_index = 0;

    while (list && list->content != value)
    {
        list = list->next;
        ++value_index;
    }

    if (value_index > ft_lstsize(stacks->b) / 2)
    {
        while (stacks->b->content != value)
            cmd_rrb(stacks);
    }
    else
    {
        while (stacks->b->content != value)
            cmd_rb(stacks);
    }
}