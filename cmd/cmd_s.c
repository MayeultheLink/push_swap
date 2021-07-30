/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:07:19 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/07/30 16:59:31 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	cmd_sa(t_stack stacks)
{
	int tmp;

	if (stacks.b && stacks.b->next && stacks.b->content < stacks.b->next->content)
		return (cmd_ss(stacks));
	if (ft_lstsize(stacks.a) > 1)
	{
		tmp = stacks.a->next->content;
		stacks.a->next->content = stacks.a->content;
		stacks.a->content = tmp;
	}
	write(1, "sa\n", 3);
	return (stacks);
}

t_stack	cmd_sb(t_stack stacks)
{
	int	tmp;

	if (stacks.a && stacks.a->next && stacks.a->content > stacks.a->next->content)
		return (cmd_ss(stacks));
	if (ft_lstsize(stacks.b) > 1)
	{
		tmp = stacks.b->next->content;
		stacks.b->next->content = stacks.b->content;
		stacks.b->content = tmp;
	}
	write(1, "sb\n", 3);
	return (stacks);
}

t_stack	cmd_ss(t_stack stacks)
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
	write(1, "ss\n", 3);
	return (stacks);
}
