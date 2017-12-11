/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:22:32 by rbaum             #+#    #+#             */
/*   Updated: 2017/12/11 13:22:32 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt(int n)
{
	int		i;

	i = 2;
	while (i * i < n)
	{
		i++;
	}
	return (i);
}

int			find_first(char *s, char c, int start)
{
	if (start == -1)
		return (-1);
	while (s[start] && s[start] != c)
	{
		if (!s[start])
		{
			return (-1);
		}
		start++;
	}
	return (start);
}

int			verify_pos(char *line, int i)
{
	int		z;

	z = 0;
	if (line[i + 1] == '#')
		z++;
	if (line[i - 1] == '#')
		z++;
	if (line[i + 4] == '#')
		z++;
	if (line[i - 4] == '#')
		z++;
	return (z);
}

int			find_bigger(int n)
{
	int		i;
	int		r;

	i = 2;
	r = n * 4;
	while ((i * i) < r)
	{
		i += 1;
	}
	return (i);
}
