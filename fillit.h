/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:31:36 by rbaum             #+#    #+#             */
/*   Updated: 2015/12/03 19:34:43 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include "libft.h"
#include <fcntl.h>

typedef struct s_gen t_triminos;
typedef struct s_prog t_prog;

typedef struct s_cor t_cor;
typedef struct s_pos t_pos;

#define FIRST_POINT 3

#define OVERFLOWX (new_pos.x >= p->size || new_pos.x < 0)
#define OVERFLOWY (new_pos.y < 0 || new_pos.y >= p->size)

struct s_pos {
  int x;
  int y;
};

struct s_prog {
  int size;
  int placed;
  int current;
  int npieces;
  t_triminos *first;
  t_triminos *last;
  char *map;
  char *order;
};

struct s_gen {
  char name;
  char *piece;
  t_pos pos[3];
  t_triminos *next;
};

int next_permutation(char *array);

t_prog *get_prog(void);
char *init_map(int n);
void init(char *file, t_prog *p);
t_triminos *fill_piece(char *piece, char name);
void add_piece(t_triminos *n);
void print_pieces();
int				verify_pos(char *line,int  i);
// ******** ********  resolve  ******** ********
void solve(t_prog *p);

// ******** ********  tools  ******** ********
int ft_sqrt(int n);
char *displace(char *s, int start, int sense);
void print_map(char *map);
int find_first(char *s, char c, int start);
#endif
