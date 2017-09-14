#include "fillit.h"

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

void print_piece(t_triminos *t) {
  int j;

  int i;

  i = 0;
  j = -1;
  ft_putchar('\n');
  ft_colstr(KCYN, "position: ");
    while (++j < 3){
      ft_print("x: %d, y: %d\t", t->pos[j].x, t->pos[j].y);
    }
    ft_putendl("\n");

  while (t->piece[i]) {
    ft_putchar(t->res[i] == '.' ? '.' : t->name);
    i++;
    if (i % 4 == 0) {
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
    ft_colendl(t->res);
    print_piece(t);
    t = t->next;
  }
}
/*
ABBBB.
ACCCEE
AFFCEE
A.FFGG
HHHDDG
.HDD.G
*/
void print_map(char *map) {
  int i;

  ft_putendl("******** ******** la map   ******** ********");
  i = 0;
  int n = ft_sqrt(ft_strlen(map));
  ft_putnbrendl(n);
  ft_putnbrendl(ft_strlen(map));
  while (map[i]) {
    if (!(i % n))
      ft_putchar('\n');
      ft_putchar(map[i]);
    // ft_putendl(map[i]);
    i++;
  }
  ft_putchar('\n');
}
