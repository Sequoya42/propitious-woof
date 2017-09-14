#include "fillit.h"

t_triminos *place_piece(t_triminos *t, t_prog *p, int start) {
  t_pos firstPos;
  t_pos newPos;
  int i;
  int c;
  int x[4];

  c = 0;
  while (t && t->placed == 1)
    t = t->next;
  if (start > (int)ft_strlen(p->map) - 4 || !t)
    return NULL;
  i = find_first(p->map, '.', start);
   firstPos.x = i % p->size;
   firstPos.y = i / p->size;
  x[3] = i;
while (c < 3){
   newPos.x = i % p->size + t->pos[c].x;
   newPos.y =  firstPos.y + t->pos[c].y;
   if (newPos.x > p->size || newPos.x < 0 || newPos.y < 0 || newPos.y > p->size){{
     return (place_piece(t->next, p, start));
   }
   }
  x[c] = newPos.y * p->size + newPos.x;
  if (p->map[x[c]] != '.')
  return (place_piece(t->next, p, start));
  c++;
  }
  c = 0;
  while (c < 4){
    p->map[x[c++]] = t->name;
  }
  t->placed = 1;
  return t;
}

void reset(t_prog *p) {
  t_triminos *f;

  f = p->first;
  while (f){
    f->placed = 0;
    f = f->next;
  }
  p->placed = 0;
  p->size += 1;
  print_map(p->map);
  p->map = init_map(p->size);
}

void solve(t_prog *p) {
  t_triminos *f;
  t_triminos *tmp;
  int i;
  int l;

  i = 0;
  l = ft_strlen(p->map) - 1;
  f = p->first;

  while (p->placed < p->npieces){
    tmp = place_piece(f, p, i);
    //  place_piece(f, p, i) ? p->placed++ : i++;
    if (!tmp){
      ft_colstr(KCYN, &f->name);
      ft_putchar('\n');
      i++;
      // f = p->first;
    }
    else{
      ft_colendl(&f->name);
      f = tmp->next;
      if (!f){
        f = p->first;
      }
      p->placed++;
    }
    if (i == l){
      reset(p);
      i = 0;
      l = ft_strlen(p->map) - 1;
      f  = p->first;
    }
  }
  ft_colendl("LA FIN");
}
