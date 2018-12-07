/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:13:18 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/06 14:15:01 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "list.h"
# include "tetriminos.h"
# include "map.h"

char	**solve_tetriminos(t_list *lst, int nb_tetriminos);
void	reset_tetri_placed(t_list *lst);
void	remove_tetri_from_map(t_map *map, t_tetriminos *tetri);
int		check_place_enough(t_map *map, t_list *lst);

#endif
