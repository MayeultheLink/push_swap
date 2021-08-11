/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5_suite_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:30:54 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/02 18:32:41 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	pos_suite_0(t_stack stacks)
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
	return (stacks);
}

t_stack	pos_suite_1(t_stack stacks, t_pos pos)
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
	return (stacks);
}

t_stack	pos_suite_2(t_stack stacks, t_pos pos)
{
	if (stacks.a->content > stacks.a->next->content || pos.min == 0)
		stacks = cmd_sa(stacks);
	if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
		return (stacks);
	stacks = cmd_ra(stacks);
	if (is_sorted(stacks.a) && ft_lstsize(stacks.a) == 5)
		return (stacks);
	stacks = cmd_ra(stacks);
	return (stacks);
}
