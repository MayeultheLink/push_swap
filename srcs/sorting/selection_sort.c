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

void selection_sort(t_stacks* stacks)
{
	while (stacks->a)
	{
		rotate_to_find_value_in_a(stacks, min_value_in_stack(stacks->a));
		cmd_pb(stacks);
	}
	while (stacks->b)
		cmd_pa(stacks);
}