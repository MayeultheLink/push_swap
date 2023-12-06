#include "push_swap.h"

t_stack bubble_sort(t_stack stacks)
{
	while (!is_sorted(stacks.a))
	{
		while (stacks.a->next)
		{
			if (stacks.a->content > stacks.a->next->content)
				stacks = cmd_sa(stacks);
			stacks = cmd_pb(stacks);
		}
		while (stacks.b->next)
		{
			if (stacks.b->content < stacks.b->next->content)
				stacks = cmd_sb(stacks);
			stacks = cmd_pa(stacks);
		}
		stacks = cmd_pa(stacks);
	}

	return stacks;
}
