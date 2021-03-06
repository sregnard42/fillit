/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:13:04 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/07 13:04:43 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include "point.h"

# define X_POS	((TETRI->pos)->x)
# define Y_POS	((TETRI->pos)->y)

typedef struct		s_tetriminos
{
	char			c;
	char			blocks[4][4];
	t_point			*pt[4];
	t_point			*pos;
	int				height;
	int				width;
}					t_tetriminos;

t_tetriminos		*new_tetriminos(char c);
void				free_tetriminos(void **ptr, size_t size);
void				normalize_tetriminos(t_tetriminos *tetri);

#endif
