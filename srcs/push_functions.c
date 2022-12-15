/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:14:20 by qujacob           #+#    #+#             */
/*   Updated: 2021/10/21 16:25:10 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_tab *tab, t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tab->size_b--;
		tmp->next = *a;
		*a = tmp;
		tab->size_a++;
	}
}

void	push_b(t_tab *tab, t_list **b, t_list **a)
{
	t_list	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tab->size_a--;
		tmp->next = *b;
		*b = tmp;
		tab->size_b++;
	}
}
