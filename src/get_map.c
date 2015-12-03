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

void			check(char *line, int j)
{
	int			i;
	static int	k = 0;

	i = 0;
	if (ft_strlen(line) != 4 && line[0] != '\0')
		ft_exit("Bad bad not good\n");
	while (line[i])
	{
		if (line[i] == '#')
			k++;
			j = j % 5;
		if (line[i] != '.' && line[i] != '\0' && line[i] != '#')
			ft_exit("Bad char, please only use . and #\n");
		i++;
	}
	if (j == 4 && k != 4)
		ft_exit("Invalid piece\n");
	else if (j == 4)
		k = 0;
	ft_putendl(line);
}

int				verif(char *name)
{
	int			fd;
	int			j;
	char		*line;

	fd = open (name, O_RDONLY);
	j = 1;
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		check(line, j);
		j++;
	}
	return (1);
}

void			get_map(char *name)
{
	if (verif(name) == 0)
		ft_exit("Bad map!");
}