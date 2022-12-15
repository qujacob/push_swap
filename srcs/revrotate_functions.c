/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:14:16 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/02 14:21:45 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	revrotate_a(t_list **a)
{
	t_list	*tmp;

	if ((*a) && (a))
	{
		tmp = *a;
		if (tmp->next)
			while (tmp->next->next)
				tmp = tmp->next;
		ft_lstadd_front(a, tmp->next);
		tmp->next = NULL;
	}
}

void	revrotate_b(t_list **b)
{
	t_list	*tmp;

	if ((*b) && (b))
	{
		tmp = *b;
		if (tmp->next)
			while (tmp->next->next)
				tmp = tmp->next;
		ft_lstadd_front(b, tmp->next);
		tmp->next = NULL;
	}
}

void	revrotate_ab(t_tab *tab)
{
	revrotate_a(&(tab->a));
	revrotate_b(&(tab->b));
}
