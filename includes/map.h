/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 08:37:24 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/07 12:32:22 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "point.h"

//# define MAP	(map->map)
//# define END	size
/*
typedef struct	s_map
{
	char		**map;
	int			size;
}				t_map;
*/
//t_map			*create_map(int size);
char			**create_map(int size);
int				block_available(char **map, t_point *pt);

#endif
