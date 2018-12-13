/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:13:18 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/10 11:32:05 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "list.h"
# include "tetriminos.h"
# include "map.h"

# define STARTING_SIZE	2

void	solve_tetriminos(t_map *map, t_list *lst);

#endif
