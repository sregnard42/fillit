/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 08:52:24 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/09 16:27:16 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 ** read the file
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
		content = ft_stradd(content, line);
		content = ft_stradd(content, "\n");
		free(line);
	}
	if (r == -1)
	{
		free(content);
		trigger_error(ERR_FILE);
	}
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
	((fd = open(file, O_RDONLY)) == -1) ? trigger_error(ERR_FILE) : 1;
	content = read_file(fd, content);
	if (close(fd) == -1)
	{
		free(content);
		trigger_error(ERR_FILE);
	}
	*nb_tetriminos = ((ft_strlen(content) + 1) / 21);
	if ((ft_strlen(content) + 1) % 21 > 0)
	{
		free(content);
		trigger_error(ERR_NORM);
	}
	res = ft_strsplit(content, '\n');
	free(content);
	if (res == NULL)
		trigger_error(ERR_PARS_FILE);
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
	if (nb_tetriminos < MIN_TETRIMINOS || nb_tetriminos > MAX_TETRIMINOS)
	{
		ft_free_tab(&tab);
		trigger_error(ERR_NB_TETRI);
	}
	if ((lst = lst_tetriminos(tab)) == NULL)
	{
		ft_free_tab(&tab);
		trigger_error(ERR_CREAT_LST);
	}
	ft_free_tab(&tab);
	tab = solve_tetriminos(lst, nb_tetriminos, STARTING_SIZE);
	ft_print_tab(tab);
	ft_free_tab(&tab);
	ft_lstdel(&lst, &free_tetriminos);
	return (0);
}
