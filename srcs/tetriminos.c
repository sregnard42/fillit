/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:14:00 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/03 11:00:16 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Create a new tetriminos, c being the char that will be used to identify it
*/

t_tetriminos		*new_tetriminos(char c)
{
	t_tetriminos	*tetri;

	if ((tetri = (t_tetriminos *)malloc(sizeof(t_tetriminos))) == NULL)
		return (NULL);
	tetri->c = c;
	tetri->placed = 0;
	return (tetri);
}

/*
**	Return point containing the the smallest x and the smallest y encountered
**	while browsing all tetriminos points
*/

static t_point		*find_min(t_tetriminos *tetri)
{
	t_point		*min;
	t_point		*pt;
	int			i;

	min = new_point(0, 0);
	cpy_point(min, tetri->pt[0]);
	i = 1;
	while (i < 4)
	{
		pt = tetri->pt[i];
		if (X_MIN > X)
			X_MIN = X;
		if (Y_MIN > Y)
			Y_MIN = Y;
		i += 1;
	}
	return (min);
}

/*
**	Place blocks/points representing tetriminos at the top_left
*/

void				normalize_tetriminos(t_tetriminos *tetri)
{
	t_point		*min;
	t_point		*pt;
	int			i;

	min = find_min(tetri);
	i = 0;
	while (i < 4)
	{
		pt = tetri->pt[i];
		tetri->blocks[X][Y] = EMPTY_BLOCK;
		X -= X_MIN;
		Y -= Y_MIN;
		tetri->blocks[X][Y] = tetri->c;
		i += 1;
	}
	ft_memdel((void **)&min);
}

/*
**	Free tetriminos and its points
*/

void				free_tetriminos(void **ptr, size_t size)
{
	t_tetriminos	*tetri;
	int				i;

	if (!ptr || !ptr || size < 1)
		return ;
	tetri = *ptr;
	i = 0;
	while (i < 4)
	{
		if (tetri->pt[i])
			ft_memdel((void **)&(tetri->pt[i]));
		i++;
	}
	ft_memdel((void **)ptr);
}

