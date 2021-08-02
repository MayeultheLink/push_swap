/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5_no_suite_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:07:13 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/02 18:35:11 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	no_suite_5(t_stack stacks, t_pos pos)
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
	return (stacks);
}

t_stack	no_suite_6(t_stack stacks, t_pos pos)
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
	return (stacks);
}

t_stack	no_suite_7(t_stack stacks, t_pos pos)
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
	else
		stacks = no_suite_7bis(stacks, pos);
	return (stacks);
}

t_stack	no_suite_7bis(t_stack stacks, t_pos pos)
{
	if (pos.min == 2 && pos.max == 0)
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
	return (stacks);
}

t_stack	no_suite_8(t_stack stacks)
{
	if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
		return (stacks);
	if (ft_lstsize(stacks.a) == 3)
		stacks = sort_3(stacks);
	if (stacks.b && stacks.b->next
		&& stacks.b->content < stacks.b->next->content)
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
