/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:37:24 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/03 09:35:05 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "fillit.h"

# define MAP	(map->map)
# define END	(map->size)

typedef struct	s_map
{
	char		**map;
	int		size;
}				t_map;

t_map			*create_map(size_t size);
int				block_available(t_map *map, t_point *pt);

#endif
