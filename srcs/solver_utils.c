/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 08:50:27 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/06 08:50:32 by sregnard         ###   ########.fr       */
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
	t_point	*pt2;
	int	i;

	i = 0;
	pt = tetri->pos;
	while(i < 4)
	{
		pt2 = tetri->pt[i++];
		MAP[X + X2][Y + Y2] = EMPTY_BLOCK;
	}
}
