/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:14:37 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/09 16:25:10 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "tetriminos.h"

# define DEBUG				0
# define DEBUG_ON			"DEBUG : "
# define MSG_ERR			"error"

# define ERR_USAGE			"usage: ./fillit source_file"
# define ERR_FILE			"Invalid file descriptor."
# define ERR_SEP			"Expected a single separator : \\n."
# define ERR_LEN			"Expected a line length of 4."
# define ERR_CHAR			"Unexpected character inside file."
# define ERR_NORM			"Norm error."
# define ERR_NB_TETRI		"Too many or not enough tetriminos."
# define ERR_TETRI_PT_MIN	"Not enough blocks in tetriminos."
# define ERR_TETRI_PT_MAX	"Too many blocks in tetriminos."
# define ERR_PARS_FILE		"Error while parsing file."
# define ERR_CREAT_LST		"Error while creating list."

void	check_line(char *line, int line_count);
int		check_blocks(t_tetriminos *tetri);
void	trigger_error(char *err_code);

#endif
