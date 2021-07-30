/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:05:11 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/07/30 19:32:01 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	quick_sort(t_stack stacks)
{
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(stacks.a) / 5;
	while (ft_lstsize(stacks.a) > size)
	{
		stacks = quick_sort_a2b(stacks, i, i + size);
		i += size;
	}


	//	a = 100, b = 4 * 100	//

	
	size /= 2;
	while (ft_lstsize(stacks.b) > size)
		stacks = quick_sort_b2a(stacks, ft_lstsize(stacks.b) - size, 
				ft_lstsize(stacks.b));


	//	a = 100 + 7 * 50, b = 50	//


	size /= 5;
	while (ft_lstsize(stacks.a) > size)
		stacks = quick_sort_a2b(stacks, ft_lstsize(stacks.b), ft_lstsize(stacks.b) + size);
	

	//	a = 10, b = 44 * 10 + 50	//


	stacks = sorting_a2b(stacks);

	stacks = sorting(stacks);
	return (stacks);
}

t_stack	quick_sort_a2b(t_stack stacks, int min, int max)
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

t_stack	quick_sort_b2a(t_stack stacks, int min, int max)
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
		{
			stacks = cmd_pa(stacks);
			if (stacks.b && stacks.b->next 
				&& stacks.b->next->content == ft_lstsize(stacks.b) - 1
				&& stacks.b->next->content == stacks.b->content + 1)
				stacks = cmd_sb(stacks);
		}
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

t_stack	sorting_a2b(t_stack stacks)
{
	t_list	*tmp;
	int		i;

	while (stacks.a && !is_sorted(stacks.a))
	{
		while (stacks.a && stacks.b 
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
