/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:37:16 by rbaum             #+#    #+#             */
/*   Updated: 2015/12/03 19:37:21 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			check(char *line)
{
	int			i;

	i = 0;
	if (ft_strlen(line) != 4 && line[0] != '\0')
		ft_exit("Bad bad not good");
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '\0' && line[i] != '#')
			ft_exit("Bad char, please only use . and #");
		i++;
	}
		ft_putendl(line);
}

int				verif(char *name)
{
	int			fd;
	char		*line;

	fd = open (name, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		check(line);
	}
	return (1);
}

void			get_map(char *name)
{
	if (verif(name) == 0)
		ft_exit("Bad map!");
}