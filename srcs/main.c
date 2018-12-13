/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 08:52:24 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/10 11:55:01 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Read the file
*/

static char	*read_file(int fd, char *content)
{
	char	*line;
	int		line_count;
	int		r;

	line_count = 0;
	while ((r = get_next_line(fd, &line)) == 1)
	{
		line_count++;
		check_line(line, line_count);
		if (!(content = ft_stradd(content, line)))
			trigger_error(ERR_FILE, NULL, NULL, NULL);
		if (!(content = ft_stradd(content, "\n")))
			trigger_error(ERR_FILE, NULL, NULL, NULL);
		free(line);
	}
	if (r == -1)
		trigger_error(ERR_FILE, content, NULL, NULL);
	return (content);
}

/*
**	Parse all file content into one string
*/

static char	**parse_file(char *file, int *nb_tetriminos)
{
	char	**res;
	char	*content;
	int		fd;

	content = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		trigger_error(ERR_FILE, NULL, NULL, NULL);
	content = read_file(fd, content);
	if (close(fd) == -1)
		trigger_error(ERR_FILE, content, NULL, NULL);
	*nb_tetriminos = ((ft_strlen(content) + 1) / 21);
	if ((ft_strlen(content) + 1) % 21 > 0)
		trigger_error(ERR_NORM, content, NULL, NULL);
	res = ft_strsplit(content, '\n');
	free(content);
	return (res);
}

/*
**	Beginning
*/

int			main(int ac, char **av)
{
	t_map	*map;
	t_list	*lst;
	char	**tab;
	int		nb_tetriminos;

	if (ac != 2)
		trigger_error(ERR_USAGE, NULL, NULL, NULL);
	if ((tab = parse_file(av[1], &nb_tetriminos)) == NULL)
		trigger_error(ERR_PARS_FILE, NULL, NULL, NULL);
	if (nb_tetriminos < MIN_TETRIMINOS || nb_tetriminos > MAX_TETRIMINOS)
		trigger_error(ERR_NB_TETRI, NULL, tab, NULL);
	if ((lst = lst_tetriminos(tab)) == NULL)
		trigger_error(ERR_CREAT_LST, NULL, tab, NULL);
	ft_free_tab(&tab);
	if (!(map = new_map(STARTING_SIZE)))
		trigger_error(ERR_MAP, NULL, NULL, lst);
	solve_tetriminos(map, lst);
	ft_lstdel(&lst, &free_tetriminos);
	return (0);
}
