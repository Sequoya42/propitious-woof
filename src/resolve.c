#include "fillit.h"

// void place_piece(t_triminos *t) {
//   char **map;
//

//   map = get_prog()->map;
// }
void solve(t_prog *p) {
  t_triminos *f;

  f = p->first;

  while (f) {
    place_piece(f);
    f = f->next;
  }
}
