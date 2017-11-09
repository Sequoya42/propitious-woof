
#include "fillit.h"
t_triminos              *next_available(t_prog *p, char name)
{
	t_triminos                      *t;

	t = p->first;
	while (t && t->name != name)
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
	return (t);
}


int place_piece(t_triminos *t, t_prog *p, int start)
{
	int first_y;
	t_pos new_pos;
	int c;
	int points[4];

	c = 0;
	if (start >= (int)ft_strlen(p->map) - 3) {
		return (0);
	}
	points[FIRST_POINT] = find_first(p->map, '.', start);
	start = points[FIRST_POINT];
	// ft_print(KGRN "%s\tFIRST %d\n" KNRM, p->order, points[FIRST_POINT]);
	// print_map(p->map);
	first_y = points[FIRST_POINT] / p->size;
	while (c < 3)
	{
		new_pos.x = points[FIRST_POINT] % p->size + t->pos[c].x;
		new_pos.y = first_y + t->pos[c].y;
		points[c] = new_pos.y * p->size + new_pos.x;
		if (OVERFLOWX || OVERFLOWY || p->map[points[c]] != '.') {
			return (place_piece(t, p, start + 1));
		}
		c++;
	}
	fill_map(p, points, t);
	return (1);
}
/*
   TODO
   reimplement remove piece to place to next spot
 */

int                                     remove(t_prog *p, int current){
	int i;
	int start;
	char name;

	start = -1;
	i = -1;
	name = p->order[current];
	while (p->map[++i]) {
		if (p->map[i] == name) {
			p->map[i] = '.';
			if (start == -1)
				start = i;
		}
	}
	// ft_print("REMOVE %d\n", start);
	if (start == -1)
		return -1;
	return (start + 1);
}

void                    solve(t_prog *p)
{
	t_triminos      *f;
	int current;
	int i;

	current = 0;
	f = p->first;
	i = 0;
	while (current <= p->npieces - 1)
	{
		// print_map(p->map);
		if (place_piece(next_available(p, p->order[current]), p, i)) {
			current++;
			i = 0;
		}else{
			current--;
			i = remove(p, current);
			if (i == -1 || current == -1)
			{
				i = 0;
				current = 0;
				p->size += 1;
				p->map = init_map(p->size);
			}
		}
	}
}
