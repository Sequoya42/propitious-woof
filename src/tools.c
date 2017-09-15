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
Renvoie la premiere occurence du charactere C dans la chaine S
en demarrant a l'index start
*/
int find_first(char *s, char c, int start) {
  while (s[start] != c)
    start++;
  return start;
}
