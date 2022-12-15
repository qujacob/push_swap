/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:01:42 by qujacob           #+#    #+#             */
/*   Updated: 2021/11/02 11:02:47 by qujacob          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstrnl(char *str, int checker)
{
	if (checker)
		return ;
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
