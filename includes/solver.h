/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:13:18 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/06 12:58:47 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# include "list.h"
# include "tetriminos.h"
# include "map.h"

char	**solve_tetriminos(t_list *lst, int nb_tetriminos);

#endif
