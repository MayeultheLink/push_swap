/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <mde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:31:54 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/17 18:53:16 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*params;
	t_stack	stacks;

	(void)ac;
	if (!av[1])
		return (0);
	params = get_params(av);
	if (!params || !params_doublon(params))
	{
		free_error(params);
		write(1, "Error\n", 6);
		return (0);
	}
	stacks = init_stacks(params);
	stacks = sorting(stacks);
	if (is_sorted_bonus(stacks.a) && !stacks.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(stacks);
	return (0);
}

t_stack	sorting(t_stack stacks)
{
	char	*cmd;

	cmd = get_next_line();
	while (cmd)
	{
		if (cmd[0] == 's' || cmd[0] == 'p')
			stacks = sorting_s_p(stacks, cmd);
		if (cmd[0] == 'r')
			stacks = sorting_r(stacks, cmd);
		if (cmd[0] == 'r' && cmd[1] == 'r')
			stacks = sorting_rr(stacks, cmd);
		free(cmd);
		cmd = NULL;
		cmd = get_next_line();
	}
	return (stacks);
}

t_stack	sorting_s_p(t_stack stacks, char *cmd)
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
	if (cmd[0] == 'p')
	{
		if (cmd[1] == 'a')
			stacks = cmd_pa_bonus(stacks);
		else if (cmd[1] == 'b')
			stacks = cmd_pb_bonus(stacks);
	}
	return (stacks);
}

t_stack	sorting_r(t_stack stacks, char *cmd)
{
	if (cmd[1] == 'a')
		stacks = cmd_ra_bonus(stacks);
	else if (cmd[1] == 'b')
		stacks = cmd_rb_bonus(stacks);
	else if (cmd[1] == 'r' && !cmd[2])
		stacks = cmd_rr_bonus(stacks);
	return (stacks);
}

t_stack	sorting_rr(t_stack stacks, char *cmd)
{
	if (cmd[2] == 'a')
		stacks = cmd_rra_bonus(stacks);
	else if (cmd[2] == 'b')
		stacks = cmd_rrb_bonus(stacks);
	else if (cmd[2] == 'r')
		stacks = cmd_rrr_bonus(stacks);
	return (stacks);
}
