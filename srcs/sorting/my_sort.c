#include "push_swap.h"

int nbr_of_values_in_range_in_stack(t_list* stack, int min, int max)
{
    int nbr = 0;

    while (stack)
    {
        if (stack->content >= min && stack->content < max)
            ++nbr;
        stack = stack->next;
    }
    return (nbr);
}

int find_nearest_value_in_range(t_list* stack, int min, int max)
{
    int nbr_of_operations_to_find_first = 0;
    int value_of_first;
    int nbr_of_operations_to_find_last = 1;
    int value_of_last;

    t_list* tmp = stack;
    while (tmp)
    {
        if (tmp->content >= min && tmp->content < max)
        {
            value_of_first = tmp->content;
            break;
        }
        ++nbr_of_operations_to_find_first;
        tmp = tmp->next;
    }

    tmp = stack;
    int range = nbr_of_values_in_range_in_stack(stack, min, max);
    while (tmp)
    {
        while (range)
        {
            if (tmp->content >= min && tmp->content < max)
            {
                value_of_last = tmp->content;
                --range;
            }
            tmp = tmp->next;
        }
        ++nbr_of_operations_to_find_last;
        if (tmp)
            tmp = tmp->next;
    }

    if (nbr_of_operations_to_find_first < nbr_of_operations_to_find_last)
        return (value_of_first);
    else
        return (value_of_last);
}

void a2b(t_stacks* stacks, int min, int max)
{
    int range = max - min;
    while (range)
    {
        rotate_to_find_value_in_a(stacks, find_nearest_value_in_range(stacks->a, min, max));
        cmd_pb(stacks);
        --range;
    }
}

void my_sort(t_stacks* stacks)
{
    int size = ft_lstsize(stacks->a);
    int min = 0;

    for (int i = 0; i < 5; i++)
    {
        a2b(stacks, min, min + (size / 5));
        min += size / 5;
    }
    while (stacks->a)
    {
        cmd_pb(stacks);
    }

    while (stacks->b)
    {
        rotate_to_find_value_in_b(stacks, ft_lstsize(stacks->b) - 1);
        cmd_pa(stacks);
    }
}