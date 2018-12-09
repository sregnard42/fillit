/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:13:18 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/09 15:10:03 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "list.h"
# include "tetriminos.h"
# include "map.h"

# define STARTING_SIZE	2

char	**solve_tetriminos(t_list *lst, int nb_tetriminos, int starting_size);

#endif
