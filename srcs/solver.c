/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:41:26 by sregnard          #+#    #+#             */
/*   Updated: 2018/12/05 16:28:45 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_print.c"

/*
**	Try placing tetriminos at given point
*/

int		place_at(t_map *map, t_point *pt2, t_tetriminos *tetri)
{
	t_point	*pt;
	int		i;

	pt = (t_point *)malloc(sizeof(t_point));
	i = 0;
	while (i < 4)
	{
		cpy_point(pt, tetri->pt[i++]);
		X += X2;
		Y += Y2;
		if (block_available(map, pt) == 0)
		{
			ft_memdel((void **)&pt);
			return (0);
		}
	}
	i = 0;
	while (i < 4)
	{
		cpy_point(pt, tetri->pt[i++]);
		X += X2;
		Y += Y2;
		MAP[X][Y] = tetri->c;
	}
	ft_memdel((void **)&pt);
	return (1);
}

/*
**	Try placing given tetriminos anywhere on the map
*/

int		place_tetri(t_map *map, t_tetriminos *tetri)
{
//	t_point		*pt;

	if (tetri->placed == 1)
		return (0);
//	pt = new_point(0, 0);
	while (/*X*/tetri->last_position->x < END)
	{
		while (/*Y*/tetri->last_position->y < END)
		{
			if (place_at(map, tetri->last_position, tetri))
				return (1);
			/*Y*/tetri->last_position->y += 1;
		}
		/*Y*/tetri->last_position->y = 0;
		/*X*/tetri->last_position->x += 1;
	}
//	ft_memdel((void **)&pt);
	return (0);
}

/*
 **	remove one tetri from the map
 */

void	remove_one(t_map *map, t_list *lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < END)
	{
		while (j < END)
		{
			if (map->map[i][j] == TETRI->c)
				map->map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

/*
**	Try placing all tetriminos on the map
*/

int		place_all(t_map *map, t_list *lst, int nb_tetriminos, int nb_placed)
{
	t_list	*el;

	el = lst;
	if (nb_tetriminos == nb_placed)
		return (1);
	while (el)
	{
	ft_putendl("TETRI :");
	ft_putchar(((t_tetriminos*)(el->content))->c);
	ft_putnbr(((t_tetriminos*)(el->content))->last_position->x);
	ft_putnbr(((t_tetriminos*)(el->content))->last_position->y);
	ft_putendl("");
	ft_print_tab(map->map);
	ft_putendl("");
		if (place_tetri(map, ((t_tetriminos*)(el->content))) == 1)
		{
			nb_placed++;
			((t_tetriminos*)(el->content))->placed = 1;
			if (place_all(map, lst, nb_tetriminos, nb_placed))
				return (1);
			else
			{
				remove_one(map, el);
				nb_placed--;
				((t_tetriminos*)(el->content))->placed = 0;
			}
		}
		el = el->next;
	}
	return (0);
}


/*
** Reset placed to 0 for all tetriminos
*/

void	reset_tetri_placed(t_list *lst)
{
	while (lst)
	{
		TETRI->placed = 0;
		lst = lst->next;
	}
}

/*
**	Find the smallest map fitting all tetriminos
*/

char	**solve_tetriminos(t_list *lst, int nb_tetriminos)
{
	char	**tab;
	t_map	*map;
	size_t	size;
	int		solved;

	size = 2;
	solved = 0;
	while (solved == 0)
	{
		if (size > 2)
		{
			ft_free_tab(&(MAP));
			ft_memdel((void **)&map);
		}
		if (!(map = create_map(size)))
			return (NULL);
		solved = place_all(map, lst, nb_tetriminos, 0);
		reset_tetri_placed(lst);
		size++;
	}
	tab = MAP;
	ft_memdel((void **)&map);
	return (tab);
}
