/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:22:22 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/11 13:22:41 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_prog		*get_prog(void)
{
	static t_prog p;

	return (&p);
}

int			main(int ac, char **av)
{
	t_prog	*p;

	if (ac != 2)
		return (-1);
	p = get_prog();
	init(av[1], p);
	solve(p);
	print_map(p->map);
	return (0);
}
