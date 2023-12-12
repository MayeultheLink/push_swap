/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:24:58 by mde-la-s          #+#    #+#             */
/*   Updated: 2023/12/03 18:16:47 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_stacks* stacks)
{
		// bubble_sort(stacks);
		// insertion_sort(stacks);
		// selection_sort(stacks);
		// merge_sort(stacks);
		// radix_sort(stacks);
		// quick_sort(stacks);

		if (ft_lstsize(stacks->a) <= 5)
			sort_stacksa(stacks);
		else if (ft_lstsize(stacks->a) <= 200)
			sorting_200(stacks);
		else if (ft_lstsize(stacks->a) <= 2500)
			sorting_500(stacks);
		else
			radix_sort(stacks);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		write(2, "Please enter as parameters numbers to be sorted.\n", ft_strlen("Please enter as parameters numbers to be sorted.\n"));
		return (1);
	}

	t_stacks stacks;
	stacks.a = get_params(av);
	stacks.b = NULL;
	if (!stacks.a || !params_doublon(stacks.a))
	{
		ft_lstfree(stacks.a);
		write(2, "Error\n", 6);
		return (1);
	}

	if (!is_sorted(stacks.a))
		sort(&stacks);

	ft_lstfree(stacks.a);
	ft_lstfree(stacks.b);
	return (0);
}