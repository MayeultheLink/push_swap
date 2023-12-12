#include "push_swap.h"

void divide_b2a(t_stacks* stacks)
{
	if (!stacks->b || !stacks->b->next)
		return ;

	int size = ft_lstsize(stacks->b);
	while (ft_lstsize(stacks->b) > size / 2)
	{
		if (stacks->b->content > ((max_value(stacks->b) - min_value(stacks->b)) / 2 + min_value(stacks->b)))
			cmd_pa(stacks);
		else
			cmd_rb(stacks);
	}
	divide_b2a(stacks);
}

void divide_a2b(t_stacks* stacks)
{
	if (!stacks->a || !stacks->a->next)
		return ;

	int size = ft_lstsize(stacks->a);
	while (ft_lstsize(stacks->a) > size / 2)
	{
		if (stacks->a->content <= ((max_value(stacks->a) - min_value(stacks->a)) / 2 + min_value(stacks->a)))
			cmd_pb(stacks);
		else
			cmd_ra(stacks);
	}
	divide_a2b(stacks);
}

void merge_in_b_with_selection_sort(t_stacks* stacks)
{
	while (!is_sorted(stacks->a))
	{
		rotate_to_find_value_in_a(stacks, min_value(stacks->a));
		cmd_pb(stacks);
	}
}

void merge_in_a_with_selection_sort(t_stacks* stacks)
{
	while (ft_lstsize(stacks->b) > ft_lstsize(stacks->a))
	{
		rotate_to_find_value_in_b(stacks, stacks->a->content - 1);
		cmd_pa(stacks);
	}
}

void merge_sort(t_stacks* stacks)
{
	divide_a2b(stacks);
	merge_in_a_with_selection_sort(stacks);
	divide_b2a(stacks);
	merge_in_b_with_selection_sort(stacks);

	while (stacks->b)
		cmd_pa(stacks);
}