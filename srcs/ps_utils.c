/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 04:03:38 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/02 11:15:53 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_last(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->value);
}

int	is_min(t_list *a)
{
	int	stock;

	stock = a->value;
	while (a)
	{
		if (a->value < stock)
			return (0);
		a = a->next;
	}
	return (1);
}

void	put_min_first(t_list **a, t_tab *tab)
{
	while (!is_min(*a))
	{
		if ((*a)->value > get_last(*a) \
		&& (*a)->next->value > get_last(*a) \
		&& (*a)->next->next->value > get_last(*a))
			do_op("rra", 0, tab);
		else
			do_op("ra", 0, tab);
	}
}

int	is_sorted(t_list *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	do_op(char *op, int checker, t_tab *tab)
{
	if (!ft_strncmp(op, "pa", 2))
		push_a(tab, &(tab->a), &(tab->b));
	else if (!ft_strncmp(op, "pb", 2))
		push_b(tab, &(tab->b), &(tab->a));
	else if (!ft_strncmp(op, "sa", 2))
		swap_a(&(tab->a), tab->size_a);
	else if (!ft_strncmp(op, "sb", 2))
		swap_a(&(tab->b), tab->size_b);
	else if (!ft_strncmp(op, "ss", 2))
		swap_ab(tab);
	else if (!ft_strncmp(op, "rra", 3))
		revrotate_a(&(tab->a));
	else if (!ft_strncmp(op, "rrb", 3))
		revrotate_b(&(tab->b));
	else if (!ft_strncmp(op, "rrr", 3))
		revrotate_ab(tab);
	else if (!ft_strncmp(op, "ra", 2))
		rotate_a(&(tab->a));
	else if (!ft_strncmp(op, "rb", 2))
		rotate_b(&(tab->b));
	else if (!ft_strncmp(op, "rr", 2))
		rotate_ab(tab);
	else
		error_message(tab, "Error\n", 1);
	ft_putstrnl(op, checker);
}
