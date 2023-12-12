/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:19:47 by mde-la-s          #+#    #+#             */
/*   Updated: 2023/12/03 17:57:11 by mde-la-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}				t_stacks;

typedef struct s_pos
{
	int	min;
	int	min2;
	int	max;
	int	size;
	int	suite;
}				t_pos;

int		free_all(t_stacks stacks);
t_list	*free_error(t_list *params);
int		param_int(char *p);
t_list	*get_params(char **av);
t_list	*get_params2(char **av, int i);
t_list	*get_indice(t_list *lst);
int		params_doublon(t_list *params);
t_stacks	init_stacks(t_list *params);
int		pos_min(t_list *lst);
int		pos_min2(t_list *lst);
int		pos_max(t_list *lst);
int		is_sorted(t_list *lst);
int		is_reverse_sorted(t_list *lst);
int		size_suite(t_list *lst);
int		pos_suite(t_list *lst, int pos_size);
int		lst_content(t_list *lst, int min, int max);
void	cmd_pb(t_stacks* stacks);
void	cmd_pa(t_stacks* stacks);
void	cmd_ra(t_stacks* stacks);
void	cmd_rb(t_stacks* stacks);
void	cmd_rr(t_stacks* stacks);
t_list	*cmd_r(t_list *lst);
void	cmd_rra(t_stacks* stacks);
void	cmd_rrb(t_stacks* stacks);
void	cmd_rrr(t_stacks* stacks);
t_list	*cmd_rrab(t_list *lst);
void	cmd_sa(t_stacks* stacks);
void	cmd_sb(t_stacks* stacks);
void	cmd_ss(t_stacks* stacks);
void	sort_stacksa(t_stacks* stacks);
void	sort_3(t_stacks* stacks);
void	sort_4(t_stacks* stacks);
void	sort_5(t_stacks* stacks);
void	sort_5_suite_3(t_stacks* stacks, t_pos pos);
void	sort_5_no_suite(t_stacks* stacks, t_pos pos);
void	no_suite_1(t_stacks* stacks, t_pos pos);
void	no_suite_2(t_stacks* stacks, t_pos pos);
void	no_suite_3(t_stacks* stacks, t_pos pos);
void	no_suite_3bis(t_stacks* stacks, t_pos pos);
void	no_suite_4(t_stacks* stacks, t_pos pos);
void	no_suite_5(t_stacks* stacks, t_pos pos);
void	no_suite_6(t_stacks* stacks, t_pos pos);
void	no_suite_7(t_stacks* stacks, t_pos pos);
void	no_suite_7bis(t_stacks* stacks, t_pos pos);
void	no_suite_8(t_stacks* stacks);
void	pos_suite_0(t_stacks* stacks);
void	pos_suite_1(t_stacks* stacks, t_pos pos);
void	pos_suite_2(t_stacks* stacks, t_pos pos);
void	chunks_a2b(t_stacks* stacks, int min, int max);
void	chunks_b2a(t_stacks* stacks, int min, int max);
void	sorting(t_stacks* stacks);
void	a2b_until_sorted(t_stacks* stacks);
void	sorting_200(t_stacks* stacks);
void	sorting_500(t_stacks* stacks);
void bubble_sort(t_stacks* stacks);
void insertion_sort(t_stacks* stacks);
void selection_sort(t_stacks* stacks);
void merge_sort(t_stacks* stacks);
void quick_sort(t_stacks* stacks);
void radix_sort(t_stacks* stacks);
void my_sort(t_stacks* stacks);
void rotate_to_find_value_in_a(t_stacks* stacks, int value);
void rotate_to_find_value_in_b(t_stacks* stacks, int value);
int min_value(t_list* stack);
int max_value(t_list* stack);
int find_nearest_value_in_range(t_list* stack, int min, int max);

#endif
