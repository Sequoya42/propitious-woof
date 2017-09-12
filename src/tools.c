#include "fillit.h"

int ft_sqrt(int n) {
  int i;

  i = 2;
  while (i * i < n) {
    i++;
  }
  return i;
}

void print_map(char **map) {
  int i;

  ft_putendl("******** ******** la map   ******** ********");
  i = 0;
  while (map[i]) {
    ft_putendl(map[i]);
    i++;
  }
}
