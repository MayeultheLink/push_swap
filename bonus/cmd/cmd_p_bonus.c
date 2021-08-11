/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 19:22:36 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/12 01:17:01 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	cmd_pb_bonus(t_stack stacks)
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
	return (stacks);
}

t_stack	cmd_pa_bonus(t_stack stacks)
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
	return (stacks);
}
