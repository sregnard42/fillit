/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:41:26 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/07 14:24:23 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char		**solve_tetriminos(t_list *lst, int nb_tetriminos)
{
	char	**tab;
	t_map	*map;
	int		starting_size;
	int		size;
	int		solved;

	starting_size = 2;
	while (starting_size < ((nb_tetriminos * 4) / starting_size))
		starting_size += 1;
	size = starting_size;
	solved = 0;
	while (solved == 0)
	{
		if (size > starting_size)
		{
			ft_free_tab(&(MAP));
			ft_memdel((void **)&map);
		}
		if (!(map = create_map(size)))
			return (NULL);
		solved = place_all(map, lst);
		size++;
	}
	tab = MAP;
	ft_memdel((void **)&map);
	return (tab);
}
