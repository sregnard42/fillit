/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 09:15:29 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/10 11:34:47 by sregnard         ###   ########.fr       */
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
			trigger_error(ERR_SEP, NULL, NULL, NULL);
	}
	else if (ft_strlen(line) != 4)
		trigger_error(ERR_LEN, NULL, NULL, NULL);
	while (*line)
	{
		if (*line != EMPTY_BLOCK && *line != FILLED_BLOCK)
			trigger_error(ERR_CHAR, NULL, NULL, NULL);
		line++;
	}
}

/*
**	Returns wheter a tetri has all its blocks linked together
**	Returns 6 only if 4 blocks are linked together, 8 if square form
**	______1______1221_____________
**	22____2________________1____1_
**	22____2___12_____21____2____31
**	______1____21___12____12____1_
*/

int		check_blocks(t_tetriminos *tetri)
{
	t_point	*pt;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < 4)
	{
		pt = tetri->pt[i++];
		if (X > 0)
			if (tetri->blocks[X - 1][Y] != EMPTY_BLOCK)
				nb++;
		if (Y > 0)
			if (tetri->blocks[X][Y - 1] != EMPTY_BLOCK)
				nb++;
		if (X < 3)
			if (tetri->blocks[X + 1][Y] != EMPTY_BLOCK)
				nb++;
		if (Y < 3)
			if (tetri->blocks[X][Y + 1] != EMPTY_BLOCK)
				nb++;
	}
	return (nb >= 6);
}

/*
** Show error and exit program (SET DEBUG AT 1 in errors.h to show more errors)
*/

void	trigger_error(char *err_msg, char *content, char **tab, t_list *lst)
{
	ft_putendl(MSG_ERR);
	if (ft_strequ(err_msg, ERR_USAGE))
		ft_putendl(ERR_USAGE);
	else if (DEBUG && !ft_strequ(err_msg, MSG_ERR))
	{
		ft_putstr(DEBUG_ON);
		ft_putendl(err_msg);
	}
	if (content != NULL)
		free(content);
	if (tab != NULL)
		ft_free_tab(&tab);
	if (lst != NULL)
		ft_lstdel(&lst, &free_tetriminos);
	exit(EXIT_FAILURE);
}
