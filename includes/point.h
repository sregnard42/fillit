/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:21:02 by sregnard          #+#    #+#             */
/*   Updated: 2018/11/30 15:58:02 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "fillit.h"

# define X	(pt->x)
# define Y	(pt->y)
# define X2	(pt2->x)
# define Y2	(pt2->y)
# define X_MIN	(min->x)
# define Y_MIN	(min->y)
# define X_MAX	(max->x)
# define Y_MAX	(max->y)

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_point				*new_point(int x, int y);
void				cpy_point(t_point *dst, t_point *src);
void				set_point(t_point *pt, int x, int y);
int					isneg_point(t_point *pt);

#endif
