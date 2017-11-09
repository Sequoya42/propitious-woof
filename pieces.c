#include "fillit.h"

void				fill_order(t_triminos *t)
{
	int				start;
	int				i;
	int				j;

	start = find_first(t->piece, '#', 0);
	i = start + 1;
	j = 0;
	while (t->piece[i])
	{
		if (t->piece[i] == '#')
		{
			t->pos[j].x = (i % 4) - (start % 4);
			t->pos[j].y = (i / 4) - (start / 4);
			j++;
		}
		i++;
	}
}

t_triminos			*fill_piece(char *piece, char name)
{
	t_triminos		*n;

	if (!(n = ft_memalloc(sizeof(t_triminos))))
		ft_exit("Bad alloc of processus\n");
	if (!piece || ft_strlen(piece) != 16)
	{
		ft_exit("error");
	}
	n->piece = piece;
	fill_order(n);
	n->name = name;
	n->next = NULL;
	return (n);
}

void				add_piece(t_triminos *n)
{
	t_prog			*p;

	p = get_prog();
	if (!p->first)
	{
		p->first = n;
		p->last = n;
	}
	else
	{
		p->last->next = n;
		p->last = p->last->next;
	}
}
