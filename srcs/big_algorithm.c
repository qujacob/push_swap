/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:17:25 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/01 18:34:01 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_algorithm(t_tab *tab)
{
	int		optimizer;
	t_move	*best_move;

	if (tab->size_a > 200)
		optimizer = 50;
	else
		optimizer = 1;
	do_op("pb", 0, tab);
	do_op("pb", 0, tab);
	while (tab->size_a > optimizer)
	{
		best_move = search_moves(tab);
		do_best_move(best_move, tab);
		free(best_move);
	}
	optimizer_push(tab);
	push_all_a(tab);
}

t_move	*search_moves(t_tab *tab)
{
	t_move	*best_move;
	t_move	*move;
	t_list	*tmp;
	int		pos;

	pos = 0;
	move = init_move();
	best_move = init_move();
	tmp = tab->a;
	move_a(best_move, pos, tab);
	move_b(best_move, tmp->value, tab);
	set_move_ab(best_move);
	while (tmp)
	{
		move_a(move, pos, tab);
		move_b(move, tmp->value, tab);
		set_move_ab(move);
		if (best_move->total > move->total)
			new_best_move(move, best_move);
		pos++;
		tmp = tmp->next;
	}
	free(move);
	return (best_move);
}

void	do_best_move(t_move *move, t_tab *tab)
{
	while (move->moves_ab > 0)
	{
		if (move->revrotate_a == true && move->revrotate_b == true)
			do_op("rrr", 0, tab);
		else
			do_op("rr", 0, tab);
		move->moves_ab--;
	}
	while (move->moves_a-- > 0)
	{
		if (move->revrotate_a == true)
			do_op("rra", 0, tab);
		else
			do_op("ra", 0, tab);
	}
	while (move->moves_b-- > 0)
	{
		if (move->revrotate_b == true)
			do_op("rrb", 0, tab);
		else
			do_op("rb", 0, tab);
	}
	do_op("pb", 0, tab);
}

int	find_pos_stack_desc(int nb, t_list *stack)
{
	t_list	*tmp;
	int		pos;
	int		prev_nb;

	pos = 0;
	tmp = stack;
	if (nb > get_max(tmp))
		return (big_nb_pos(stack));
	if (nb < get_min(tmp))
		return (small_nb_pos(stack) + 1);
	prev_nb = stack->value;
	while (tmp)
	{
		if (prev_nb > nb && nb > tmp->value)
			return (pos);
		prev_nb = tmp->value;
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

int	find_pos_stack_asc(int nb, t_list *stack)
{
	t_list	*tmp;
	int		pos;
	int		prev_nb;

	pos = 0;
	tmp = stack;
	if (nb > get_max(tmp))
		return (big_nb_pos(stack) + 1);
	if (nb < get_min(tmp))
		return (small_nb_pos(stack));
	prev_nb = stack->value;
	while (tmp)
	{
		if (prev_nb < nb && nb < tmp->value)
			return (pos);
		prev_nb = tmp->value;
		tmp = tmp->next;
		pos++;
	}
	return (0);
}
