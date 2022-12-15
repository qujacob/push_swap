/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:21:12 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/01 18:59:30 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include "libft.h"

typedef enum e_bool {
	false,
	true
}	t_bool;

typedef struct s_tab
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
	int		final_size_a;
}	t_tab;

typedef struct s_move
{
	int		moves_a;
	int		moves_b;
	int		moves_ab;
	int		total;
	t_bool	revrotate_a;
	t_bool	revrotate_b;
}	t_move;

void	free_all(t_tab *tab);
void	create_a(t_tab *tab, t_list **a, int ac, char *av[]);
t_tab	*initialize_tab(int ac, char *av[]);
void	algorithm_selector(t_tab *tab);

void	error_message(t_tab *tab, char *message, int return_value);
int		not_a_number(char *av);
int		check_duplicates(t_list *a);
void	catch_errors(int ac, char *av[]);

void	swap_a(t_list **a, int size_a);
void	swap_b(t_list **b, int size_b);
void	swap_ab(t_tab *tab);
void	push_a(t_tab *tab, t_list **a, t_list **b);
void	push_b(t_tab *tab, t_list **b, t_list **a);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_ab(t_tab *tab);
void	revrotate_a(t_list **a);
void	revrotate_b(t_list **b);
void	revrotate_ab(t_tab *tab);

void	two_algorithm(t_tab *tab);
void	three_algorithm(t_tab *tab);
void	four_algorithm(t_tab *tab);
void	five_algorithm(t_tab *tab);

void	big_algorithm(t_tab *tab);
t_move	*search_moves(t_tab *tab);
void	do_best_move(t_move *move, t_tab *tab);
int		find_pos_stack_desc(int nb, t_list *stack);
int		find_pos_stack_asc(int nb, t_list *stack);

void	set_move_ab(t_move *move);
void	new_best_move(t_move *move, t_move *best_move);
t_move	*init_move(void);
void	move_a(t_move *move, int pos, t_tab *tab);
void	move_b(t_move *move, int nb, t_tab *tab);

void	optimizer_push(t_tab *tab);
void	push_all_a(t_tab *tab);
void	final_rotate(t_tab *tab);

int		get_last(t_list *stack);
void	print_stack(t_list *stack);
int		is_min(t_list *a);
void	put_min_first(t_list **a, t_tab *tab);
int		is_sorted(t_list *a);
void	do_op(char *op, int checker, t_tab *tab);
int		get_max(t_list *stack);
int		get_min(t_list *stack);
int		big_nb_pos(t_list *stack);
int		small_nb_pos(t_list *stack);
int		ft_check_int_limits(const char *str);

#endif
