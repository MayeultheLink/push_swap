/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:23:03 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/07/07 20:18:43 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pos_min(t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		content;

	tmp = lst;
	content = tmp->content;
	while (tmp)
	{
		if (content > tmp->content)
			content = tmp->content;
		tmp = tmp->next;
	}
	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (tmp->content == content)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	pos_min2(t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		content;

	tmp = lst;
	content = tmp->content;
	while (tmp)
	{
		if (content > tmp->content)
			content = tmp->content;
		tmp = tmp->next;
	}
	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (tmp->content == content + 1)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	pos_max(t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		content;

	tmp = lst;
	content = tmp->content;
	while (tmp)
	{
		if (content < tmp->content)
			content = tmp->content;
		tmp = tmp->next;
	}
	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (tmp->content == content)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}
