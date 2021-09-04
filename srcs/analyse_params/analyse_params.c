/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:56:24 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/04 18:57:01 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
