/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:05:21 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/05 19:24:07 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "errors.h"
# include "point.h"
# include "tetriminos.h"
# include "lst_tetriminos.h"
# include "solver.h"
# include "map.h"
# include "ft_print.h"
# include <fcntl.h>

# define EMPTY_BLOCK	'.'
# define FILLED_BLOCK	'#'
# define MIN_TETRIMINOS	2
# define MAX_TETRIMINOS	26

#endif
