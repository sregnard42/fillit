/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:23:56 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/06 13:13:09 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Generate 2D map of given size filled with empty blocks
*/

t_map	*create_map(int size)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(MAP = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < END)
	{
		if (!(MAP[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (j < END)
			MAP[i][j++] = EMPTY_BLOCK;
		MAP[i++][j] = '\0';
	}
	MAP[i] = 0;
	return (map);
}

/*
**	Returns 1 if given block exists and is empty in given map
*/

int		block_available(t_map *map, t_point *pt)
{
	if (!pt)
		return (0);
	if (X < 0 || Y < 0 || X >= END || Y >= END)
		return (0);
	return (MAP[X][Y] == EMPTY_BLOCK);
}
