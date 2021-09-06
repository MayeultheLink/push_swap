/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:24:58 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/06 13:35:06 by mde-la-s         ###   ########.fr       */
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
		if (ft_lstsize(stacks.a) <= 5)
			stacks = sort_stacksa(stacks);
		else if (ft_lstsize(stacks.a) <= 200)
			stacks = sorting_200(stacks);
		else
			stacks = sorting_500(stacks);
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
