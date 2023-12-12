/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5_no_suite_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:07:13 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 15:04:17 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_suite_5(t_stacks* stacks, t_pos pos)
{
	if (pos.min == 0 && pos.max == 1)
	{
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
	else if (pos.min == 0 && pos.max == 4)
	{
		cmd_pb(stacks);
		cmd_rra(stacks);
		cmd_pb(stacks);
	}
	else
	{
		cmd_pb(stacks);
		cmd_rra(stacks);
		cmd_rra(stacks);
		cmd_pb(stacks);
	}
}

void	no_suite_6(t_stacks* stacks, t_pos pos)
{
	if (pos.min == 1 && pos.max == 0)
	{
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
	else if (pos.min == 1 && pos.max == 2)
	{
		cmd_ra(stacks);
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
	else
	{
		cmd_ra(stacks);
		cmd_pb(stacks);
		cmd_ra(stacks);
		cmd_pb(stacks);
	}
}

void	no_suite_7(t_stacks* stacks, t_pos pos)
{
	if (pos.min == 4 && pos.max == 0)
	{
		cmd_pb(stacks);
		cmd_rra(stacks);
		cmd_pb(stacks);
	}
	else if (pos.min == 2 && pos.max == 1)
	{
		cmd_ra(stacks);
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
	else if (pos.max == 3)
	{
		if (stacks->a->content > stacks->a->next->content)
			cmd_sa(stacks);
		cmd_ra(stacks);
		cmd_ra(stacks);
		cmd_sa(stacks);
		cmd_ra(stacks);
		if (!is_sorted(stacks->a))
			cmd_sa(stacks);
	}
	no_suite_7bis(stacks, pos);
}

void	no_suite_7bis(t_stacks* stacks, t_pos pos)
{
	if (pos.min == 2 && pos.max == 0)
	{
		cmd_pb(stacks);
		cmd_sa(stacks);
		cmd_pb(stacks);
	}
	else if (pos.min == 4 && pos.max == 1)
	{
		cmd_sa(stacks);
		cmd_rra(stacks);
		cmd_pb(stacks);
		cmd_pb(stacks);
	}
	else if ((pos.max != 0 && pos.min != 4) && (pos.min != 2 && pos.max != 1) && pos.max != 3)
	{
		cmd_rra(stacks);
		cmd_pb(stacks);
		cmd_rra(stacks);
		cmd_rra(stacks);
		cmd_pa(stacks);
	}
}

void	no_suite_8(t_stacks* stacks)
{
	if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
		return ;
	if (ft_lstsize(stacks->a) == 3)
		sort_3(stacks);
	if (stacks->b && stacks->b->next
		&& stacks->b->content < stacks->b->next->content)
		cmd_sb(stacks);
	if (ft_lstsize(stacks->a) == 3)
	{
		cmd_pa(stacks);
		if (stacks->a->content > stacks->a->next->content)
			cmd_ra(stacks);
		cmd_pa(stacks);
	}
}
