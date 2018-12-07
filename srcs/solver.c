/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:04:41 by jdugoudr          #+#    #+#             */
/*   Updated: 2018/12/07 15:23:42 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	place_one_tetri(char **map, t_list *lst, int size)
{
	
}

static int	place_all_tetri(char **map, t_list head, int size)
{
	t_list	*lst;

	lst = head;
	while (lst && TETRI->placed == 1)
		lst = lst->next;
	if (!lst)
		return (1);
	while (lst)
	{
		if (TETRI->placed == 1)
			while (lst && TETRI->placed == 1)
				lst = lst->next;
		else if (place_one_tetri(map, lst, size))
		{
			TETRI->placed = 1;
			return (place_all_tetri(map, head, size));
		}
		else
		{
			if (Y_POS + 1 < size)
				Y_POS++;
			else if (Y_POS + 1 == size && X_POS + 1 < size)
			{
				Y_POS = 0;
				X_POS++;
			}
			else
			{
				Y_POS = 0;
				X_POS = 0;
				lst = lst->next;
			}
		}
	}
	return (0);
}

char		**solve_tetriminos(t_list *lst, int nb_treminos)
{
	int		size;
	char	**map;

	size = 3;
	while ((map = creatmap(size)))
	{
		if (place_all_tetri(map, lst, size))
			break ;
		else
		{
			reset_tetri_placed(lst);
			ft_free_tab(map);
			size++;
		}
	}
	return (map);
}
