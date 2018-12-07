/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:14:00 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/07 13:08:04 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Create a new tetriminos, c being the char that will be used to identify it
*/

t_tetriminos	*new_tetriminos(char c)
{
	t_tetriminos	*tetri;

	if ((tetri = (t_tetriminos *)malloc(sizeof(t_tetriminos))) == NULL)
		return (NULL);
	tetri->c = c;
	tetri->placed = 0;
	tetri->pos = new_point(0, 0);
	tetri->height = 0;
	tetri->width = 0;
	return (tetri);
}

/*
**	Free tetriminos and its points
*/

void			free_tetriminos(void **ptr, size_t size)
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
	ft_memdel((void **)&(tetri->pos));
	ft_memdel((void **)ptr);
}

/*
**	Returns wheter a tetri has all its blocks linked together
**	Returns 6 only if 4 blocks are linked together, 8 if square form
**	______1______1221_____________
**	22____2________________1____1_
**	22____2___12_____21____2____31
**	______1____21___12____12____1_
*/

int				check_blocks(t_tetriminos *tetri)
{
	t_point	*pt;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < 4)
	{
		pt = tetri->pt[i++];
		if (X > 0)
			if (tetri->blocks[X - 1][Y] != EMPTY_BLOCK)
				nb++;
		if (Y > 0)
			if (tetri->blocks[X][Y - 1] != EMPTY_BLOCK)
				nb++;
		if (X < 3)
			if (tetri->blocks[X + 1][Y] != EMPTY_BLOCK)
				nb++;
		if (Y < 3)
			if (tetri->blocks[X][Y + 1] != EMPTY_BLOCK)
				nb++;
	}
	return (nb >= 6);
}

/*
**	Returns point containing the the smallest x and the smallest y encountered
**	while browsing all tetriminos points
*/

static t_point	*find_min(t_tetriminos *tetri)
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
**	Returns point containing the the smallest x and the smallest y encountered
**	while browsing all tetriminos points
*/

static t_point	*find_max(t_tetriminos *tetri)
{
	t_point		*max;
	t_point		*pt;
	int			i;

	max = new_point(0, 0);
	cpy_point(max, tetri->pt[0]);
	i = 1;
	while (i < 4)
	{
		pt = tetri->pt[i];
		if (X_MAX < X)
			X_MAX = X;
		if (Y_MAX < Y)
			Y_MAX = Y;
		i += 1;
	}
	return (max);
}

/*
**	Place blocks/points representing tetriminos at the top_left
*/

void			normalize_tetriminos(t_tetriminos *tetri)
{
	t_point		*min;
	t_point		*max;
	t_point		*pt;
	int			i;

	min = find_min(tetri);
	max = find_max(tetri);
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
	tetri->width = Y_MAX - Y_MIN;
	tetri->height = X_MAX - X_MIN;
	ft_memdel((void **)&min);
}
