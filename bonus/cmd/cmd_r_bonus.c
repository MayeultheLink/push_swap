/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:42:26 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/12 01:15:41 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	cmd_ra_bonus(t_stack stacks)
{
	int		param;
	t_list	*tmp;

	if (stacks.b && stacks.b->next
		&& stacks.b->content < ft_lstlast(stacks.b)->content)
		return (cmd_rr(stacks));
	param = stacks.a->content;
	tmp = stacks.a;
	if (ft_lstsize(stacks.a) > 1)
	{
		while (tmp->next)
		{
			tmp->content = tmp->next->content;
			tmp = tmp->next;
		}
	}
	tmp->content = param;
	return (stacks);
}

t_stack	cmd_rb_bonus(t_stack stacks)
{
	int		param;
	t_list	*tmp;

	if (stacks.a && stacks.a->next
		&& stacks.a->content > ft_lstlast(stacks.a)->content)
		return (cmd_rr(stacks));
	param = stacks.b->content;
	tmp = stacks.b;
	if (ft_lstsize(stacks.b) > 1)
	{
		while (tmp->next)
		{
			tmp->content = tmp->next->content;
			tmp = tmp->next;
		}
	}
	tmp->content = param;
	return (stacks);
}

t_stack	cmd_rr_bonus(t_stack stacks)
{
	stacks.a = cmd_r(stacks.a);
	stacks.b = cmd_r(stacks.b);
	return (stacks);
}
