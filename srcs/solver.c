/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:41:26 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/04 15:30:19 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Try placing tetriminos at given point, returns 0 if not possible
*/

int		place_tetri(t_map *map, t_point *p, t_tetriminos *tetri)
{
	t_point	*pt;
	int		i;

	pt = (t_point *)malloc(sizeof(t_point));
	i = 0;
	while (i < 4)
	{
		cpy_point(pt, tetri->pt[i++]);
		pt->x += p->x;
		pt->y += p->y;
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
		pt->x += p->x;
		pt->y += p->y;
		map->map[pt->x][pt->y] = tetri->c;
	}
	ft_memdel((void **)&pt);
	return (1);
}

/*
**	Try placing any tetrminos at given point
**	returns element containing the placed tetriminos if successful
**	returns NULL if all attempts failed
*/

int		place_at(t_map *map, t_point *pt, t_list *lst)
{
	t_tetriminos	*tetri;

	while (lst)
	{
		tetri = (t_tetriminos *)lst->content;
		if (tetri->placed == 0)
		{
			if (place_tetri(map, pt, tetri))
			{
				tetri->placed = 1;
				return (1);
			}
		}
		lst = lst->next;
	}
	return (0);
}

/*
**	Try placing all tetriminos contained in the list, returns 0 if failed
*/

int		place_all(t_map *map, t_list *lst, int nb_tetriminos, int nb_placed)
{
	t_point	*pt;

	pt = new_point(0, 0);
	while (pt->x < (int)map->size)
	{
		pt->y = 0;
		while (pt->y < (int)map->size)
		{
			if (place_at(map, pt, lst) == 1)
			{
				nb_placed++;
				place_all(map, lst, nb_tetriminos, nb_placed);
			}
			if (nb_tetriminos == nb_placed)
			{
				ft_memdel((void **)&pt);
				return (1);
			}
			pt->y += 1;
		}
		pt->x += 1;
	}
	while (lst)
	{
		((t_tetriminos *)(lst->content))->placed = 0;
		lst = lst->next;
	}
	ft_memdel((void **)&pt);
	return (0);
}

/*
**	Find the smallest square fitting all tetriminos
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
			ft_free_tab(&(map->map));
			ft_memdel((void **)&map);
		}
		if (!(map = create_map(size)))
			return (NULL);
		solved = place_all(map, lst, nb_tetriminos, 0);
		size++;
	}
	tab = map->map;
	ft_memdel((void **)&map);
	return (tab);
}
