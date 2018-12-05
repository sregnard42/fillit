/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:41:26 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/05 12:44:38 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Try placing tetriminos at given point
*/

int		place_at(t_map *map, t_point *pt2, t_tetriminos *tetri)
{
	t_point	*pt;
	int		i;

	pt = (t_point *)malloc(sizeof(t_point));
	i = 0;
	while (i < 4)
	{
		cpy_point(pt, tetri->pt[i++]);
		X += X2;
		Y += Y2;
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
		X += X2;
		Y += Y2;
		MAP[X][Y] = tetri->c;
	}
	ft_memdel((void **)&pt);
	return (1);
}

/*
**	Try placing given tetriminos anywhere on the map
*/

int		place_tetri(t_map *map, t_tetriminos *tetri)
{
	t_point		*pt;

	pt = new_point(0, 0);
	while (X < END)
	{
		while (Y < END)
		{
			if (place_at(map, pt, tetri))
				return (1);
			Y += 1;
		}
		Y = 0;
		X += 1;
	}
	ft_memdel((void **)&pt);
	return (0);
}

/*
**	Try placing all tetriminos on the map
*/

int		place_all(t_map *map, t_list *lst, int nb_tetriminos, int nb_placed)
{
	if (nb_tetriminos == nb_placed)
		return (1);
	while (lst)
	{
		if (place_tetri(map, TETRI) == 1)
		{
			nb_placed++;
			TETRI->placed = 1;
			if (place_all(map, lst->next, nb_tetriminos, nb_placed))
				return (1);
			else
			{
				nb_placed--;
				TETRI->placed = 0;
			}
		}
		lst = lst->next;
	}
	return (0);
}


/*
** Reset placed to 0 for all tetriminos
*/

void	reset_tetri_placed(t_list *lst)
{
	while (lst)
	{
		TETRI->placed = 0;
		lst = lst->next;
	}
}

/*
**	Find the smallest map fitting all tetriminos
*/

char	**solve_tetriminos(t_list *lst, int nb_tetriminos)
{
	char	**tab;
	t_map	*map;
	size_t	size;
	int		solved;

	size = 4;
	solved = 0;
	while (solved == 0)
	{
		if (size > 4)
		{
			ft_free_tab(&(MAP));
			ft_memdel((void **)&map);
		}
		if (!(map = create_map(size)))
			return (NULL);
		solved = place_all(map, lst, nb_tetriminos, 0);
		reset_tetri_placed(lst);
		size++;
	}
	tab = MAP;
	ft_memdel((void **)&map);
	return (tab);
}
