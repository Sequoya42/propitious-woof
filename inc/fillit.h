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

typedef struct s_gen t_gen;
typedef struct s_prog t_prog;

struct s_prog
{
t_gen		*first;
t_gen 	*last;
char 		**map;
};

struct			s_gen
{
	char		*piece;
	t_gen			*next;
};

t_prog 		*get_prog(void);

void			get_map(char *name);
t_gen			*fill_piece(char *piece);
void 			add_piece(t_gen *n);
void 			print_pieces();

#endif
