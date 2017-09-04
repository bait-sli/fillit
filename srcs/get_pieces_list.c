/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:58:49 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/17 18:56:12 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

static int		add_piece_tolist(char buf[21], t_piece list[27], int n)
{
	int			i;
	int			point_nbr;
	t_point		origin;

	i = 0;
	origin.x = -1;
	point_nbr = 0;
	while (i < 20 || point_nbr < 4)
	{
		if (buf[i] == '#')
		{
			if (origin.x == -1)
			{
				set_point(&origin, i / 5, i % 5);
				set_point(&(list[n].point[point_nbr]), 0, 0);
			}
			else
				set_point(&(list[n].point[point_nbr]),
						i / 5 - origin.x, i % 5 - origin.y);
			point_nbr++;
		}
		i++;
	}
	list[n].name = 'A' + n;
	return (1);
}

int				get_pieces_list(int fd, t_piece list[27])
{
	int		ret;
	int		piece_nbr;
	char	buf[21];

	piece_nbr = 0;
	while ((ret = read(fd, buf, 21)))
	{
		add_piece_tolist(buf, list, piece_nbr);
		piece_nbr++;
	}
	list[piece_nbr].name = '\0';
	return (1);
}
