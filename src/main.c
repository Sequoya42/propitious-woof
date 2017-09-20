/*
 **************************************************************************

                                                          :::      ::::::::
     main.c                                             :+:      :+:    :+:
 +:+ +:+         +:+
     By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+
 +#+#+#+#+#+   +#+
     Created: 2015/12/03 19:31:28 by rbaum             #+#    #+#
     Updated: 2015/12/03 19:35:25 by rbaum            ###   ########.fr

 **************************************************************************
 */

#include "fillit.h"

t_prog *get_prog(void)
{
	static t_prog p;

	return (&p);
}


int main(int ac, char * *av)
{
	t_prog *p;

	if (ac != 2) return (-1);

	p = get_prog();
	init(av[1], p);
	// print_pieces(); [debug purposes]
	solve(p);
	print_map(p->map);

	return (0);
}
