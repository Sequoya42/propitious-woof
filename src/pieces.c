#include "fillit.h"

t_gen *fill_piece(char *piece) {
  t_gen *n;
  if (!(n = ft_memalloc(sizeof(t_gen))))
    ft_exit("Bad alloc of processus\n");
  n->piece = piece;
  n->next = NULL;
  return n;
}

void add_piece(t_gen *n) {
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

void print_pieces() {
  t_gen *first;

  first = get_prog()->first;
  // ft_putendl(first->piece);
  while (first->next) {
    ft_putendl(first->piece);
    first = first->next;
  }
  ft_putendl(first->piece);
}
