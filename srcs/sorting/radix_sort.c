#include "push_swap.h"

int how_many_bits_in_int(int i)
{
    int bit = 0;
    for (; i > 0; i /= 2)
        bit++;
    return (bit);
}

void radix_sort(t_stacks* stacks)
{
    int max_bits = how_many_bits_in_int(max_value(stacks->a));
    int size = ft_lstsize(stacks->a);

    for (int i = 0; i < max_bits; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (((stacks->a->content >> i) & 1) == 1)
                cmd_ra(stacks);
            else
                cmd_pb(stacks);
        }
        while (stacks->b)
            cmd_pa(stacks);
    }
}