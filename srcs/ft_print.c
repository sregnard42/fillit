#include "fillit.h"

/*
**	Display tetriminos values
*/

void				print_tetriminos(t_tetriminos *tetri)
{
	int		i;
	int		j;

	if (!tetri)
		return ;
	ft_putstr("[Tetriminos] = ");
	ft_putchar(tetri->c);
	i = 0;
	while (i < 4)
	{
		ft_putstr("\tpt[");
		ft_putnbr(i);
		ft_putstr("] = ");
		print_point(tetri->pt[i++]);
	}
	ft_putln();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			ft_putchar(tetri->blocks[i][j++]);
		ft_putln();
		i++;
	}
}

/*
**	Display the coordinates of a point
*/

void		print_point(t_point *pt)
{
	if (!pt)
		return ;
	ft_putchar('(');
	ft_putnbr(pt->x);
	ft_putchar(',');
	ft_putchar(' ');
	ft_putnbr(pt->y);
	ft_putchar(')');
}

/*
** Display all tetriminos contained in the list
*/

void	print_lst(t_list *lst)
{
	while (lst)
	{
		print_tetriminos(lst->content);
		lst = lst->next;
	}
}
