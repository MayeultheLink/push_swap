/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:05:11 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/06 14:40:07 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	chunks_a2b(t_stack stacks, int min, int max)
{
	t_list	*tmp;
	int		i;

	while (stacks.a && stacks.a->next && !lst_content(stacks.a, min, max)
		&& !is_sorted(stacks.a))
	{
		tmp = stacks.a;
		i = 0;
		while (tmp->content < min || tmp->content >= max)
		{
			i++;
			tmp = tmp->next;
		}
		if (i <= ft_lstsize(stacks.a) / 2)
			while (stacks.a->content < min || stacks.a->content >= max)
				stacks = cmd_ra(stacks);
		else
			while (stacks.a->content < min || stacks.a->content >= max)
				stacks = cmd_rra(stacks);
		stacks = cmd_pb(stacks);
	}
	return (stacks);
}

t_stack	chunks_b2a(t_stack stacks, int min, int max)
{
	t_list	*tmp;
	int		i;

	while (stacks.b && stacks.b->next && !lst_content(stacks.b, min, max))
	{
		tmp = stacks.b;
		i = 0;
		while (tmp->content < min || tmp->content >= max)
		{
			i++;
			tmp = tmp->next;
		}
		if (i <= ft_lstsize(stacks.b) / 2)
			while (stacks.b->content < min || stacks.b->content >= max)
				stacks = cmd_rb(stacks);
		else
			while (stacks.b->content < min || stacks.b->content >= max)
				stacks = cmd_rrb(stacks);
		stacks = cmd_pa(stacks);
	}
	return (stacks);
}

t_stack	sorting(t_stack stacks)
{
	t_list	*tmp;
	int		i;

	while (stacks.b)
	{
		while (stacks.b && stacks.b->content == (ft_lstsize(stacks.b) - 1))
			stacks = cmd_pa(stacks);
		i = 0;
		tmp = stacks.b;
		while (tmp && tmp->content != (ft_lstsize(stacks.b) - 1))
		{
			i++;
			tmp = tmp->next;
		}
		if (i <= ft_lstsize(stacks.b) / 2)
			while (stacks.b && (stacks.b->content != ft_lstsize(stacks.b) - 1))
				stacks = cmd_rb(stacks);
		else
			while (stacks.b && (stacks.b->content != ft_lstsize(stacks.b) - 1))
				stacks = cmd_rrb(stacks);
	}
	return (stacks);
}

t_stack	a2b_until_sorted(t_stack stacks)
{
	t_list	*tmp;
	int		i;

	while (stacks.a && !is_sorted(stacks.a))
	{
		while (stacks.a && stacks.b && !is_sorted(stacks.a)
			&& stacks.a->content == (ft_lstsize(stacks.b)))
			stacks = cmd_pb(stacks);
		i = 0;
		tmp = stacks.a;
		while (tmp && tmp->content != (ft_lstsize(stacks.b)))
		{
			i++;
			tmp = tmp->next;
		}
		if (i <= ft_lstsize(stacks.a) / 2)
			while (stacks.a && (stacks.a->content != (ft_lstsize(stacks.b))))
				stacks = cmd_ra(stacks);
		else
			while (stacks.a && (stacks.a->content != (ft_lstsize(stacks.b))))
				stacks = cmd_rra(stacks);
	}
	return (stacks);
}
