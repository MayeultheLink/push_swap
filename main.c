/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:24:58 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/07/30 20:44:18 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*params;
	t_stack	stacks;
	int		i;

	i = 0;
	(void)ac;
	params = get_params(av);
	if (!params || !params_doublon(params))
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	stacks = init_stacks(params);
//	printf("\n=====================   cmd   =====================\n");
	if (ft_lstsize(stacks.a) <= 5)
		stacks = sort_stacksa(stacks);
	else
		stacks = quick_sort(stacks);
	if (is_sorted(stacks.a))
		i++;
/*	printf("\n===================== stack a =====================\n");
	if (ft_lstsize(stacks.a) > 0)
	{
		while (1)
		{
			printf("%d\n", stacks.a->content);
			free(stacks.a);
			if (!stacks.a->next)
				break ;
			stacks.a = stacks.a->next;
		}
	}
	printf("===================== stack b =====================\n");
	if (ft_lstsize(stacks.b) > 0)
	{
		while (1)
		{
			printf("%d\n", stacks.b->content);
			free(stacks.b);
			if (!stacks.b->next)
				break ;
			stacks.b = stacks.b->next;
		}
	}
	printf("\n");
	if (i)
		printf("OK\n");
	else
		printf("NON TRIE\n");*/
	return (0);
}
