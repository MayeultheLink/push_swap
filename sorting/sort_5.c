/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:09:16 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/07/30 16:39:27 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	sort_5(t_stack stacks)
{
	t_pos	pos;

	pos.size = size_suite(stacks.a);
	pos.suite = pos_suite(stacks.a, pos.size);
	pos.min = pos_min(stacks.a);
	pos.min2 = pos_min2(stacks.a);
	pos.max = pos_max(stacks.a);
//	printf("size = %d\nsuite = %d\nmin = %d\nmin2 = %d\nmax = %d\n", pos.size, pos.suite, pos.min, pos.min2, pos.max);
	if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
		return (stacks);
	if (pos.size == 4)
	{
		if (pos.min == 1)
			stacks = cmd_ra(stacks);
		if (pos.min == 4)
			stacks = cmd_rra(stacks);
		return (stacks);
	}
	if (pos.size == 3)
		stacks = sort_5_suite_3(stacks, pos);
	else
		stacks = sort_5_no_suite(stacks, pos);
	return (stacks);
}

t_stack	sort_5_suite_3(t_stack stacks, t_pos pos)
{
	if (pos.suite == 0)
	{
		stacks = cmd_rra(stacks);
		if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
			return (stacks);
		stacks = cmd_rra(stacks);
		if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
			return (stacks);
		stacks = cmd_sa(stacks);
		if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
			return (stacks);
		stacks = cmd_ra(stacks);
		if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
			return (stacks);
		stacks = cmd_ra(stacks);
	}
	if (pos.suite == 1)
	{
		if (pos.min == 4)
		{
			stacks = cmd_rra(stacks);
			if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
				return (stacks);
			stacks = cmd_sa(stacks);
			stacks = cmd_ra(stacks);
			return (stacks);
		}
		stacks = cmd_rra(stacks);
		stacks = cmd_sa(stacks);
		if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
			return (stacks);
		stacks = cmd_ra(stacks);
		stacks = cmd_ra(stacks);
	}
	if (pos.suite == 2)
	{
		if (stacks.a->content > stacks.a->next->content || pos.min == 0)
			stacks = cmd_sa(stacks);
		if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
			return (stacks);
		stacks = cmd_ra(stacks);
		if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
			return (stacks);
		stacks = cmd_ra(stacks);
	}
	return (stacks);
}

t_stack	sort_5_no_suite(t_stack stacks, t_pos pos)
{
	if ((pos.min == 0 && pos.min2 == 1) || (pos.min == 1 && pos.min2 == 0))
	{
		stacks = cmd_pb(stacks);
		stacks = cmd_pb(stacks);
	}
	if ((pos.min == 0 && pos.min2 == 4) || (pos.min == 4 && pos.min2 == 0))
	{
		stacks = cmd_pb(stacks);
		stacks = cmd_rra(stacks);
		stacks = cmd_pb(stacks);
	}
	if ((pos.min == 1 && pos.min2 == 2) || (pos.min == 2 && pos.min2 == 1))
	{
		stacks = cmd_ra(stacks);
		stacks = cmd_pb(stacks);
		stacks = cmd_pb(stacks);
	}
	if ((pos.min == 0 && pos.min2 == 2) || (pos.min == 2 && pos.min2 == 0))
	{
		stacks = cmd_pb(stacks);
		stacks = cmd_ra(stacks);
		stacks = cmd_pb(stacks);
	}
	if ((pos.min == 2 && pos.min2 == 3) || (pos.min == 3 && pos.min2 == 2))
	{
		stacks = cmd_ra(stacks);
		stacks = cmd_ra(stacks);
		stacks = cmd_pb(stacks);
		stacks = cmd_pb(stacks);
	}
	if ((pos.min == 1 && pos.min2 == 4) || (pos.min == 4 && pos.min2 == 1))
	{
		if (pos.max == 0 && pos.min == 1)
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_pb(stacks);
		}	
		else if (pos.max == 0 && pos.min == 4)
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_pb(stacks);
		}
		else if (pos.max == 2 && pos.min == 1)
		{
			stacks = cmd_ra(stacks);
			stacks = cmd_pb(stacks);
			stacks = cmd_pb(stacks);
		}
		else
		{
			stacks = cmd_sa(stacks);
			if (pos.min == 1)
			{
				stacks = cmd_pb(stacks);
				stacks = cmd_ra(stacks);
			}
			if (pos.min == 4)
			{
				stacks = cmd_ra(stacks);
				stacks = cmd_pb(stacks);
			}
			stacks = cmd_pb(stacks);
		}
	}
	if ((pos.min == 3 && pos.min2 == 4) || (pos.min == 4 && pos.min2 == 3))
	{
		if (pos.max == 0 && pos.min == 4)
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_pb(stacks);
		}
		else
		{
			stacks = cmd_rra(stacks);
			if (pos.min == 3)
			{
				stacks = cmd_rra(stacks);
				stacks = cmd_pb(stacks);
			}
			if (pos.min == 4)
			{
				stacks = cmd_pb(stacks);
				stacks = cmd_rra(stacks);
			}
			stacks = cmd_pb(stacks);
		}
	}
	if ((pos.min == 0 && pos.min2 == 3) || (pos.min == 3 && pos.min2 == 0))
	{
		if (pos.min == 0 && pos.max == 1)
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_pb(stacks);
		}
		else if (pos.min == 0 && pos.max == 4)
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_pb(stacks);
		}
		else
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_pb(stacks);
		}
	}
	if ((pos.min == 1 && pos.min2 == 3) || (pos.min == 3 && pos.min2 == 1))
	{
		if (pos.min == 1 && pos.max == 0)
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_pb(stacks);
		}
		else if (pos.min == 1 && pos.max == 2)
		{
			stacks = cmd_ra(stacks);
			stacks = cmd_pb(stacks);
			stacks = cmd_pb(stacks);
		}
		else
		{
			stacks = cmd_ra(stacks);
			stacks = cmd_pb(stacks);
			stacks = cmd_ra(stacks);
			stacks = cmd_pb(stacks);
		}
	}
	if ((pos.min == 2 && pos.min2 == 4) || (pos.min == 4 && pos.min2 == 2))
	{
		if (pos.min == 4 && pos.max == 0)
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_pb(stacks);
		}
		else if (pos.min == 2 && pos.max == 1)
		{
			stacks = cmd_ra(stacks);
			stacks = cmd_pb(stacks);
			stacks = cmd_pb(stacks);
		}
		else if (pos.min == 4 && pos.max == 1)
		{
			stacks = cmd_sa(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_pb(stacks);
			stacks = cmd_pb(stacks);
		}
		else if (pos.min == 2 && pos.max == 0)
		{
			stacks = cmd_pb(stacks);
			stacks = cmd_sa(stacks);
			stacks = cmd_pb(stacks);
		}
		else if (pos.max == 3)
		{
			if (stacks.a->content > stacks.a->next->content)
				stacks = cmd_sa(stacks);
			stacks = cmd_ra(stacks);
			stacks = cmd_ra(stacks);
			stacks = cmd_sa(stacks);
			stacks = cmd_ra(stacks);
		}
		else
		{
			stacks = cmd_rra(stacks);
			stacks = cmd_pb(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_rra(stacks);
			stacks = cmd_pa(stacks);
		}
	}
	if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
		return (stacks);
	if (ft_lstsize(stacks.a) == 3)
		stacks = sort_3(stacks);
	if (stacks.b && stacks.b->next && stacks.b->content < stacks.b->next->content)
		stacks = cmd_sb(stacks);
	if (ft_lstsize(stacks.a) == 3)
	{
		stacks = cmd_pa(stacks);
		if (stacks.a->content > stacks.a->next->content)
			stacks = cmd_ra(stacks);
		stacks = cmd_pa(stacks);
	}
	return (stacks);
}
