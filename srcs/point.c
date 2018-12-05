/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:23:36 by sregnard          #+#    #+#             */
/*   Updated: 2018/11/30 16:11:24 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Create new point with given coordinates
*/

t_point		*new_point(int x, int y)
{
	t_point	*pt;

	if (!(pt = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	set_point(pt, x, y);
	return (pt);
}

/*
**	Copy coordinates of src point to dst point
*/

void		cpy_point(t_point *dst, t_point *src)
{
	if (!dst || !src)
		return ;
	dst->x = src->x;
	dst->y = src->y;
}

/*
**	Set coordinates of point to x and y
*/

void		set_point(t_point *pt, int x, int y)
{
	if (!pt)
		return ;
	pt->x = x;
	pt->y = y;
}
