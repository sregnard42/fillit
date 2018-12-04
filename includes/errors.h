/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:14:37 by sregnard          #+#    #+#             */
/*   Updated: 2018/11/30 13:28:18 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define DEBUG				0
# define DEBUG_ON			"DEBUG : "
# define MSG_ERR			"error"

# define ERR_USAGE			"usage: ./fillit source_file"
# define ERR_FILE			"Invalid file descriptor."
# define ERR_SEP			"Expected a single separator : \\n."
# define ERR_LEN			"Expected a line length of 4."
# define ERR_CHAR			"Unexpected character inside file."
# define ERR_TETRI_MIN		"Not enough tetriminos."
# define ERR_TETRI_MAX		"Too many tetriminos."
# define ERR_TETRI_PT_MIN	"Not enough blocks in tetriminos."
# define ERR_TETRI_PT_MAX	"Too many blocks in tetriminos."
# define ERR_PARS_FILE		"Error while parsing file."
# define ERR_CREAT_LST		"Error while creating list."

void	check_line(char *line, int line_count);
void	trigger_error(char *err_code);

#endif
