/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:13:04 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/05 16:07:38 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include "fillit.h"

typedef struct		s_tetriminos
{
	char			blocks[4][4];
	t_point			*pt[4];
	char			c;
	int				placed;
	t_point			*last_position;
}					t_tetriminos;

t_tetriminos		*new_tetriminos(char c);
void				normalize_tetriminos(t_tetriminos *tetri);
void				free_tetriminos(void **ptr, size_t size);

#endif
