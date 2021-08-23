/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:19:47 by mde-la-s          #+#    #+#             */
/*   Updated: 2021/08/14 22:03:40 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}				t_stack;

typedef struct s_pos
{
	int	min;
	int	min2;
	int	max;
	int	size;
	int	suite;
}				t_pos;

void	free_all(t_stack stacks);
t_list	*free_error(t_list *params);
int		param_int(char *p);
t_list	*get_params(char **av);
t_list	*get_indice(t_list *lst);
int		params_doublon(t_list *params);
t_stack	init_stacks(t_list *params);
int		pos_min(t_list *lst);
int		pos_min2(t_list *lst);
int		pos_max(t_list *lst);
int		is_sorted(t_list *lst);
int		size_suite(t_list *lst);
int		pos_suite(t_list *lst, int pos_size);
int		lst_content(t_list *lst, int min, int max);
t_stack	cmd_pb(t_stack stacks);
t_stack	cmd_pa(t_stack stacks);
t_stack	cmd_ra(t_stack stacks);
t_stack	cmd_rb(t_stack stacks);
t_stack	cmd_rr(t_stack stacks);
t_list	*cmd_r(t_list *lst);
t_stack	cmd_rra(t_stack stacks);
t_stack	cmd_rrb(t_stack stacks);
t_stack	cmd_rrr(t_stack stacks);
t_list	*cmd_rrab(t_list *lst);
t_stack	cmd_sa(t_stack stacks);
t_stack	cmd_sb(t_stack stacks);
t_stack	cmd_ss(t_stack stacks);
t_stack	sort_stacksa(t_stack stacks);
t_stack	sort_3(t_stack stacks);
t_stack	sort_4(t_stack stacks);
t_stack	sort_5(t_stack stacks);
t_stack	sort_5_suite_3(t_stack stacks, t_pos pos);
t_stack	sort_5_no_suite(t_stack stacks, t_pos pos);
t_stack	no_suite_1(t_stack stacks, t_pos pos);
t_stack	no_suite_2(t_stack stacks, t_pos pos);
t_stack	no_suite_3(t_stack stacks, t_pos pos);
t_stack	no_suite_3bis(t_stack stacks, t_pos pos);
t_stack	no_suite_4(t_stack stacks, t_pos pos);
t_stack	no_suite_5(t_stack stacks, t_pos pos);
t_stack	no_suite_6(t_stack stacks, t_pos pos);
t_stack	no_suite_7(t_stack stacks, t_pos pos);
t_stack	no_suite_7bis(t_stack stacks, t_pos pos);
t_stack	no_suite_8(t_stack stacks);
t_stack	pos_suite_0(t_stack stacks);
t_stack	pos_suite_1(t_stack stacks, t_pos pos);
t_stack	pos_suite_2(t_stack stacks, t_pos pos);
t_stack	chunks_a2b(t_stack stacks, int min, int max);
t_stack	chunks_b2a(t_stack stacks, int min, int max);
t_stack	sorting(t_stack stacks);
t_stack	a2b_until_sorted(t_stack stacks);
t_stack	sorting_200(t_stack stacks);
t_stack	sorting_500(t_stack stacks);

#endif
