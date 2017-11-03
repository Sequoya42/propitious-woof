#include "fillit.h"

t_triminos		*next_available(t_triminos *t)
{
	while (t && t->placed == 1)
	{
		t = t->next;
	}
	return (t);
}

t_triminos		*fill_map(t_prog *p, int points[4], t_triminos *t)
{
	int		c;

	c = 0;
	while (c < 4)
	{
		p->map[points[c++]] = t->name;
	}
	t->placed = 1;
	return (t);
}

t_triminos		*place_piece(t_triminos *t, t_prog *p, int start)
{
	int		first_y;
	t_pos	new_pos;
	int		c;
	int		points[4];

	c = 0;
	if (!t)
		return (NULL);
	points[FIRST_POINT] = find_first(p->map, '.', start);
	first_y = points[FIRST_POINT] / p->size;
	while (c < 3)
	{
		new_pos.x = points[FIRST_POINT] % p->size + t->pos[c].x;
		new_pos.y = first_y + t->pos[c].y;
		if (OVERFLOWX || OVERFLOWY)
			return (place_piece(next_available(t->next), p, start));
		points[c] = new_pos.y * p->size + new_pos.x;
		if (p->map[points[c]] != '.')
			return (place_piece(next_available(t->next), p, start));
		c++;
	}
	return (fill_map(p, points, t));
}

void			reset(t_prog *p)
{
	t_triminos *f;

	f = p->first;
	while (f)
	{
		f->placed = 0;
		f = f->next;
	}
	p->placed = 0;
	p->size += 1;
	p->map = init_map(p->size);
}

void			solve(t_prog *p)
{
	t_triminos	*f;
	t_triminos	*tmp;
	int			i;
	int			l;

	i = 0;
	l = ft_strlen(p->map) - 1;
	f = p->first;
	while (p->placed < p->npieces)
	{
		tmp = place_piece(next_available(f), p, i);
		if (tmp && ++p->placed)
			f = tmp->next ? tmp->next : p->first;
		else
			i++;
		if (i == l)
		{
			reset(p);
			i = 0;
			l = ft_strlen(p->map) - 1;
			f = p->first;
		}
	}
}
