/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:15:29 by sregnard          #+#    #+#             */
/*   Updated: 2018/11/30 15:11:25 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check if given line is respecting the format
*/

void	check_line(char *line, int line_count)
{
	if (line_count % 5 == 0)
	{
		if (line[0] != EOS)
			trigger_error(ERR_SEP);
	}
	else if (ft_strlen(line) != 4)
		trigger_error(ERR_LEN);
	while (*line)
	{
		if (*line != EMPTY_BLOCK && *line != FILLED_BLOCK)
			trigger_error(ERR_CHAR);
		line++;
	}
}

/*
** Show error and exit program (SET DEBUG AT 1 in errors.h to show more errors)
*/

void	trigger_error(char *err_msg)
{
	ft_putendl(MSG_ERR);
	if (ft_strequ(err_msg, ERR_USAGE))
		ft_putendl(ERR_USAGE);
	else if (DEBUG && !ft_strequ(err_msg, MSG_ERR))
	{
		ft_putstr(DEBUG_ON);
		ft_putendl(err_msg);
	}
	exit(EXIT_FAILURE);
}
