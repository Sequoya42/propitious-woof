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
  n->transform = displace(piece, 4, 0);
  n->transformTwo = displace(piece, 4, 1);
  n->name = name;
  n->next = NULL;
  return n;
}
