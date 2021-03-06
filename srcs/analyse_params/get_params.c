/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:57:20 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/06 15:15:47 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_params(int ac, char **av)
{
	t_list	*params;
	int		i;

	params = NULL;
	if (ac == 2)
	{
		av = ft_split(av[1], " ");
		params = get_params2(av, 0);
		i = 0;
		if (av)
		{
			while (av[i])
			{
				free(av[i]);
				i++;
			}
			free(av);
		}
	}
	else
		params = get_params2(av, 1);
	params = get_indice(params);
	return (params);
}

t_list	*get_params2(char **av, int i)
{
	t_list	*params;
	t_list	*tmp;
	int		j;

	params = NULL;
	if (av == NULL)
		return (NULL);
	while (av[i] && av[i][0])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]) || !param_int(av[i]))
				return (free_error(params));
			j++;
		}
		tmp = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&params, tmp);
		i++;
		if (av[i] && av[i][0] == '\0')
			return (free_error(params));
	}
	return (params);
}

t_list	*get_indice(t_list *lst)
{
	t_list	*tmp;
	t_list	*save;
	int		i;

	save = lst;
	while (lst)
	{
		tmp = save;
		i = 0;
		while (tmp)
		{
			if (tmp->content < lst->content)
				i++;
			tmp = tmp->next;
		}
		lst->indice = i;
		lst = lst->next;
	}
	lst = save;
	while (save)
	{
		save->content = save->indice;
		save = save->next;
	}
	return (lst);
}

t_stack	init_stacks(t_list *params)
{
	t_stack	stacks;

	stacks.a = params;
	stacks.b = NULL;
	return (stacks);
}
