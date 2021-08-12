/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:57:20 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/12 15:33:07 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]) || !param_int(av[i]))
				return (NULL);
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
