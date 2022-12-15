/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:19:34 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/05 12:50:43 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_message(t_tab *tab, char *message, int return_value)
{
	free_all(tab);
	ft_putstr_fd(message, 2);
	exit(return_value);
}

int	not_a_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-' || av[i] == '+')
		i++;
	while (av[i])
	{
		if (!ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_duplicates(t_list *a)
{
	t_list	*i;
	t_list	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

void	catch_errors(int ac, char *av[])
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (not_a_number(av[i]) || !ft_check_int_limits(av[i]))
			error_message(NULL, "Error\n", 1);
	}
}
