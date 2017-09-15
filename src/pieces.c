#include "fillit.h"

/*
t->pos contient 3 position [x, y]
correspond aux distances respectives en x et y par rapport au premier point
]
exemple:
on trouve le premier A, ensuite, on voit les distances des autres points.
On voit qu'etant en dessous, deplacement en y [1, 2, 3] de distance
respectivement. position: x: 0, y: 1	x: 0, y: 2	x: 0, y: 3

. . . A
. . . A
. . . A
. . . A

Meme chose sur l'axe x.
position: x: 1, y: 0	x: 2, y: 0	x: 3, y: 0

. . . .
. . . .
. . . .
B B B B

Mix un peu des deux
position: x: 1, y: 0	x: 2, y: 0	x: 2, y: 1

. C C C
. . . C
. . . .
. . . .
*/

void fill_order(t_triminos *t) {
  int start;
  int i;
  int j;

  start = find_first(t->piece, '#', 0);
  i = start + 1;
  j = 0;
  while (t->piece[i]) {
    if (t->piece[i] == '#') {
      t->pos[j].x = (i % 4) - (start % 4);
      t->pos[j].y = (i / 4) - (start / 4);
      j++;
    }
    i++;
  }
}

t_triminos *fill_piece(char *piece, char name) {
  t_triminos *n;

  if (!(n = ft_memalloc(sizeof(t_triminos))))
    ft_exit("Bad alloc of processus\n");
  n->piece = piece;
  n->placed = 0;
  fill_order(n);
  n->name = name;
  n->next = NULL;
  return n;
}

void add_piece(t_triminos *n) {
  t_prog *p;

  p = get_prog();
  if (!p->first) {
    p->first = n;
    p->last = n;
  } else {
    p->last->next = n;
    p->last = p->last->next;
  }
}
/*debug purposes*/
