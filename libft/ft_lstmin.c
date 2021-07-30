/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:34:34 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/06/11 14:42:02 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmin(t_list *lst)
{
	int	content;

	content = lst->content;
	while (lst->next)
	{
		while (lst->next && content < lst->next->content)
			lst = lst->next;
		if (lst->next)
		{
			lst = lst->next;
			content = lst->content;
		}
	}
	return (content);
}
