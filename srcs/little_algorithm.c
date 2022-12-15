/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 23:10:04 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/01 18:06:12 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_algorithm(t_tab *tab)
{
	while (!is_sorted(tab->a))
	{
		if ((tab->a->value > get_last(tab->a) && \
		tab->a->value > tab->a->next->value))
			do_op("ra", 0, tab);
		if (tab->a->value > tab->a->next->value)
			do_op("sa", 0, tab);
		if (!is_sorted(tab->a))
			do_op("rra", 0, tab);
	}
}

void	four_algorithm(t_tab *tab)
{
	if (!is_sorted(tab->a))
		put_min_first(&(tab->a), tab);
	if (!is_sorted(tab->a))
	{
		do_op("pb", 0, tab);
		three_algorithm(tab);
		do_op("pa", 0, tab);
	}
}

void	five_algorithm(t_tab *tab)
{
	if (!is_sorted(tab->a))
		put_min_first(&(tab->a), tab);
	if (!is_sorted(tab->a))
	{
		do_op("pb", 0, tab);
		four_algorithm(tab);
		do_op("pa", 0, tab);
	}
}
