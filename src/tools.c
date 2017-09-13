#include "fillit.h"

int ft_sqrt(int n) {
  int i;

  i = 2;
  while (i * i < n) {
    i++;
  }
  return i;
}

int find_first(char *s, char c, int start) {
  while (s[start] != c)
    start++;
    return start;
}

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
