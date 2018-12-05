#include "fillit.h"

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
** Remove given tetriminos from map
*/

void	remove_tetri_from_map(t_map *map, t_tetriminos *tetri)
{
	t_point	*pt;

	pt = new_point(0, 0);
	while (X < END)
	{
		while (Y < END)
		{
			if (MAP[X][Y] == tetri->c)
				MAP[X][Y] = EMPTY_BLOCK;
			Y += 1;
		}
		Y = 0;
		X += 1;
	}
	ft_memdel((void **)&pt);
}
