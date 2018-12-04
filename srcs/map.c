/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:23:56 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/03 09:46:31 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*
**	Generate tab filled with empty blocks, equivalent of tab[size][size]
*/

t_map	*create_map(size_t size)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < (int)size)
	{
		if (!(map->map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (j < (int)size)
			map->map[i][j++] = EMPTY_BLOCK;
		map->map[i++][j] = '\0';
	}
	map->map[i] = 0;
	return (map);
}

/*
**	Returns 1 if given point is valid and is empty in given map
*/

int		block_available(t_map *map, t_point *pt)
{
	int		x;
	int		y;

	if (!pt)
		return (0);
	x = pt->x;
	y = pt->y;
	if (x < 0 || y < 0 || x >= (int)map->size || y >= (int)map->size)
		return (0);
	return (map->map[x][y] == EMPTY_BLOCK);
}
