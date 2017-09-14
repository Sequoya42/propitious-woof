#include "fillit.h"


// void   repos(t_cor *cor, int i, int j, int size) {
//   cor->mx = i % size;
//   cor->my = i / size;
//
//   cor->px = j % 4;
//   cor->py = j / 4;
//
//   ft_print("MAP [%d ; %d] and PIECE [%d ; %d]\n",
//    cor->mx, cor->my, cor->px, cor->py);
// }

int place_piece(t_triminos *t, t_prog *p, int start) {
  t_pos firstPos;
  t_pos newPos;
  int i;
  int c;
  int x[4];

  c = 0;
  if (start > (int)ft_strlen(p->map) - 4)
    return 0;
  i = find_first(p->map, '.', start);
   firstPos.x = i % p->size;
   firstPos.y = i / p->size;
  x[3] = i;
while (c < 3){
   newPos.x = i % p->size + t->pos[c].x;
   newPos.y =  firstPos.y + t->pos[c].y;
   if (newPos.x > p->size || newPos.x < 0 || newPos.y < 0 || newPos.y > p->size){
     return place_piece(t, p, start + 1);
   }
  x[c] = newPos.y * p->size + newPos.x;
  if (p->map[x[c]] != '.')
  return place_piece(t, p, start + 1);
  c++;
  }
  c = 0;
  while (c < 4){
    p->map[x[c++]] = t->name;
  }
  return 1;
}

void solve(t_prog *p) {
  t_triminos *f;

  f = p->first;
  while (f){
    ft_colendl(&f->name);
    if (!place_piece(f, p, 0)){
      p->size += 1;
      print_map(p->map);
      p->map = init_map(p->size);
      f  = p->first;
    }
      else {
        f = f->next;
      }
  }
  ft_colendl("LA FIN");
}
