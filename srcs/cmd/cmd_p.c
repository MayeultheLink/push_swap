/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:22:36 by mde-la-s          #+#    #+#             */
/*   Updated: 2023/12/02 15:35:15 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	cmd_pb(t_stack stacks)
{
	t_list	*new;

	if (stacks.a)
	{
		new = ft_lstnew(stacks.a->content);
		ft_lstadd_front(&stacks.b, new);
		new = stacks.a;
		stacks.a = stacks.a->next;
		free(new);
		new = NULL;
	}
	write(1, "pb\n", 3);
	return (stacks);
}

t_stack	cmd_pa(t_stack stacks)
{
	t_list	*new;

	if (stacks.b)
	{
		new = ft_lstnew(stacks.b->content);
		ft_lstadd_front(&stacks.a, new);
		new = stacks.b;
		stacks.b = stacks.b->next;
		free(new);
		new = NULL;
	}
	write(1, "pa\n", 3);
	return (stacks);
}
