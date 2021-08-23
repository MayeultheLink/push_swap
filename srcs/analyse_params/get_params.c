/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:57:20 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/23 23:47:48 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	param_int(char *p)
{
	int	i;

	i = 0;
	if (p[0] == '-')
		i++;
	if (ft_strlen(p) <= 9 || (p[0] == '-' && ft_strlen(p) <= 10))
		return (1);
	else if ((p[0] != '-' && ft_strlen(p) > 10) || ft_strlen(p) > 11)
		return (0);
	else if (p[i + 9] <= '8')
	{
		if (p[0] != '-' && p[9] == '8')
			return (0);
		if (p[i + 8] <= '4')
			if (p[i + 7] <= '6')
				if (p[i + 6] <= '3')
					if (p[i + 5] <= '8')
						if (p[i + 4] <= '4')
							if (p[i + 3] <= '7')
								if (p[i + 2] <= '4')
									if (p[i + 1] <= '1')
										if (p[i] <= '2')
											return (1);
	}
	return (0);
}

t_list	*get_params(char **av)
{
	t_list	*params;
	t_list	*tmp;
	int		i;
	int		j;

	params = NULL;
	tmp = NULL;
	i = 1;
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
	}
	params = get_indice(params);
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

int	params_doublon(t_list *params)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = params;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (1)
		{
			if (tmp1->content == tmp2->content)
				return (0);
			if (!tmp2->next)
				break ;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

t_stack	init_stacks(t_list *params)
{
	t_stack	stacks;

	stacks.a = params;
	stacks.b = NULL;
	return (stacks);
}
