/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:49:06 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/07/30 16:19:18 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->content != tmp->next->content - 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		size_suite(t_list *lst)
{
	t_list	*tmp;
	int		i;
	int		size;
	int		content;

	tmp = lst->next;
	content = lst->content;
	i = 1;
	size = 1;

	while (tmp)
	{
		while (tmp && tmp->content == content + 1)
		{
			i++;
			tmp = tmp->next;
			content++;
		}
		if (size < i)
			size = i;
		i = 1;
		if (tmp)
		{
			content = tmp->content;
			tmp = tmp->next;
		}
	}
	return (size);
}

int		pos_suite(t_list *lst, int suite_size)
{
	t_list	*tmp;
	int		pos;
	int		i;
	int		content;

	tmp = lst->next;
	content = lst->content;
	pos = 0;
	i = 1;

	while (tmp)
	{
		while (tmp && tmp->content == content + 1)
		{
			i++;
			if (i == suite_size)
				return (pos);
			tmp = tmp->next;
			content++;
		}
		pos += i;
		i = 1;
		if (tmp)
		{
			content = tmp->content;
			tmp = tmp->next;
		}
	}
	return (pos);
}

int		lst_content(t_list *lst, int min, int max)
{
	while (lst)
	{
		if (lst->content >= min && lst->content < max)
			return (0);
		lst = lst->next;
	}
	return (1);
}
