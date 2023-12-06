#include "push_swap.h"

t_stack insertion_sort(t_stack stacks)
{

	while (stacks.a)
	{
		while (stacks.b && stacks.a->content < stacks.b->content)
		{
			stacks = cmd_pa(stacks);
			stacks = cmd_sa(stacks);
		}
		stacks = cmd_pb(stacks);
	}

	while (stacks.b)
	{
		stacks = cmd_pa(stacks);
	}

	return (stacks);
}
