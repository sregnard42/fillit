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

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_point				*new_point(int x, int y);
void				cpy_point(t_point *dst, t_point *src);
void				set_point(t_point *pt, int x, int y);
int					isneg_point(t_point *pt);
void				print_point(t_point *pt);

#endif
