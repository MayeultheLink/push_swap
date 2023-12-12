/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5_suite_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:30:54 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 15:04:23 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_suite_0(t_stacks* stacks)
{
	cmd_rra(stacks);
	if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
		return ;
	cmd_rra(stacks);
	if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
		return ;
	cmd_sa(stacks);
	if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
		return ;
	cmd_ra(stacks);
	if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
		return ;
	cmd_ra(stacks);
}

void	pos_suite_1(t_stacks* stacks, t_pos pos)
{
	if (pos.min == 4)
	{
		cmd_rra(stacks);
		if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
			return ;
		cmd_sa(stacks);
		cmd_ra(stacks);
		return ;
	}
	cmd_rra(stacks);
	cmd_sa(stacks);
	if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
		return ;
	cmd_ra(stacks);
	cmd_ra(stacks);
}

void	pos_suite_2(t_stacks* stacks, t_pos pos)
{
	if (stacks->a->content > stacks->a->next->content || pos.min == 0)
		cmd_sa(stacks);
	if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
		return ;
	cmd_ra(stacks);
	if (is_sorted(stacks->a) && ft_lstsize(stacks->a) == 5)
		return ;
	cmd_ra(stacks);
}
