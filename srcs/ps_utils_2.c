/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:27:40 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/01 16:48:29 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_list *stack)
{
	t_list	*tmp;
	int		min;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	big_nb_pos(t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		pos;
	int		nb;

	tmp = stack;
	nb = stack->value;
	i = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->value > nb)
		{
			nb = tmp->value;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

int	small_nb_pos(t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		pos;
	int		nb;

	tmp = stack;
	nb = stack->value;
	i = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->value < nb)
		{
			nb = tmp->value;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

int	ft_check_int_limits(const char *str)
{
	int		neg;
	long	res;

	neg = 1;
	if (!(*str))
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	res = 0;
	while (*str && (*str < ':' && *str > '/'))
	{
		res = res * 10 + (*str - 48);
		str++;
		if ((res * neg) < INT_MIN || (res * neg) > INT_MAX)
			return (0);
	}
	if (*str && (*str >= ':' || *str <= '/'))
		return (0);
	return (1);
}
