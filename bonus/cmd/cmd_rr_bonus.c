/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:19:58 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 16:57:41 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	cmd_rra_bonus(t_stack stacks)
{
	int		param1;
	int		param2;
	t_list	*tmp;

	if (stacks.a && stacks.a->next && stacks.b && stacks.b->next
		&& stacks.b->content < ft_lstlast(stacks.b)->content)
		return (cmd_rrr_bonus(stacks));
	if (ft_lstsize(stacks.a) > 1)
	{
		tmp = stacks.a;
		param2 = ft_lstlast(stacks.a)->content;
		param1 = tmp->next->content;
		tmp->next->content = tmp->content;
		tmp->content = param2;
		tmp = tmp->next;
		while (tmp->next)
		{
			param2 = tmp->next->content;
			tmp->next->content = param1;
			param1 = param2;
			tmp = tmp->next;
		}
	}
	return (stacks);
}

t_stack	cmd_rrb_bonus(t_stack stacks)
{
	int		param1;
	int		param2;
	t_list	*tmp;

	if (stacks.b && stacks.b->next && stacks.a && stacks.a->next
		&& stacks.a->content > ft_lstlast(stacks.a)->content)
		return (cmd_rrr_bonus(stacks));
	if (ft_lstsize(stacks.b) > 1)
	{
		tmp = stacks.b;
		param2 = ft_lstlast(stacks.b)->content;
		param1 = tmp->next->content;
		tmp->next->content = tmp->content;
		tmp->content = param2;
		tmp = tmp->next;
		while (tmp->next)
		{
			param2 = tmp->next->content;
			tmp->next->content = param1;
			param1 = param2;
			tmp = tmp->next;
		}
	}
	return (stacks);
}

t_stack	cmd_rrr_bonus(t_stack stacks)
{
	stacks.a = cmd_rrab_bonus(stacks.a);
	stacks.b = cmd_rrab_bonus(stacks.b);
	return (stacks);
}

t_list	*cmd_rrab_bonus(t_list *lst)
{
	int		param1;
	int		param2;
	t_list	*tmp;

	tmp = lst;
	if (ft_lstsize(lst) > 1)
	{
		param2 = ft_lstlast(lst)->content;
		param1 = tmp->next->content;
		tmp->next->content = tmp->content;
		tmp->content = param2;
		tmp = tmp->next;
		while (tmp->next)
		{
			param2 = tmp->next->content;
			tmp->next->content = param1;
			param1 = param2;
			tmp = tmp->next;
		}
	}
	return (lst);
}
