#include "push_swap.h"

t_stack divide_a2b_quick(t_stack stacks)
{
	if (!stacks.a || !stacks.a->next)
		return stacks;

	int pivot = ft_lstlast(stacks.a)->content;

	while (stacks.a->content != pivot)
	{
		if (stacks.a->content < pivot)
			stacks = cmd_pb(stacks);
		else
			stacks = cmd_ra(stacks);
	}

	return divide_a2b_quick(stacks);
}

t_stack divide_b2a_quick(t_stack stacks)
{
	if (!stacks.b || !stacks.b->next)
	{
		stacks = cmd_pa(stacks);
		return stacks;
	}

	int pivot = ft_lstlast(stacks.b)->content;

	while (stacks.b->content != pivot)
	{
		if (stacks.b->content > pivot)
			stacks = cmd_pa(stacks);
		else
			stacks = cmd_rb(stacks);
	}

	return divide_b2a_quick(stacks);
}

t_stack quick_sort(t_stack stacks)
{

	stacks = divide_a2b_quick(stacks);
	stacks = divide_b2a_quick(stacks);

	return stacks;
}
