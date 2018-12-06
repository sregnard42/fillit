/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 08:52:24 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/06 08:52:31 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Parse all file content into one string
*/

static char	**parse_file(char *file, int *nb_tetriminos)
{
	char	**res;
	char	*content;
	char	*line;
	int		line_count;
	int		fd;

	content = NULL;
	line_count = 0;
	((fd = open(file, O_RDONLY)) == -1) ? trigger_error(ERR_FILE) : 1;
	while (get_next_line(fd, &line) == 1)
	{
		line_count++;
		check_line(line, line_count);
		content = ft_stradd(content, line);
		content = ft_stradd(content, "\n");
		free(line);
	}
	close(fd) == -1 ? trigger_error(ERR_FILE) : 1;
	*nb_tetriminos = ((ft_strlen(content) + 1) / 21);
	(ft_strlen(content) + 1) % 21 > 0 ? trigger_error(ERR_NORM) : 1;
	res = ft_strsplit(content, '\n');
	free(content);
	return (res);
}

/*
**	Beginning
*/

int			main(int ac, char **av)
{
	t_list	*lst;
	char	**tab;
	int		nb_tetriminos;

	if (ac != 2)
		trigger_error(ERR_USAGE);
	if ((tab = parse_file(av[1], &nb_tetriminos)) == NULL)
		trigger_error(ERR_PARS_FILE);
	nb_tetriminos < MIN_TETRIMINOS ? trigger_error(ERR_TETRI_MIN) : 1;
	nb_tetriminos > MAX_TETRIMINOS ? trigger_error(ERR_TETRI_MAX) : 1;
	if ((lst = lst_tetriminos(tab)) == NULL)
		trigger_error(ERR_CREAT_LST);
	ft_free_tab(&tab);
	tab = solve_tetriminos(lst, nb_tetriminos);
	ft_print_tab(tab);
	ft_free_tab(&tab);
	ft_lstdel(&lst, &free_tetriminos);
	return (0);
}
