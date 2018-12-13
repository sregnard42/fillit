/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:23:56 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/10 11:35:10 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Create new instance of map
*/

t_map	*new_map(int size)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	return (map);
}

/*
**	Generate 2D map
*/

char	**create_map(t_map *map)
{
	int		i;
	int		j;

	if (!(MAP = (char **)malloc(sizeof(char *) * (END + 1))))
		return (NULL);
	i = 0;
	while (i < END)
	{
		if (!(MAP[i] = (char *)malloc(sizeof(char) * (END + 1))))
			return (NULL);
		j = 0;
		while (j < END)
			MAP[i][j++] = EMPTY_BLOCK;
		MAP[i++][j] = '\0';
	}
	MAP[i] = 0;
	return (MAP);
}

/*
**	Calc the starting size of the map according to the number of tetri
*/

int		get_starting_size(int nb_tetriminos)
{
	int size;

	size = STARTING_SIZE;
	while (size < ((nb_tetriminos * 4) / size))
		size += 1;
	return (size);
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
