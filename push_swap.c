/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:24:58 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/11 20:53:24 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*params;
	t_stack	stacks;

	(void)ac;
	if (!av[1])
		return (0);
	params = get_params(av);
	if (!params || !params_doublon(params))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (is_sorted(params))
		return (0);
	stacks = init_stacks(params);
	if (ft_lstsize(stacks.a) <= 5)
		stacks = sort_stacksa(stacks);
	else if (ft_lstsize(stacks.a) <= 200)
		stacks = sorting_200(stacks);
	else
		stacks = sorting_500(stacks);
	free_all(stacks);
	return (0);
}

void	free_all(t_stack stacks)
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
}
