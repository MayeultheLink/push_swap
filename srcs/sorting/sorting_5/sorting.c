/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:21:28 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 15:36:09 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	sort_stacksa(t_stack stacks)
{
	if (ft_lstsize(stacks.a) == 5)
		return (sort_5(stacks));
	if (ft_lstsize(stacks.a) == 4)
		return (sort_4(stacks));
	if (ft_lstsize(stacks.a) == 3)
		return (sort_3(stacks));
	if (ft_lstsize(stacks.a) == 2
		&& stacks.a->content > stacks.a->next->content)
		return (cmd_sa(stacks));
	return (stacks);
}
