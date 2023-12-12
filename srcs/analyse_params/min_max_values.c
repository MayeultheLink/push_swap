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