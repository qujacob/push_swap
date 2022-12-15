/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:00:27 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/02 14:24:11 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_tab *tab)
{
	if (tab)
	{
		if (tab->a)
			ft_lstclear(&(tab->a));
		if (tab->b)
			ft_lstclear(&(tab->b));
		free(tab);
	}
}

void	create_a(t_tab *tab, t_list **a, int ac, char *av[])
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (++i < ac)
	{
		tmp = ft_lstnew(ft_atoi(av[i]));
		if (!tmp)
			error_message(tab, "Error\n", 1);
		ft_lstadd_back(a, tmp);
		tmp = tmp->next;
	}
	ft_lstclear(&tmp);
	if (!check_duplicates(*a))
		error_message(tab, "Error\n", 1);
}

t_tab	*initialize_tab(int ac, char *av[])
{
	t_tab	*tab;

	tab = (t_tab *)malloc(sizeof(t_tab));
	if (!tab)
		error_message(tab, "Error\n", 1);
	tab->a = NULL;
	tab->b = NULL;
	create_a(tab, &(tab->a), ac, av);
	tab->size_a = ac - 1;
	tab->size_b = 0;
	tab->final_size_a = tab->size_a;
	return (tab);
}

int	ft_scan(t_tab *tab)
{
	char	*buffer;
	int		size;

	buffer = (char *)malloc(sizeof(char) * 5);
	size = read(0, buffer, 4);
	if (size == -1)
		error_message(tab, "Error\n", 1);
	while (size)
	{
		do_op(buffer, 1, tab);
		size = read(0, buffer, 4);
		if (size == -1)
			error_message(tab, "Error\n", 1);
	}
	free(buffer);
	return (0);
}

int	main(int ac, char **av)
{
	t_tab	*tab;

	catch_errors(ac, av);
	if (ac > 1)
	{
		tab = initialize_tab(ac, av);
		ft_scan(tab);
		if (is_sorted(tab->a) && tab->size_a == tab->final_size_a)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		free_all(tab);
	}
	return (0);
}
