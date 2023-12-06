#include "push_swap.h"

int min_value(t_list* stack)
{
	if (!stack)
		return 0;
	int min = stack->content;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return min;
}

int max_value(t_list* stack)
{
	if (!stack)
		return 0;
	int max = stack->content;
	while (stack)
	{
		if (max < stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return max;
}

t_stack divide_a2b(t_stack stacks)
{
	if (!stacks.a || !stacks.a->next)
		return stacks;
	int size = ft_lstsize(stacks.a);
	while (ft_lstsize(stacks.a) > size / 2)
	{
		if (stacks.a->content <= (max_value(stacks.a) - min_value(stacks.a) / 2 + min_value(stacks.a)))
			stacks = cmd_pb(stacks);
		else
			stacks = cmd_ra(stacks);
	}
	return divide_a2b(stacks);
}

t_stack divide_b2a(t_stack stacks)
{
	if (!stacks.b || !stacks.b->next)
		return stacks;
	int size = ft_lstsize(stacks.b);
	while (ft_lstsize(stacks.b) > size / 2)
	{
		if (stacks.b->content <= (max_value(stacks.b) - min_value(stacks.b) / 2 + min_value(stacks.b)))
			stacks = cmd_pa(stacks);
		else
			stacks = cmd_rb(stacks);
	}
	return divide_b2a(stacks);
}

t_stack merge_sort(t_stack stacks)
{
	if (!stacks.a || !stacks.a->next)
		return stacks;

	stacks = divide_a2b(stacks);
	stacks = divide_b2a(stacks);

	return stacks;
}
