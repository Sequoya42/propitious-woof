#include "fillit.h"

void	print_piece(t_triminos *t)
{
	int j;
	int i;

	i = 0;
	j = -1;
	ft_putchar('\n');
	ft_colstr(KCYN, "position: ");
	while (++j < 3)
	{
		ft_print("x: %d, y: %d\t", t->pos[j].x, t->pos[j].y);
	}
	ft_putendl("\n");
	while (t->piece[i])
	{
		ft_putchar(t->piece[i] == '.' ? '.' : t->name);
		i++;
		!(i % 4) ? ft_putchar('\n') : ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	print_pieces(void)
{
	t_triminos *t;

	ft_putendl("******** ********	les pieces ******** ********");
	t = get_prog()->first;
	while (t)
	{
		print_piece(t);
		t = t->next;
	}
}

void	print_map(char *map)
{
	int i;
	int n;

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
