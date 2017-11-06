#include "fillit.h"

t_triminos              *next_available(t_triminos *t)
{
	while (t && (t->placed == 1 || t->tested == 1))
	{
		t = t->next;
	}
	return (t);
}

t_triminos              *fill_map(t_prog *p, int points[4], t_triminos *t)
{
	int c;

	c = 0;
	while (c < 4)
	{
		p->map[points[c++]] = t->name;
	}
	t->placed = 1;
	return (t);
}

int                                             is_in(char *str, char c){
	int i;

	i = -1;
	while (str[++i]) {
		if (str[i] == c)
			return (1);
	}

	return (0);
}

int                                             get_names(t_prog *p, int n, char *names) {
	int i;
	int j;

	i = ft_strlen(p->map);
	j = 0;
	while (--i  && j != n) {
		if (p->map[i] != '.' && !is_in(names, p->map[i])) {
			names[j++] = p->map[i];
		}
	}
	return (j == n);
}

void                                    remove(t_prog *p, char *names){
	t_triminos                      *t;

	t = p->first;
	while (t) {
		if (is_in(names, t->name)) {
			t->placed = 0;
			t->tested = 1;
			p->placed--;
		}
		t = t->next;
	}
}

int                             back_track(t_prog *p, int n){
	static int count = 0;
	int i;
	char *names;

	names = ft_memalloc(n);
	if (count == p->npieces) {
		count = 0;
		return -1;
	}
	i = ft_strlen(p->map);
	if (!get_names(p, n, names)) {
		return -2;
	}
	remove(p, names);
	while (--i > -1) {
		if (is_in(names, p->map[i])) {
			ft_putchar(p->map[i]);
			ft_colendl("WOROKED");
			p->map[i] = '.';
		}
	}
	print_map(p->map);
	count++;

	return (1);
}

t_triminos              *place_piece(t_triminos *t, t_prog *p, int start)
{
	int first_y;
	t_pos new_pos;
	int c;
	int points[4];

	c = 0;
	if (!t) {
		return (NULL);
	}
	// print_map(p->map);
	// ft_colendl(&t->name);
	points[FIRST_POINT] = find_first(p->map, '.', start);
	first_y = points[FIRST_POINT] / p->size;
	while (c < 3)
	{
		new_pos.x = points[FIRST_POINT] % p->size + t->pos[c].x;
		new_pos.y = first_y + t->pos[c].y;
		points[c] = new_pos.y * p->size + new_pos.x;
		if (OVERFLOWX || OVERFLOWY || p->map[points[c]] != '.') {
			return NULL;
			// return (place_piece(t, p, start + 1));
		}
		c++;
	}
	return (fill_map(p, points, t));
}

void                    reset(t_prog *p)
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

void clear_tested(t_prog *p){
	t_triminos *t;
	t = p->first;
	while (t) {
		t->tested = 0;
		t = t->next;
	}
}
void                    solve(t_prog *p)
{
	t_triminos      *f;
	t_triminos      *tmp;
	int i;
	int l;
	int test;

	i = 0;
	test = 1;
	l = ft_strlen(p->map) - 3;
	f = p->first;
	while (p->placed < p->npieces)
	{
		tmp = place_piece(next_available(f), p, i);
		if (tmp && ++p->placed) {
			clear_tested(p);
			// test = test;
		}
		else
			i++;
		if (i == l)
		{
			print_map(p->map);
			ft_colendl("entre deux");
			int x = back_track(p, test);
			ft_print("X %d\n", x);
			// print_map(p->map);

			if (x == -1)
				test++;
			else if (x == -2 || test == p->npieces)
			{
				ft_colendl("w");
				reset(p);
				l = ft_strlen(p->map) - 3;
			}
			i = 0;
		}
	}
}
