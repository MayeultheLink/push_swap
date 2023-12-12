/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:42:26 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 16:57:35 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stacks	cmd_ra_bonus(t_stacks stacks)
{
	int		param;
	t_list	*tmp;

	if (stacks.a && stacks.a->next && stacks.b && stacks.b->next
		&& stacks.b->content < ft_lstlast(stacks.b)->content)
		return (cmd_rr_bonus(stacks));
	if (ft_lstsize(stacks.a) > 1)
	{
		param = stacks.a->content;
		tmp = stacks.a;
		while (tmp->next)
		{
			tmp->content = tmp->next->content;
			tmp = tmp->next;
		}
		tmp->content = param;
	}
	return (stacks);
}

t_stacks	cmd_rb_bonus(t_stacks stacks)
{
	int		param;
	t_list	*tmp;

	if (stacks.b && stacks.b->next && stacks.a && stacks.a->next
		&& stacks.a->content > ft_lstlast(stacks.a)->content)
		return (cmd_rr_bonus(stacks));
	if (ft_lstsize(stacks.b) > 1)
	{
		param = stacks.b->content;
		tmp = stacks.b;
		while (tmp->next)
		{
			tmp->content = tmp->next->content;
			tmp = tmp->next;
		}
		tmp->content = param;
	}
	return (stacks);
}

t_stacks	cmd_rr_bonus(t_stacks stacks)
{
	stacks.a = cmd_r_bonus(stacks.a);
	stacks.b = cmd_r_bonus(stacks.b);
	return (stacks);
}

t_list	*cmd_r_bonus(t_list *lst)
{
	int		param;
	t_list	*tmp;

	if (lst)
	{
		param = lst->content;
		tmp = lst;
	}
	if (ft_lstsize(lst) > 1)
	{
		while (tmp->next)
		{
			tmp->content = tmp->next->content;
			tmp = tmp->next;
		}
	}
	tmp->content = param;
	return (lst);
}
