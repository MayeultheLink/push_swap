/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:19:47 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/09/06 13:59:55 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}				t_stacks;

int		param_int(char *p);
t_list	*get_params(int ac, char **av);
t_list	*get_params2(char **av, int i);
int		params_doublon(t_list *params);
t_stacks	init_stacks(t_list *params);
int		is_sorted_bonus(t_list *lst);
t_stacks	cmd_pb_bonus(t_stacks stacks);
t_stacks	cmd_pa_bonus(t_stacks stacks);
t_stacks	cmd_ra_bonus(t_stacks stacks);
t_stacks	cmd_rb_bonus(t_stacks stacks);
t_stacks	cmd_rr_bonus(t_stacks stacks);
t_list	*cmd_r_bonus(t_list *lst);
t_stacks	cmd_rra_bonus(t_stacks stacks);
t_stacks	cmd_rrb_bonus(t_stacks stacks);
t_stacks	cmd_rrr_bonus(t_stacks stacks);
t_list	*cmd_rrab_bonus(t_list *lst);
t_stacks	cmd_sa_bonus(t_stacks stacks);
t_stacks	cmd_sb_bonus(t_stacks stacks);
t_stacks	cmd_ss_bonus(t_stacks stacks);
char	*get_next_line(void);
int		gnl(char **line, int i);
t_stacks	sorting(t_stacks stacks);
t_stacks	sorting_s_p(t_stacks stacks, char *cmd);
t_stacks	sorting_r(t_stacks stacks, char *cmd);
t_stacks	sorting_rr(t_stacks stacks, char *cmd);
void	free_all(t_stacks stacks);
t_list	*free_error(t_list *params);

#endif
