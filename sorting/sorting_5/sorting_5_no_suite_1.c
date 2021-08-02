/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5_no_suite_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:41:10 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/02 18:32:23 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	no_suite_1(t_stack stacks, t_pos pos)
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
	return (stacks);
}

t_stack	no_suite_2(t_stack stacks, t_pos pos)
{
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
	return (stacks);
}

t_stack	no_suite_3(t_stack stacks, t_pos pos)
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
		stacks = no_suite_3bis(stacks, pos);
	return (stacks);
}

t_stack	no_suite_3bis(t_stack stacks, t_pos pos)
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
	return (stacks);
}

t_stack	no_suite_4(t_stack stacks, t_pos pos)
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
	return (stacks);
}
