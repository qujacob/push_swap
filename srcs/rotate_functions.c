/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:14:27 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/01 16:51:01 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*tmp;

	if ((*a) && (a))
	{
		tmp = (*a)->next;
		(*a)->next = NULL;
		ft_lstadd_back(&tmp, *a);
		*a = tmp;
	}
}

void	rotate_b(t_list **b)
{
	t_list	*tmp;

	if ((*b) && (b))
	{
		tmp = (*b)->next;
		(*b)->next = NULL;
		ft_lstadd_back(&tmp, *b);
		*b = tmp;
	}
}

void	rotate_ab(t_tab *tab)
{
	rotate_a(&(tab->a));
	rotate_b(&(tab->b));
}
