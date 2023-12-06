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

int	main(int ac, char **av)
{
	t_list	*params;
	t_stack	stacks;

	if (ac == 1)
		return (0);
	params = get_params(ac, av);
	if (!params || !params_doublon(params))
	{
		free_error(params);
		write(1, "Error\n", 6);
		return (0);
	}
	stacks = init_stacks(params);

	if (!is_sorted(params))
	{
//		stacks = bubble_sort(stacks);
//		stacks = insertion_sort(stacks);
//		stacks = selection_sort(stacks);
		stacks = quick_sort(stacks);

//		if (ft_lstsize(stacks.a) <= 5)
//			stacks = sort_stacksa(stacks);
//		else if (ft_lstsize(stacks.a) <= 200)
//			stacks = sorting_200(stacks);
//		else
//			stacks = sorting_500(stacks);
	}

	while (stacks.a)
	{
		printf("a : %d\n", stacks.a->content);
		stacks.a = stacks.a->next;
	}
	while (stacks.b)
	{
		printf("b : %d\n", stacks.b->content);
		stacks.b = stacks.b->next;
	}


	return (free_all(stacks));
}

int	free_all(t_stack stacks)
{
	t_list	*tmp;

	while (stacks.a)
	{
		tmp = stacks.a;
		stacks.a = stacks.a->next;
		free(tmp);
		tmp = NULL;
	}
	while (stacks.b)
	{
		tmp = stacks.b;
		stacks.b = stacks.b->next;
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

t_list	*free_error(t_list *params)
{
	t_list	*tmp;

	while (params)
	{
		tmp = params;
		params = params->next;
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
