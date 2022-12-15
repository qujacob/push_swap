/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:46:08 by qujacob           #+#    #+#             */
/*   Updated: 2021/10/23 18:24:16 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	optimizer_push(t_tab *tab)
{
	int	pos;

	pos = 0;
	while (tab->size_a > 2)
	{
		pos = small_nb_pos(tab->a);
		if (pos == 0)
			do_op("pb", 0, tab);
		else if (pos >= tab->size_a / 2)
			do_op("rra", 0, tab);
		else
			do_op("ra", 0, tab);
	}
}

void	push_all_a(t_tab *tab)
{
	int	pos;
	int	count;

	while (tab->size_b)
	{
		pos = find_pos_stack_asc(tab->b->value, tab->a);
		if (pos >= tab->size_a - pos)
			count = tab->size_a - pos;
		else if (pos < tab->size_a / 2)
			count = pos;
		while (count)
		{
			if (pos >= tab->size_a / 2)
				do_op("rra", 0, tab);
			else
				do_op("ra", 0, tab);
			count--;
		}
		do_op("pa", 0, tab);
	}
	final_rotate(tab);
}

void	final_rotate(t_tab *tab)
{
	int	pos;
	int	count;

	pos = small_nb_pos(tab->a);
	if (pos >= tab->size_a / 2)
		count = tab->size_a - pos;
	else
		count = pos;
	while (count)
	{
		if (pos >= tab->size_a / 2)
			do_op("rra", 0, tab);
		else
			do_op("ra", 0, tab);
		count--;
	}
}
