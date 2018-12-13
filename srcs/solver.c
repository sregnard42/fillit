/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:41:26 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/10 11:33:18 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Remove given tetriminos from map
*/

void		remove_tetri_from_map(t_map *map, t_tetriminos *tetri)
{
	t_point	*pt;

	pt = new_point(0, 0);
	while (X < END)
	{
		while (Y < END)
		{
			if (MAP[X][Y] == tetri->c)
				MAP[X][Y] = EMPTY_BLOCK;
			Y += 1;
		}
		Y = 0;
		X += 1;
	}
	ft_memdel((void **)&pt);
}

/*
**	Try placing tetriminos at given point
*/

static int	place_at(t_map *map, t_point *pt2, t_tetriminos *tetri)
{
	t_point	*pt;
	int		i;

	pt = (t_point *)malloc(sizeof(t_point));
	i = 0;
	while (i < 4)
	{
		cpy_point(pt, tetri->pt[i++]);
		set_point(pt, X + X2, Y + Y2);
		if (block_available(map, pt) == 0)
		{
			ft_memdel((void **)&pt);
			return (0);
		}
	}
	i = 0;
	while (i < 4)
	{
		cpy_point(pt, tetri->pt[i++]);
		MAP[X + X2][Y + Y2] = tetri->c;
	}
	ft_memdel((void **)&pt);
	return (1);
}

/*
**	Try placing given tetriminos anywhere on the map
*/

static int	place_tetri(t_map *map, t_tetriminos *tetri)
{
	t_point		*pt;

	pt = tetri->pos;
	if (Y >= END)
		set_point(pt, X + 1, 0);
	if (X > END - tetri->height || Y > END - tetri->width)
		return (0);
	while (X < END)
	{
		while (Y < END)
		{
			if (place_at(map, pt, tetri))
				return (1);
			Y += 1;
		}
		set_point(pt, X + 1, 0);
	}
	return (0);
}

/*
**	Try placing all tetriminos on the map
*/

static int	place_all(t_map *map, t_list *lst)
{
	if (!lst)
		return (1);
	X_POS = 0;
	Y_POS = 0;
	while (place_tetri(map, TETRI))
	{
		if (place_all(map, lst->next))
			return (1);
		remove_tetri_from_map(map, TETRI);
		Y_POS += 1;
	}
	return (0);
}

/*
**	Find the smallest map fitting all tetriminos
*/

void		solve_tetriminos(t_map *map, t_list *lst)
{
	if (!(MAP = create_map(map)))
	{
		ft_memdel((void **)&map);
		trigger_error(ERR_MAP, NULL, NULL, lst);
	}
	if (place_all(map, lst) == 0)
	{
		ft_free_tab(&(MAP));
		map->size += 1;
		solve_tetriminos(map, lst);
		return ;
	}
	ft_print_tab(MAP);
	ft_free_tab(&(MAP));
	ft_memdel((void **)&map);
}
