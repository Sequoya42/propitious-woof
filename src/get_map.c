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

int verif(char *name) {
  char *piece;
  int fd;
  int j;
  char *line;

  piece = NULL;
  fd = open(name, O_RDONLY);
  j = 1;
  if (fd < 0)
    return (0);
  while (get_next_line(fd, &line)) {
    if (line[0] == '\0') {
      add_piece(fill_piece(piece));
      piece = NULL;
    } else {
      check(line, j);
    }
    piece = piece == NULL ? ft_strdup(line) : ft_strjoin(piece, line);
    j++;
  }
  add_piece(fill_piece(piece));
  return (1);
}

void get_map(char *name) {
  if (verif(name) == 0)
    ft_exit("Bad map!");
}
