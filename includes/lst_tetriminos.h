/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tetriminos.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:58:51 by sregnard          #+#    #+#             */
/*   Updated: 2018/11/30 13:28:35 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_TETRIMINOS_H
# define LST_TETRIMINOS_H

# include "tetriminos.h"
# include "list.h"
# include "point.h"

# define TETRI	((t_tetriminos *)lst->content)

int			set_points(char **content, int i, t_tetriminos **ptr);
t_list		*get_tetriminos(char **content, int i, char c);
t_list		*lst_tetriminos(char **content);
void		reset_tetri_placed(t_list *lst);

#endif
