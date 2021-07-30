/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:04:49 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/07/02 21:35:47 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelone(t_list *lst, int content)
{
	t_list	*previous;
	t_list	*next;

	previous = lst;
	next = lst;
	if (lst && lst->next && lst->content == content)
	{
		lst = lst->next;
		previous = NULL;
		free(previous);
		return (lst);
	}
	while (next && next->next && next->content != content)
		next = next->next;
	if (next && next->next && next->content == content)
	{
		while (previous && previous->next)
		{
			if (previous->next->content == content)
				break ;
			previous = previous->next;
		}
		previous->next = next->next;
		free(next);
	}
	return (lst);
}
