#include "push_swap.h"

int min_value_in_stack(t_list* stack)
{
	int min = stack->content;

	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return min;
}

t_stack selection_sort(t_stack stacks)
{
	while (stacks.a)
	{
		int min = min_value_in_stack(stacks.a);
		while (stacks.a && stacks.a->content != min)
			stacks = cmd_ra(stacks);
		stacks = cmd_pb(stacks);
	}
	while (stacks.b)
		stacks = cmd_pa(stacks);
	return stacks;
}
