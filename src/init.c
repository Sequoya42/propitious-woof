#include "fillit.h"

/*
en vrai faut renvoyer bad map et pas d'erreur precise
tous les petits cas stupides, verifier que ya bien 4 points etc etc
*/
static char *check(char *line, int j) {
  int i;
  static int k = 0;

  i = 0;
  if (ft_strlen(line) != 4 && line[0] != '\0')
    ft_exit("Lines do not have the same length\n");
  while (line[i]) {
    if (line[i] == '#')
      k++;
    j = j % 5;
    if (line[i] != '.' && line[i] != '\0' && line[i] != '#')
      ft_exit("Bad char, please only use . and #\n");
    i++;
  }
  if (j == 4 && k != 4)
    ft_exit("Invalid piece\n");
  else if (j == 4)
    k = 0;
  return line;
}
/*
truc sale qui check trop de truc parce que court a ecrire
et on s'en fou un peu vu que fait une fois.
*/
int verify_touch(char *line) {
  int i = 0;
  while (line[i]) {
    if (line[i] == '#') {
      if (line[i + 1] != '#' && line[i - 1] != '#' && line[i + 4] != '#' &&
          line[i >= 4 ? i - 4 : -1] != '#')
        return 0;
    }
    i++;
  }
  return 1;
}

char *init_map(int n) {
  char *map;
  int i;
  int l;

  l = (n * n) + 1;
  i = 0;
  map = ft_memalloc(sizeof(*map) * l);
  while (i < (l - 1)) {
    map[i++] = '.';
  }

  return map;
}
/*
get_next_line : lis ligne par ligne les bails
en vrai project d'apres mais pratique.
le add_piece de fill_piece , a voir dans pieces.c directement.

piece = piece == NULL ? ft_strdup(line) : ft_strjoin(piece, line);

ce bail la en gros vu que tu lis ligne par ligne,
si la piece est vide ,copies la premiere ligne, sinon rajoutes les suivantes
*/
int verif(int fd) {
  char *piece;
  int j;
  char *line;
  char name;

  piece = NULL;
  name = 'A';
  j = 1;
  if (fd < 0)
    return (0);
  while (get_next_line(fd, &line)) {
    if (line[0] == '\0' && piece == NULL)
      return 0;
    else if (line[0] == '\0') {
      add_piece(fill_piece(piece, name++));
      piece = NULL;
    } else {
      check(line, j);
    }
    piece = piece == NULL ? ft_strdup(line) : ft_strjoin(piece, line);
    j++;
  }
  add_piece(fill_piece(piece, name++));
  return 4;
}

/*
ouvre le fichier,
verifie que c'est OK [les pieces]
ensuite, verify_touch c'est une autre verif des pieces, un peu a la sale
p->npieces c'est le nombre de pieces a placer.

initialise la map avec taille de 4 [retour de verif]
en vrai faudrait calculer la taille minimum possible en fonction des pieces.
la flemme, alors 4.
*/
void init(char *file, t_prog *p) {
  int fd;
  int n;
  t_triminos *t;

  fd = open(file, O_RDONLY);
  n = verif(fd);
  p->size = n;
  if (n == 0)
    ft_exit("Bad map!");
  t = p->first;
  p->npieces = 0;
  while (t) {
    if (!verify_touch(t->piece))
      ft_exit("Bad piece, all '#' must touch");
    t = t->next;
    p->npieces++;
  }
  p->map = init_map(n);
}
