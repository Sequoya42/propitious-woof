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
# define FILLIT_H

#include "libft.h"
#include <fcntl.h>

typedef struct s_gen t_triminos;
typedef struct s_prog t_prog;

typedef struct s_cor t_cor;
typedef struct s_pos t_pos;
/*unused, can be removed*/
struct 			s_cor
{
		int mx;
		int my;
		int px;
		int py;
};


struct 			s_pos
{
		int x;
		int y;
};

struct 			s_prog
{
	int 			size;
	t_triminos *first;
	t_triminos 	*last;
	char 			*map;
char 			 nik[2048];
};

struct			s_gen
{
	char			name;
	char			*piece;
	char			*res;
	t_pos			pos[3];
	char			*transform;

	char			*transformTwo;
	t_triminos		*next;
};

t_prog 			*get_prog(void);

void				init(char *file, t_prog *p);
t_triminos			*fill_piece(char *piece, char name);
void 				add_piece(t_triminos *n);
void 				print_pieces();

// ******** ********  resolve  ******** ********
void 				solve(t_prog *p);

// ******** ********  tools  ******** ********
int 				ft_sqrt(int n);
char 				*displace(char *s, int start, int sense);
void 				print_map(char *map);
int 				find_first(char *s, char c, int start);
#endif
