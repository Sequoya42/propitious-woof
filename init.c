#include "fillit.h"

static char             *check(char *line, int j)
{
	int i;
	static int k = 0;

	i = 0;
	if (ft_strlen(line) != 4 && line[0] != '\0')
		ft_exit("error");
	while (line[i])
	{
		if (line[i] == '#')
			k++;
		j = j % 5;
		if (line[i] != '.' && line[i] != '\0' && line[i] != '#')
			ft_exit("error");
		i++;
	}
	if (j == 4 && k != 4)
		ft_exit("error");
	else if (j == 4)
		k = 0;
	return (line);
}

int                             verify_touch(char *line)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	x = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			x += verify_pos(line, i);
			j++;
		}
		i++;
	}
	return (x >= 6);
}

char                    *init_map(int n)
{
	char            *map;
	int i;
	int l;

	l = (n * n) + 1;
	i = 0;
	map = ft_memalloc(sizeof(*map) * l);
	while (i < (l - 1))
		map[i++] = '.';
	return (map);
}

int                             verif(int fd)
{
	char                    *piece;
	int j;
	char                    *line;
	char name;

	piece = NULL;
	name = 'A';
	j = 0;
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line) && ++j)
	{
		if (line[0] == '\0' && piece == NULL)
			return (0);
		else if (line[0] == '\0')
		{
			add_piece(fill_piece(piece, name++));

			piece = NULL;
		}
		else
			check(line, j);
		piece = piece == NULL ? ft_strdup(line) : ft_strjoin(piece, line);
	}
	add_piece(fill_piece(piece, name++));
	return (j);
}

int                                    find_bigger(int n) {
	int i;
	int r;

	i = 2;
	r = n * 4;
	while ((i * i) < r) {
		i += 1;
	}
	return i;
}

void                    init(char *file, t_prog *p)
{
	int fd;
	int n;
	t_triminos      *t;

	fd = open(file, O_RDONLY);
	n = verif(fd);
	if (n == 0)
		ft_exit("error");
	t = p->first;
	p->npieces = 0;
	p->order = ft_memalloc(26);
	while (t)
	{
		if (!verify_touch(t->piece))
			ft_exit("error");
		p->order[p->npieces] = t->name;
		t = t->next;
		p->npieces++;
	}
	p->current = 0;
	p->size = find_bigger(p->npieces);
	p->size = 3;
	p->map = init_map(p->size);
}
