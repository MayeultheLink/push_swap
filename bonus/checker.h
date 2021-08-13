/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:19:47 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/13 12:02:10 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}				t_stack;

int		param_int(char *p);
t_list	*get_params(char **av);
int		params_doublon(t_list *params);
t_stack	init_stacks(t_list *params);
int		is_sorted_bonus(t_list *lst);
t_stack	cmd_pb_bonus(t_stack stacks);
t_stack	cmd_pa_bonus(t_stack stacks);
t_stack	cmd_ra_bonus(t_stack stacks);
t_stack	cmd_rb_bonus(t_stack stacks);
t_stack	cmd_rr_bonus(t_stack stacks);
t_list	*cmd_r_bonus(t_list *lst);
t_stack	cmd_rra_bonus(t_stack stacks);
t_stack	cmd_rrb_bonus(t_stack stacks);
t_stack	cmd_rrr_bonus(t_stack stacks);
t_list	*cmd_rrab_bonus(t_list *lst);
t_stack	cmd_sa_bonus(t_stack stacks);
t_stack	cmd_sb_bonus(t_stack stacks);
t_stack	cmd_ss_bonus(t_stack stacks);
char	*get_next_line(void);
int		gnl(char **line, int i);
t_stack	sorting(t_stack stacks);
t_stack	sorting_s_p(t_stack stacks, char *cmd);
t_stack	sorting_r(t_stack stacks, char *cmd);
t_stack	sorting_rr(t_stack stacks, char *cmd);
void	free_all(t_stack stacks);

#endif
