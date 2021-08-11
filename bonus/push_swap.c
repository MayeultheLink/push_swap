/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:24:58 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/12 01:22:14 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*params_save;
	t_list	*params;
	t_stack	stacks;

	(void)ac;
	if (!av[1])
		return (0);
	params_save = get_params(av);
	params = get_indice(params_save);
	if (!params || !params_doublon(params))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (is_sorted(params))
		return (0);
	stacks = init_stacks(params);
	if (ft_lstsize(stacks.a) <= 5)
		stacks = sort_stacksa(stacks);
	else if (ft_lstsize(stacks.a) <= 200)
		stacks = sorting_200(stacks);
	else
		stacks = sorting_500(stacks);
	checker(params_save);
	free_all(stacks);
	return (0);
}

void	checker(t_list params)
{
	t_stacks	stacks;
	char		*cmd;

	stacks = init_stacks(params);
	cmd = get_next_line();
	while (cmd)
	{
		if (cmd[0] == 's')
		{
			if (cmd[1] == 'a')
				stacks = cmd_sa_bonus(stacks);
			else if (cmd[1] == 'b')
				stacks = cmd_sb_bonus(stacks);
			else if (cmd[1] == 's')
				stacks = cmd_ss_bonus(stacks);
		}
		if (cmd[0] == 'r')
		{
			if (cmd[1] == 'a')
				stacks = cmd_ra_bonus(stacks);
			else if (cmd[1] == 'b')
				stacks = cmd_rb_bonus(stacks);
			else if (cmd[1] == 'r' && !cmd[2])
				stacks = cmd_rr_bonus(stacks);
		}
		if (cmd[0] == 'r' && cmd[1] == 'r')
		{
			if (cmd[2] == 'a')
				stacks = cmd_rra_bonus(stacks);
			else if (cmd[2] == 'b')
				stacks = cmd_rrb_bonus(stacks);
			else if (cmd[2] == 'r')
				stacks = cmd_rrr_bonus(stacks);
		}
		if (cmd[0] == 'p')
		{
			if (cmd[1] == 'a')
				stacks = cmd_pa_bonus(stacks);
			else if (cmd[1] == 'b')
				stacks = cmd_pb_bonus(stacks);
		}
		free(cmd);
		cmd = NULL;
		cmd = get_next_line();
	}
	if (is_sorted(stacks.a) && !stacks.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	gnl(char **line, int i)
{
	char    buf;
	int    ret;

	ret = read(STDIN_FILENO, &buf, 1);
	if (ret == 1 && buf != '\n')
	{
		ret = gnl(line, i + 1, fd);
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

char	*get_next_line()
{
	char	*line;

	if (gnl(&line, 0))
		return (line);
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
