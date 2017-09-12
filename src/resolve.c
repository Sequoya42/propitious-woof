#include "fillit.h"

void place_piece(t_triminos *t) {
  char **map;
  int x;
  int y;
  (void)t;
  x = -1;
  y = -1;
  map = get_prog()->map;
  while (map[++y]) {
    while (map[y][++x]) {
    }
  }
}

void solve(t_prog *p) {
  t_triminos *f;

  f = p->first;

  while (f) {
    // place_piece(f);
    f = f->next;
  }
}
