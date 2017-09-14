#include "fillit.h"

static int trim_col(char *s, int jump) {
  int i = 0;
  while (s[i] == '.') {
    i += jump;
  }
  return (i == 16);
}

static int trim_line(char *s, int jump) {
  int i = 0;
  while (s[i] == '.' && i < jump) {
    i += 1;
  }
  return (i == jump);
}

void fill_order(t_triminos  *t){
    int start;
    int i;
    int j;

  start = find_first(t->res, '#', 0);
    i = start + 1;
    j = 0;
    while (t->res[i]){
      if (t->res[i] == '#'){
        // t->pos[j].x = i - start;
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
  n->res = piece;
  while (trim_col(n->res, 4))
    n->res = displace(n->res, 4, 1);
  while (trim_line(n->res, 4))
    n->res = displace(n->res, 4, 0);
    fill_order(n);
// ******** ******** to remove, only debug   ******** ********
  n->transform = displace(piece, 4, 0);
  n->transformTwo = displace(piece, 4, 1);
// ******** ********    ******** ********
  n->name = name;
  n->next = NULL;
  return n;
}
