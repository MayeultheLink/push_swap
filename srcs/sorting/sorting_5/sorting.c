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

void	sort_stacksa(t_stacks* stacks)
{
	if (ft_lstsize(stacks->a) == 5)
		sort_5(stacks);
	if (ft_lstsize(stacks->a) == 4)
		sort_4(stacks);
	if (ft_lstsize(stacks->a) == 3)
		sort_3(stacks);
	if (ft_lstsize(stacks->a) == 2 && stacks->a->content > stacks->a->next->content)
		cmd_sa(stacks);
}