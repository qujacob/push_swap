/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:14:30 by qujacob           #+#    #+#             */
/*   Updated: 2021/10/21 16:24:13 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_list **a, int size_a)
{
	t_list	*tmp;

	if (size_a > 1)
	{
		tmp = (*a)->next;
		(*a)->next = (*a)->next->next;
		tmp->next = *a;
		*a = tmp;
	}
}

void	swap_b(t_list **b, int size_b)
{
	t_list	*tmp;

	if (size_b > 1)
	{
		tmp = (*b)->next;
		(*b)->next = (*b)->next->next;
		tmp->next = *b;
		*b = tmp;
	}
}

void	swap_ab(t_tab *tab)
{
	swap_a(&(tab->a), tab->size_a);
	swap_b(&(tab->b), tab->size_b);
}
