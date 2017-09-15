#include "fillit.h"
/*
en gros tout ca c'est pour le debug [voir le main]
Le vrai bail c'est la derniere fonction pour imprimer la map
*/
void print_piece(t_triminos *t) {
  int j;
  int i;

  i = 0;
  j = -1;
  ft_putchar('\n');
  ft_colstr(KCYN, "position: ");
  while (++j < 3) {
    ft_print("x: %d, y: %d\t", t->pos[j].x, t->pos[j].y);
  }
  ft_putendl("\n");
  while (t->piece[i]) {
    ft_putchar(t->piece[i] == '.' ? '.' : t->name);
    i++;
    !(i % 4) ? ft_putchar('\n') : ft_putchar(' ');
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

/*
n c'est genre le nombre de colonnes,
vu que c'est stock sur un char * faut le sqrt blabla.
car si length = 16, ca fait un carré de 4x4 genre.
*/
void print_map(char *map) {
  int i;

  i = 0;
  int n = ft_sqrt(ft_strlen(map));
  while (map[i]) {
    if (!(i % n))
      ft_putchar('\n');
    ft_putchar(map[i]);
    i++;
  }
  ft_putchar('\n');
}
