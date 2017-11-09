/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*                                                                            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:31:28 by rbaum             #+#    #+#             */
/*   Updated: 2015/12/03 19:35:25 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
   // TODO

   Listen to nipal.
   Permutations won't work.
   Place, a, then b, then c etc

   If can't place c, move b to the next fit area.
   If still cant place c, move b
   If end of map, move a, then place b
   etc

 */
t_prog          *get_prog(void)
{
	static t_prog p;

	return (&p);
}

int                     main(int ac, char **av)
{
	t_prog  *p;

	if (ac != 2)
		return (-1);
	p = get_prog();
	init(av[1], p);
	solve(p);
	print_map(p->map);
	return (0);
}

// char *str = ft_memalloc(4);
// str[0] = 'A';
// str[1] = 'B';
// str[2] = 'C';
// // str[3] = '\0';
// ft_putendl(str);
// next_permutation(str);
// ft_putendl(str);
