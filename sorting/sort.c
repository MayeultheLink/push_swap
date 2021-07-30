/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:21:28 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/07/14 16:44:10 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	sort_stacksa(t_stack stacks)
{
	t_list	*tmp;
	int		content;

	tmp = stacks.a;
	content = stacks.a->content;
	if (ft_lstsize(stacks.a) == 5)
		return (sort_5(stacks));
	if (ft_lstsize(stacks.a) == 3)
		return (sort_3(stacks));
	if (ft_lstsize(stacks.a) == 4)
	{
		while (tmp)
		{
			if (content > tmp->content)
				content = tmp->content;
			tmp = tmp->next;
		}
		while (stacks.a->content != content)
			stacks = cmd_ra(stacks);
		stacks = cmd_pb(stacks);
		stacks = sort_3(stacks);
		return (cmd_pa(stacks));
	}
	if (ft_lstsize(stacks.a) == 2 && stacks.a->content > stacks.a->next->content)
		return (cmd_sa(stacks));
	return (stacks);
}

t_stack	sort_3(t_stack stacks)
{
	if (stacks.a && ft_lstsize(stacks.a) == 3)
	{
		if (stacks.a->content > stacks.a->next->content
			&& stacks.a->content > ft_lstlast(stacks.a)->content)
			stacks = cmd_ra(stacks);
		if (stacks.a->content > stacks.a->next->content)
			stacks = cmd_sa(stacks);
		if (stacks.a->next->content > ft_lstlast(stacks.a)->content)
			stacks = cmd_rra(stacks);
		if (stacks.a->content > stacks.a->next->content)
			stacks = cmd_sa(stacks);
	}
	if (stacks.b && ft_lstsize(stacks.b) == 3)
	{
		if (stacks.b->content < stacks.b->next->content
			&& stacks.b->content < ft_lstlast(stacks.b)->content)
			stacks = cmd_rb(stacks);
		if (stacks.b->content < stacks.b->next->content)
			stacks = cmd_sb(stacks);
		if (stacks.b->next->content < ft_lstlast(stacks.b)->content)
			stacks = cmd_rrb(stacks);
		if (stacks.b->content < stacks.b->next->content)
			stacks = cmd_sb(stacks);
	}
	return (stacks);
}
