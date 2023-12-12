/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:19:58 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/06 16:02:10 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_rra(t_stacks* stacks)
{
	int		param1;
	int		param2;
	t_list	*tmp;

	if (stacks->a && stacks->a->next && stacks->b && stacks->b->next
		&& stacks->b->content < ft_lstlast(stacks->b)->content)
		return (cmd_rrr(stacks));
	if (ft_lstsize(stacks->a) > 1)
	{
		tmp = stacks->a;
		param2 = ft_lstlast(stacks->a)->content;
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
	write(1, "rra\n", 4);
}

void	cmd_rrb(t_stacks* stacks)
{
	int		param1;
	int		param2;
	t_list	*tmp;

	if (stacks->b && stacks->b->next && stacks->a && stacks->a->next
		&& stacks->a->content > ft_lstlast(stacks->a)->content)
		return (cmd_rrr(stacks));
	if (ft_lstsize(stacks->b) > 1)
	{
		tmp = stacks->b;
		param2 = ft_lstlast(stacks->b)->content;
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
	write(1, "rrb\n", 4);
}

void	cmd_rrr(t_stacks* stacks)
{
	stacks->a = cmd_rrab(stacks->a);
	stacks->b = cmd_rrab(stacks->b);
	write(1, "rrr\n", 4);
}

t_list	*cmd_rrab(t_list *lst)
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
