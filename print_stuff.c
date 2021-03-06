/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:22:28 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/11 13:22:28 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(char *map)
{
	int		i;
	int		n;

	i = 0;
	n = ft_sqrt(ft_strlen(map));
	while (map[i])
	{
		if (!(i % n) && i > 0)
			ft_putchar('\n');
		ft_putchar(map[i]);
		i++;
	}
	ft_putchar('\n');
}
