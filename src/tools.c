#include "fillit.h"

int ft_sqrt(int n) {
  int i;

  i = 2;
  while (i * i < n) {
    i++;
  }
  return i;
}

/*
. . . .
. x x .
. x x .
. . . .

x: i % c
y: i / c
x + y
i % c + i / c
----
i = i + 1 / 4 +
*/
char *displace(char *s, int start, int c) {
  char *ret;
  int i;
  int l;
  int pos;

  l = ft_strlen(s);
  ret = ft_memalloc(sizeof(*s) * (l + 1));

  i = -1;
  while (++i < l) {
    // pos = c == 0 ? (i + start) % l : (i + 1) % start ? i + 1 : i + 1 - start;
    if (c == 0)
      pos = (i + start) % l;
    else
      pos = (i + 1) % start ? i + 1 : i + 1 - start;
    ret[i] = s[pos];
  }
  ret[i] = '\0';
  return ret;
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
