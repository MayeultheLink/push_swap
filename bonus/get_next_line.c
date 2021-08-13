/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:45:31 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/13 12:34:50 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	gnl(char **line, int i)
{
	char	buf;
	int		ret;

	ret = read(STDIN_FILENO, &buf, 1);
	if (ret == 1 && buf != '\n')
	{
		ret = gnl(line, i + 1);
		if (ret != -1)
			(*line)[i] = buf;
	}
	else if (ret != -1)
	{
		*line = (char *)malloc(sizeof(char) * (i + 1));
		if (*line != NULL)
			(*line)[i] = '\0';
		else
			ret = -1;
	}
	return (ret);
}

char	*get_next_line(void)
{
	char	*line;

	if (gnl(&line, 0) == 1)
		return (line);
	free(line);
	line = NULL;
	return (NULL);
}

void	free_all(t_stack stacks)
{
	t_list	*tmp;

	while (stacks.a)
	{
		tmp = stacks.a;
		stacks.a = stacks.a->next;
		free(tmp);
		tmp = NULL;
	}
	while (stacks.b)
	{
		tmp = stacks.b;
		stacks.b = stacks.b->next;
		free(tmp);
		tmp = NULL;
	}
}
