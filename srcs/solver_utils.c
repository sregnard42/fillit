/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 08:50:27 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/06 16:21:34 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
** Remove given tetriminos from map
*/

void	remove_tetri_from_map(t_map *map, t_tetriminos *tetri)
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
int		check_place_enough(t_map *map, t_list *lst)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	i = 0;
	j = 0;
	while (i < END - 1)
	{
		while (j < END - 1)
		{
			if (map->map[i][j] == '.' && (map->map[i][j + 1] == '.' || map->map[i + 1][j] == '.'))
				nb++;
			j++;
		}
		j = 0;
		i++;
	}
	while (lst)
	{
		if (TETRI->placed == 0)
			nb = nb - 4;
		lst = lst->next;
	}
	if (nb < 0)
		return (0);
	ft_putnbr(nb);
	ft_putendl("");
	return (1);
}
*/
