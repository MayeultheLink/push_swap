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

t_list* duplicate_list(t_list* list)
{
	t_list* new_list = NULL;
	t_list* tmp = NULL;

	while (list)
	{
		tmp = ft_lstnew(list->content);
		ft_lstadd_back(&new_list, tmp);
		list = list->next;
	}

	return (new_list);
}

void free_list(t_list* list)
{
	t_list* tmp;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void replace_content_with_index(t_list* list)
{
	t_list* index = duplicate_list(list);
	t_list* save_index = index;
	t_list* save_list = list;
	int i = 0;

	while (index)
	{
		list = save_list;
		while (list)
		{
			if (index->content > list->content)
				i++;
			list = list->next;
		}
		index->content = i;
		i = 0;
		index = index->next;
	}

	list = save_list;
	index = save_index;
	while (index)
	{
		list->content = index->content;
		list = list->next;
		index = index->next;
	}

	free_list(save_index);
}

char** duplicate_params(char** av)
{	
	char** params;
	int nbr_of_params = ft_tab_of_str_len(av) - 1;

	if (nbr_of_params == 1)
		params = ft_split(av[1], " ");
	else
	{
		params = (char**)malloc((sizeof(char*)) * (nbr_of_params + 1));
		if (!params)
			return (NULL);
		params[nbr_of_params] = NULL;
		for (int i = 0; i < nbr_of_params; i++)
		{
			params[i] = ft_strdup(av[i + 1]);
			if (!params[i])
			{
				ft_free_double_ptr(params);
				return (NULL);
			}
		}
	}

	return (params);
}

t_list *get_params(char **av)
{
	char** params = duplicate_params(av);
	char* itoa;

	t_list* stack = NULL;
	t_list* tmp = NULL;
	for (int i = 0; i < ft_tab_of_str_len(params); i++)
	{
		itoa = ft_itoa(ft_atoi(params[i]));
		if (!ft_strncmp(params[i], itoa, ft_strlen(params[i])))
		{
			tmp = ft_lstnew(ft_atoi(params[i]));
			ft_lstadd_back(&stack, tmp);
		}
		else
		{
			free(itoa);
			ft_free_double_ptr(params);
			return (NULL);
		}
		free(itoa);
	}
	ft_free_double_ptr(params);

	replace_content_with_index(stack);

	return (stack);

}