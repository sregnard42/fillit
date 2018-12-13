/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:58:36 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/10 11:35:24 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Find all points defining a tetriminos
*/

static int		set_points(char **content, int i, t_tetriminos *tetri)
{
	int				pt_count;
	int				end;
	int				j;

	pt_count = 0;
	end = i + 4;
	while (i < end)
	{
		j = 0;
		while (content[i][j])
		{
			tetri->blocks[i % 4][j] = content[i][j];
			if (content[i][j] == FILLED_BLOCK)
			{
				tetri->pt[pt_count++] = new_point(i % 4, j);
				if (pt_count > 4)
					return (0);
			}
			j += 1;
		}
		i += 1;
	}
	if (pt_count < 4)
		return (0);
	return (check_blocks(tetri));
}

/*
** Create a list element containing a tetriminos
*/

static t_list	*get_tetriminos(char **content, int i, char c)
{
	t_list			*elem;
	t_tetriminos	*tetri;

	if (!(tetri = new_tetriminos(c)))
		return (NULL);
	if (!(set_points(content, i, tetri)))
	{
		free_tetriminos((void **)&tetri, sizeof(t_tetriminos));
		return (NULL);
	}
	normalize_tetriminos(tetri);
	elem = ft_lstnew(tetri, sizeof(t_tetriminos));
	ft_memdel((void **)&tetri);
	return (elem);
}

/*
** Create a list of all tetriminos
*/

t_list			*lst_tetriminos(char **content)
{
	t_list			*lst_head;
	t_list			*elem;
	char			c;
	int				i;

	lst_head = NULL;
	c = 'A';
	i = 0;
	while (content && content[i])
	{
		if (!(elem = get_tetriminos(content, i, c)))
		{
			ft_lstdel(&lst_head, &free_tetriminos);
			return (NULL);
		}
		if (lst_head == NULL)
			lst_head = elem;
		else
			ft_lstadd(&lst_head, elem);
		i += 4;
		c += 1;
	}
	return (lst_head);
}
