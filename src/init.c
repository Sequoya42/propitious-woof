#include "fillit.h"

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

int verif(char *file) {
  char *piece;
  int fd;
  int j;
  char *line;
  char name;

  piece = NULL;
  name = 'A';
  fd = open(file, O_RDONLY);
  j = 1;
  if (fd < 0)
    return (0);
  while (get_next_line(fd, &line)) {
    if (line[0] == '\0') {
      add_piece(fill_piece(piece, name++));
      piece = NULL;
    } else {
      check(line, j);
    }
    piece = piece == NULL ? ft_strdup(line) : ft_strjoin(piece, line);
    j++;
  }
  add_piece(fill_piece(piece, name++));
  return (j / 4 - 1);
}

int verify_touch(char *line) {
  int i = 0;
  while (line[i]) {
    if (line[i] == '#') {
      if (line[i + 1] != '#' && line[i - 1] != '#' && line[i + 4] != '#' &&
          line[i >= 4 ? i - 4 : 0] != '#')
        return 0;
    }
    i++;
  }
  return 1;
}

char *init_map(int n) {
   char *map;
  int  i;
  int l;

  l = (n * n) + 1;
  i = 0;
  map = ft_memalloc(sizeof(*map) * l);
  while (i < (l-1)) {
    map[i++] = '.';
  }

  return map;
}

void init(char *file, t_prog *p) {
  int n;
  t_triminos *t;

  n =  verif(file);
   p->size = n;
  if (n == 0)
    ft_exit("Bad map!");
  t = p->first;
  while (t) {
    if (!verify_touch(t->piece))
      ft_exit("Bad piece, all '#' must touch");
    t = t->next;
  }
  p->map = init_map(n);
}
