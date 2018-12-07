/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:58:50 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/06 13:44:06 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	reset_tetri_placed(t_list *lst);
void	remove_tetri_from_map(t_map *map, t_tetriminos *tetri);

#endif
