/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_s_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:07:19 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 16:57:50 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	cmd_sa_bonus(t_stack stacks)
{
	int	tmp;

	if (stacks.a && stacks.a->next && stacks.b && stacks.b->next
		&& stacks.b->content < stacks.b->next->content)
		return (cmd_ss_bonus(stacks));
	if (ft_lstsize(stacks.a) > 1)
	{
		tmp = stacks.a->next->content;
		stacks.a->next->content = stacks.a->content;
		stacks.a->content = tmp;
	}
	return (stacks);
}

t_stack	cmd_sb_bonus(t_stack stacks)
{
	int	tmp;

	if (stacks.b && stacks.b->next && stacks.a && stacks.a->next
		&& stacks.a->content > stacks.a->next->content)
		return (cmd_ss_bonus(stacks));
	if (ft_lstsize(stacks.b) > 1)
	{
		tmp = stacks.b->next->content;
		stacks.b->next->content = stacks.b->content;
		stacks.b->content = tmp;
	}
	return (stacks);
}

t_stack	cmd_ss_bonus(t_stack stacks)
{
	int	tmp;

	if (ft_lstsize(stacks.a) > 1)
	{
		tmp = stacks.a->next->content;
		stacks.a->next->content = stacks.a->content;
		stacks.a->content = tmp;
	}
	if (ft_lstsize(stacks.b) > 1)
	{
		tmp = stacks.b->next->content;
		stacks.b->next->content = stacks.b->content;
		stacks.b->content = tmp;
	}
	return (stacks);
}
