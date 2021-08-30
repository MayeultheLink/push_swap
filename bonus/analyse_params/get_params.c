/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:57:20 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/30 14:57:22 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	param_int(char *p)
{
	int		paramint;
	char	*paramchar;

	paramint = ft_atoi(p);
	paramchar = ft_itoa(paramint);
	if (ft_strcmp(p, paramchar))
	{
		free(paramchar);
		paramchar = NULL;
		return (1);
	}
	free(paramchar);
	paramchar = NULL;
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
	return (params);
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
