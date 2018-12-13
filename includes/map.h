/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:37:24 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/10 10:57:23 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "point.h"

# define MAP	(map->map)
# define END	(map->size)

typedef struct	s_map
{
	char		**map;
	int			size;
}				t_map;

t_map			*new_map();
char			**create_map(t_map *map);
int				get_starting_size(int nb_tetriminos);
int				block_available(t_map *map, t_point *pt);

#endif
