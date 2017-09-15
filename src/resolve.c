#include "fillit.h"

/*
Rempli la map une fois qu'on est sur qu'elle est placable
points, c'est un tableau avec les coordonnes des points de la map ou mettre
les 4 points de la piece.
[index vu que la map c'est un char * et pas char **]
*/
t_triminos *fill_map(t_prog *p, int points[4], t_triminos *t) {
  int c;

  c = 0;
  while (c < 4) {
    p->map[points[c++]] = t->name;
  }
  t->placed = 1;
  return t;
}

/*
test de placer une piece,
pour ca ya les deux define de OVERFLOW X et OVERFLOW Y
genre on a  ca comme map:
##..
....
....

et on veut placer ca comme piece : AAAA

bah on peut pas faire
##AAAA
....
....
....

vu que ca depasse de la map.
du coup on avance sur le start [envoye par resolve]
comme ca on peut faire

##..
AAAA
....
....

[on check en x a gauche et a droite et y en bas et en haut]
*/
t_triminos *place_piece(t_triminos *t, t_prog *p, int start) {
  int first_y; /*le y du premier '.' de la map [premier emplacement libre]*/
  t_pos new_pos;
  int c;
  int points[4];

  c = 0;
  if (!t)
    return NULL;
  points[FIRST_POINT] = find_first(p->map, '.', start);
  first_y = points[FIRST_POINT] / p->size;
  while (c < 3) {
    new_pos.x = points[FIRST_POINT] % p->size + t->pos[c].x;
    new_pos.y = first_y + t->pos[c].y;
    if (OVERFLOWX || OVERFLOWY)
      return (place_piece(t->next, p, start));
    points[c] = new_pos.y * p->size + new_pos.x;
    if (p->map[points[c]] != '.')
      return (place_piece(t->next, p, start));
    c++;
  }
  // si on peut pas placer la piece, on test la suivante, sinon on retourne NULL
  // et on avance sur la map
  return fill_map(p, points, t);
}

/*
reset tous les bails, et essaye avec une map plus grande de 1
[genre ca rentre pas dans du 4x4 on test dans du 5x5]
*/
void reset(t_prog *p) {
  t_triminos *f;

  f = p->first;
  while (f) {
    f->placed = 0;
    f = f->next;
  }
  p->placed = 0;
  p->size += 1;
  p->map = init_map(p->size);
}

/*
trouve la "piece suivante" a placer
*/
t_triminos *next_available(t_triminos *t) {
  while (t && t->placed == 1)
    t = t->next;
  return t;
}

/*
tant qu'on a pas placer toutes les pieces, on fait des bails.
Si on a reussi a placer une piece, on test placer la suivante.
Si on a pas reussi a placer de piece, on recommence sur la premiere piece.
c'est ce bail la :

tmp = place_piece(next_available(f), p, i);
tmp ? ((f = tmp->next ? tmp->next : p->first) && p->placed++) : i++;


on peut aussi lecrire comme ca pour la lisibilite etc :

tmp = place_piece(next_available(f), p, i);

if (tmp) {
  if (tmp->next){
    f = tmp->next;
  } else {
    f = p->first;
    [on a placer la derniere piece, peut etre qu'il en reste a placer,
    du coup on revient au debut de la liste sur la premiere piece]
  }
} else {
  i++;
}


if (i == l) : si on est a la fin de la map,
c'est que ca l'a pas fait, on retest avec map + grande.
*/

void solve(t_prog *p) {
  t_triminos *f;
  t_triminos *tmp;
  int i;
  int l;

  i = 0;
  l = ft_strlen(p->map) - 1;
  f = p->first;

  while (p->placed < p->npieces) {
    tmp = place_piece(next_available(f), p, i);
    tmp ? ((f = tmp->next ? tmp->next : p->first) && p->placed++) : i++;
    if (i == l) {
      reset(p);
      i = 0;
      l = ft_strlen(p->map) - 1;
      f = p->first;
    }
  }
}
