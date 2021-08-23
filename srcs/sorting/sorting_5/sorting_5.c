/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:09:16 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 15:04:00 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	sort_5(t_stack stacks)
{
	t_pos	pos;

	pos.size = size_suite(stacks.a);
	pos.suite = pos_suite(stacks.a, pos.size);
	pos.min = pos_min(stacks.a);
	pos.min2 = pos_min2(stacks.a);
	pos.max = pos_max(stacks.a);
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
		stacks = pos_suite_0(stacks);
	if (pos.suite == 1)
		stacks = pos_suite_1(stacks, pos);
	if (pos.suite == 2)
		stacks = pos_suite_2(stacks, pos);
	return (stacks);
}

t_stack	sort_5_no_suite(t_stack stacks, t_pos pos)
{
	stacks = no_suite_1(stacks, pos);
	stacks = no_suite_2(stacks, pos);
	if ((pos.min == 1 && pos.min2 == 4) || (pos.min == 4 && pos.min2 == 1))
		stacks = no_suite_3(stacks, pos);
	if ((pos.min == 3 && pos.min2 == 4) || (pos.min == 4 && pos.min2 == 3))
		stacks = no_suite_4(stacks, pos);
	if ((pos.min == 0 && pos.min2 == 3) || (pos.min == 3 && pos.min2 == 0))
		stacks = no_suite_5(stacks, pos);
	if ((pos.min == 1 && pos.min2 == 3) || (pos.min == 3 && pos.min2 == 1))
		stacks = no_suite_6(stacks, pos);
	if ((pos.min == 2 && pos.min2 == 4) || (pos.min == 4 && pos.min2 == 2))
		stacks = no_suite_7(stacks, pos);
	stacks = no_suite_8(stacks);
	return (stacks);
}
