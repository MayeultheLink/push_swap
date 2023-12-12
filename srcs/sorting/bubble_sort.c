#include "push_swap.h"

void bubble_sort(t_stacks* stacks)
{
	while (!is_sorted(stacks->a))
	{
		while (stacks->a->next)
		{
			if (stacks->a->content > stacks->a->next->content)
				cmd_sa(stacks);
			cmd_pb(stacks);
		}
		while (stacks->b->next)
		{
			if (stacks->b->content < stacks->b->next->content)
				cmd_sb(stacks);
			cmd_pa(stacks);
		}
		cmd_pa(stacks);
	}
}