/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:21:15 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/01 18:59:46 by qujacob          ###   ########.fr       */
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

void	algorithm_selector(t_tab *tab)
{
	if (tab->size_a == 2)
		do_op("sa", 0, tab);
	else if (tab->size_a == 3)
		three_algorithm(tab);
	else if (tab->size_a == 4)
		four_algorithm(tab);
	else if (tab->size_a == 5)
		five_algorithm(tab);
	else
		big_algorithm(tab);
}

int	main(int ac, char *av[])
{
	t_tab	*tab;

	catch_errors(ac, av);
	if (ac > 2)
	{
		tab = initialize_tab(ac, av);
		if (!is_sorted(tab->a))
			algorithm_selector(tab);
		free_all(tab);
	}
	return (0);
}
