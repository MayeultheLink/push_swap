/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <mde-la-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:31:54 by mde-la-s          #+#    #+#             */
/*   Updated: 2023/12/03 15:56:14 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*params;
	t_stack	stacks;

	if (ac == 1)
		return (0);
	params = get_params(ac, av);
	if (params == NULL || !params_doublon(params))
	{
		free_error(params);
		write(1, "Error\n", 6);
		return (0);
	}
	stacks = init_stacks(params);
	stacks = sorting(stacks);

/*      while (stacks.a)
         {
                 printf("a : %d\n", stacks.a->content);
                 stacks.a = stacks.a->next;
         }
         while (stacks.b)
         {
                 printf("b : %d\n", stacks.b->content);
                 stacks.b = stacks.b->next;
         }
*/
	if (stacks.a && is_sorted_bonus(stacks.a) && !stacks.b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(stacks);
	return (0);
}

t_stack	sorting(t_stack stacks)
{
	char	*cmd;
int i = 0;
	cmd = get_next_line();
	while (cmd)
	{
printf("cmd %d = %s\n", ++i, cmd);
		if (cmd[0] == 's' || cmd[0] == 'p')
			stacks = sorting_s_p(stacks, cmd);
		else if (cmd[0] == 'r')
			stacks = sorting_r(stacks, cmd);
		else
		{
			free_all(stacks);
			stacks.a = NULL;
			write(1, "Error\n", 6);
			free(cmd);
			cmd = NULL;
			return (stacks);
		}
		free(cmd);
		cmd = NULL;
		if (!stacks.a)
			return (stacks);
		cmd = get_next_line();
	}
	return (stacks);
}

t_stack	sorting_s_p(t_stack stacks, char *cmd)
{
	if (cmd[0] == 's' && cmd[1] == 'a' && !cmd[2])
		stacks = cmd_sa_bonus(stacks);
	else if (cmd[0] == 's' && cmd[1] == 'b' && !cmd[2])
		stacks = cmd_sb_bonus(stacks);
	else if (cmd[0] == 's' && cmd[1] == 's' && !cmd[2])
		stacks = cmd_ss_bonus(stacks);
	else if (cmd[0] == 'p' && cmd[1] == 'a' && !cmd[2])
		stacks = cmd_pa_bonus(stacks);
	else if (cmd[0] == 'p' && cmd[1] == 'b' && !cmd[2])
		stacks = cmd_pb_bonus(stacks);
	else
	{
		free_all(stacks);
		stacks.a = NULL;
		stacks.b = NULL;
		write(1, "Error\n", 6);
	}
	return (stacks);
}

t_stack	sorting_r(t_stack stacks, char *cmd)
{
	if (cmd[0] == 'r' && cmd[1] == 'a' && !cmd[2])
		stacks = cmd_ra_bonus(stacks);
	else if (cmd[0] == 'r' && cmd[1] == 'b' && !cmd[2])
		stacks = cmd_rb_bonus(stacks);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && !cmd[2])
		stacks = cmd_rr_bonus(stacks);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'a' && !cmd[3])
		stacks = cmd_rra_bonus(stacks);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'b' && !cmd[3])
		stacks = cmd_rrb_bonus(stacks);
	else if (cmd[0] == 'r' && cmd[1] == 'r' && cmd[2] == 'r' && !cmd[3])
		stacks = cmd_rrr_bonus(stacks);
	else
	{
		free_all(stacks);
		stacks.a = NULL;
		stacks.b = NULL;
		write(1, "Error\n", 6);
	}
	return (stacks);
}
