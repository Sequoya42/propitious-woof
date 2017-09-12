#include "fillit.h"

t_triminos *fill_piece(char *piece, char name) {
  t_triminos *n;
  if (!(n = ft_memalloc(sizeof(t_triminos))))
    ft_exit("Bad alloc of processus\n");
  n->piece = piece;
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

void print_piece(t_triminos *g) {
  int i;

  i = 0;
  ft_putendl(g->piece);
  while (g->piece[i]) {
    ft_putchar(g->piece[i] == '.' ? '.' : g->name);
    i++;
    if (i % 4 == 0)
      ft_putchar('\n');
  }
  ft_putchar('\n');
}

void print_pieces() {
  t_triminos *t;

  ft_putendl("******** ********  les pieces ******** ********");
  t = get_prog()->first;
  while (t) {
    print_piece(t);
    t = t->next;
  }
}
