#include "push_swap.h"

void divide_a2b_quick(t_stacks* stacks)
{
	if (!stacks->a || !stacks->a->next)
		return ;

	int pivot = ft_lstlast(stacks->a)->content;

	while (stacks->a->content != pivot)
	{
		if (stacks->a->content < pivot)
			cmd_pb(stacks);
		else
			cmd_ra(stacks);
	}

	return divide_a2b_quick(stacks);
}

void divide_b2a_quick(t_stacks* stacks)
{
	if (!stacks->b || !stacks->b->next)
	{
		cmd_pa(stacks);
		return ;
	}

	int pivot = ft_lstlast(stacks->b)->content;

	while (stacks->b->content != pivot)
	{
		if (stacks->b->content > pivot)
			cmd_pa(stacks);
		else
			cmd_rb(stacks);
	}

	return divide_b2a_quick(stacks);
}

void merge_in_b_with_selection_sort_quick(t_stacks* stacks)
{
	while (!is_sorted(stacks->a))
	{
		rotate_to_find_value_in_a(stacks, min_value(stacks->a));
		cmd_pb(stacks);
	}
}

void merge_in_a_with_selection_sort_quick(t_stacks* stacks)
{
	while (ft_lstsize(stacks->b) > ft_lstsize(stacks->a))
	{
		rotate_to_find_value_in_b(stacks, stacks->a->content - 1);
		cmd_pa(stacks);
	}
}

void quick_sort(t_stacks* stacks)
{
	divide_a2b_quick(stacks);
	merge_in_a_with_selection_sort_quick(stacks);
	divide_b2a_quick(stacks);
	merge_in_b_with_selection_sort_quick(stacks);

	while (stacks->b)
		cmd_pa(stacks);
}
