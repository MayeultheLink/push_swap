/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:33:39 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/02 18:33:01 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	sorting_200(t_stack stacks)
{
	int		size;

	size = ft_lstsize(stacks.a) / 2;
	while (ft_lstsize(stacks.a) > size)
		stacks = chunks_a2b(stacks, ft_lstsize(stacks.b),
				ft_lstsize(stacks.b) + size);
	size /= 2;
	while (ft_lstsize(stacks.b) > size)
		stacks = chunks_b2a(stacks, ft_lstsize(stacks.b) - size,
				ft_lstsize(stacks.b));
	size = 10;
	while (ft_lstsize(stacks.a) > size)
		stacks = chunks_a2b(stacks, ft_lstsize(stacks.b),
				ft_lstsize(stacks.b) + size);
	stacks = a2b_until_sorted(stacks);
	stacks = sorting(stacks);
	return (stacks);
}
