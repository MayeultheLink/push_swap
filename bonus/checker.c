/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <mde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:31:54 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/12 02:00:12 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_list *params)
{
	t_stack	stacks;
	char	*cmd;

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
	if (is_sorted_bonus(stacks.a) && !stacks.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	gnl(char **line, int i)
{
	char    buf;
	int    ret;

	ret = read(STDIN_FILENO, &buf, 1);
	write(1, "F", 1);
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

char	*get_next_line()
{
	char	*line;

	if (gnl(&line, 0) == 1)
		return (line);
	return (NULL);
}
