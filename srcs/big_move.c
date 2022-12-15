/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:02:19 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/01 16:13:10 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_move_ab(t_move *move)
{
	if (move->revrotate_a == move->revrotate_b)
	{
		if (move->moves_a < move->moves_b)
		{
			move->moves_ab = move->moves_a;
			move->moves_b -= move->moves_a;
			move->moves_a = 0;
		}
		else if (move->moves_a > move->moves_b)
		{
			move->moves_ab = move->moves_b;
			move->moves_a -= move->moves_b;
			move->moves_b = 0;
		}
		else
		{
			move->moves_ab = move->moves_a;
			move->moves_a = 0;
			move->moves_b = 0;
		}
	}
	else
		move->moves_ab = 0;
	move->total = move->moves_a + move->moves_b + move->moves_ab;
}

void	new_best_move(t_move *move, t_move *best_move)
{
	best_move->moves_a = move->moves_a;
	best_move->moves_b = move->moves_b;
	best_move->moves_ab = move->moves_ab;
	best_move->revrotate_a = move->revrotate_a;
	best_move->revrotate_b = move->revrotate_b;
	best_move->total = move->total;
}

t_move	*init_move(void)
{
	t_move	*move;

	move = (t_move *)malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	move->moves_a = 0;
	move->moves_b = 0;
	move->moves_ab = 0;
	move->revrotate_a = false;
	move->revrotate_b = false;
	return (move);
}

void	move_a(t_move *move, int pos, t_tab *tab)
{
	if (pos >= tab->size_a / 2)
	{
		move->moves_a = tab->size_a - pos;
		move->revrotate_a = true;
	}
	else
	{
		move->moves_a = pos;
		move->revrotate_a = false;
	}
}

void	move_b(t_move *move, int nb, t_tab *tab)
{
	int	pos;

	pos = find_pos_stack_desc(nb, tab->b);
	if (pos >= tab->size_b / 2)
	{
		move->moves_b = tab->size_b - pos;
		move->revrotate_b = true;
	}
	else
	{
		move->moves_b = pos;
		move->revrotate_b = false;
	}
}
