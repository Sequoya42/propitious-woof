#include "fillit.h"

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
void laTransform(char *s, char *color, int i, char letter) {
  int j;

  j = i - 4;
  ft_putchar('\t');
  ft_putstr(color);
  while (j < i) {
    ft_putchar(s[j] == '.' ? '.' : letter);
    j++;
  }
}

void print_piece(t_triminos *g) {
  int i;

  i = 0;
  ft_putchar('\n');
  while (g->piece[i]) {
    ft_putchar(g->piece[i] == '.' ? '.' : g->name);
    i++;
    if (i % 4 == 0) {
      laTransform(g->res, KMAG, i, g->name);
      laTransform(g->transform, KCYN, i, g->name);
      laTransform(g->transformTwo, KGRN, i, g->name);
      ft_putstr(KNRM);
      ft_putchar('\n');
    }
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
