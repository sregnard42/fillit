/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:41:26 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/07 15:23:44 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
		set_point(pt, X + X2, Y + Y2);
		MAP[X][Y] = tetri->c;
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

	if (tetri->placed == 1)
		return (0);
	pt = tetri->pos;
	if (X >= END || Y >= END)
		return (0);
	while (X < END)
	{
		while (Y < END)
		{
//	ft_putendl("segfault 3");
			if (place_at(map, pt, tetri))
				return (1);
			Y += 1;
//	ft_putnbr(Y);
//	ft_putnbr(END);
//	ft_putendl("segfault 4");
		}
		Y = 0;
		X += 1;
	}
	return (0);
}

/*
**	Try placing all tetriminos on the map
*/

static int	place_all(t_map *map, t_list *head, int nb_tetri, int nb_placed)
{
	t_list	*lst;
//	char	c;

	lst = head;
	while (lst)
	{
		while (TETRI->placed == 1)
		{
			lst = lst->next;
			if (!lst)
				return (0);
		}
		while (place_tetri(map, TETRI) == 1)
		{
			nb_placed++;
			TETRI->placed = 1;
	ft_putchar(TETRI->c);
	ft_putendl("");
	ft_print_tab(map->map);
//			if (nb_tetri > nb_placed && check_place_enough(map, head) == 0)
//				return (0);
//	ft_putendl("");
//	scanf("%c", &c);
			if (nb_tetri == nb_placed
					|| place_all(map, head, nb_tetri, nb_placed))
				return (1);
			else
			{
//		ft_putstr("move or remove : ");
//		ft_putchar(TETRI->c);
//		ft_putendl("");
				nb_placed--;
				TETRI->placed = 0;
				remove_tetri_from_map(map, TETRI);
				Y_POS += 1;
			}
		}
		if (TETRI->placed == 0)
			set_point(TETRI->pos, 0, 0);
		lst = lst->next;
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

	starting_size = ft_sqrt(nb_tetriminos * 4);
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
		solved = place_all(map, lst, nb_tetriminos, 0);
		reset_tetri_placed(lst);
		size++;
	}
	tab = MAP;
	ft_memdel((void **)&map);
	return (tab);
}
