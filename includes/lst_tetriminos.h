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

t_list		*lst_tetriminos(char **content);

#endif
