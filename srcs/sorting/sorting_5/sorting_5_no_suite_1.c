/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5_no_suite_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:41:10 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 15:04:09 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_suite_1(t_stacks* stacks, t_pos pos)
{
	if ((pos.min == 0 && pos.min2 == 1) || (pos.min == 1 && pos.min2 == 0))
	{
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
	if ((pos.min == 0 && pos.min2 == 4) || (pos.min == 4 && pos.min2 == 0))
	{
		cmd_pb(stacks);
		cmd_rra(stacks);
		cmd_pb(stacks);
	}
	if ((pos.min == 1 && pos.min2 == 2) || (pos.min == 2 && pos.min2 == 1))
	{
		cmd_ra(stacks);
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
}

void	no_suite_2(t_stacks* stacks, t_pos pos)
{
	if ((pos.min == 0 && pos.min2 == 2) || (pos.min == 2 && pos.min2 == 0))
	{
		cmd_pb(stacks);
		cmd_ra(stacks);
		cmd_pb(stacks);
	}
	if ((pos.min == 2 && pos.min2 == 3) || (pos.min == 3 && pos.min2 == 2))
	{
		cmd_ra(stacks);
		cmd_ra(stacks);
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
}

void	no_suite_3(t_stacks* stacks, t_pos pos)
{
	if (pos.max == 0 && pos.min == 1)
	{
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
	else if (pos.max == 0 && pos.min == 4)
	{
		cmd_pb(stacks);
		cmd_rra(stacks);
		cmd_pb(stacks);
	}
	else if (pos.max == 2 && pos.min == 1)
	{
		cmd_ra(stacks);
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
	else
		no_suite_3bis(stacks, pos);
}

void	no_suite_3bis(t_stacks* stacks, t_pos pos)
{
	cmd_sa(stacks);
	if (pos.min == 1)
	{
		cmd_pb(stacks);
		cmd_rra(stacks);
	}
	if (pos.min == 4)
	{
		cmd_rra(stacks);
		cmd_pb(stacks);
	}
	cmd_pb(stacks);
}

void	no_suite_4(t_stacks* stacks, t_pos pos)
{
	if (pos.max == 0 && pos.min == 4)
	{
		cmd_pb(stacks);
		cmd_rra(stacks);
		cmd_pb(stacks);
	}
	else
	{
		cmd_rra(stacks);
		if (pos.min == 3)
		{
			cmd_rra(stacks);
			cmd_pb(stacks);
		}
		if (pos.min == 4)
		{
			cmd_pb(stacks);
			cmd_rra(stacks);
		}
		cmd_pb(stacks);
	}
}
