/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:57:20 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/06 15:17:12 by mde-la-s         ###   ########.fr       */
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

t_list	*get_params(int ac, char **av)
{
	t_list	*params;
	int		i;

	params = NULL;
	i = 1;
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
	}
	if (av[i] && av[i][0] == '\0')
		return (NULL);
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
