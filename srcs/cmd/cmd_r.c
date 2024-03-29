/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:42:26 by mde-la-s          #+#    #+#             */
/*   Updated: 2023/12/03 16:44:42 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_ra(t_stacks* stacks)
{
	int		param;
	t_list	*tmp;

	if (stacks->a && stacks->a->next && stacks->b && stacks->b->next
		&& stacks->b->content < ft_lstlast(stacks->b)->content)
		return (cmd_rr(stacks));
	if (ft_lstsize(stacks->a) > 1)
	{
		param = stacks->a->content;
		tmp = stacks->a;
		while (tmp->next)
		{
			tmp->content = tmp->next->content;
			tmp = tmp->next;
		}
		tmp->content = param;
	}
	write(1, "ra\n", 3);
}

void	cmd_rb(t_stacks* stacks)
{
	int		param;
	t_list	*tmp;

	if (stacks->b && stacks->b->next && stacks->a && stacks->a->next
		&& stacks->a->content > ft_lstlast(stacks->a)->content)
		return (cmd_rr(stacks));
	if (ft_lstsize(stacks->b) > 1)
	{
		param = stacks->b->content;
		tmp = stacks->b;
		while (tmp->next)
		{
			tmp->content = tmp->next->content;
			tmp = tmp->next;
		}
		tmp->content = param;
	}
	write(1, "rb\n", 3);
}

void	cmd_rr(t_stacks* stacks)
{
	stacks->a = cmd_r(stacks->a);
	stacks->b = cmd_r(stacks->b);
	write(1, "rr\n", 3);
}

t_list	*cmd_r(t_list *lst)
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
