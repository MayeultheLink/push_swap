#include "push_swap.h"

void insertion_sort(t_stacks* stacks)
{
	while (stacks->a)
	{
		while (stacks->b && stacks->a->content < stacks->b->content)
		{
			cmd_pa(stacks);
			cmd_sa(stacks);
		}
		cmd_pb(stacks);
	}

	while (stacks->b)
	{
		cmd_pa(stacks);
	}
}