/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:26:14 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 15:03:46 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (stacks);
}
