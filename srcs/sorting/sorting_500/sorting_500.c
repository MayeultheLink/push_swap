/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:38:24 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/06 13:47:22 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorting_500(t_stacks* stacks)
{
	int		size;

	size = ft_lstsize(stacks->a) / 5;
	while (ft_lstsize(stacks->a) > size && !is_sorted(stacks->a))
		chunks_a2b(stacks, ft_lstsize(stacks->b), ft_lstsize(stacks->b) + size);

	size /= 2;
	while (ft_lstsize(stacks->b) > size)
		chunks_b2a(stacks, ft_lstsize(stacks->b) - size, ft_lstsize(stacks->b));

	size /= 5;
	while (ft_lstsize(stacks->b) > size)
		chunks_b2a(stacks, ft_lstsize(stacks->b) - size, ft_lstsize(stacks->b));

	while (ft_lstsize(stacks->a) > size && !is_sorted(stacks->a))
		chunks_a2b(stacks, ft_lstsize(stacks->b), ft_lstsize(stacks->b) + size);

	a2b_until_sorted(stacks);
	sorting(stacks);
}
