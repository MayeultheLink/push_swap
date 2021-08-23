/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:25:32 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 15:03:52 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	sort_4(t_stack stacks)
{
	t_list	*tmp;
	int		content;

	tmp = stacks.a;
	content = stacks.a->content;
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
	stacks = cmd_pa(stacks);
	return (stacks);
}
