/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_and_remove_pieces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:42:34 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/17 18:43:56 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_add_piece(t_piece tetris, char *sol_square, int size, int i)
{
	int		n;
	int		x;
	int		y;

	n = 1;
	while (n < 4)
	{
		x = i / size + tetris.point[n].x;
		y = i % size + tetris.point[n].y;
		if (x < 0 || x >= size || y < 0 || y >= size ||
			sol_square[x * size + y] != '.')
			return (0);
		n++;
	}
	n = 0;
	while (n < 4)
	{
		x = i / size + tetris.point[n].x;
		y = i % size + tetris.point[n].y;
		sol_square[x * size + y] = tetris.name;
		n++;
	}
	return (1);
}

int		remove_piece(t_piece tetris, char *sol_square, int size, int i)
{
	int		n;
	int		x;
	int		y;

	n = 0;
	while (n < 4)
	{
		x = i / size + tetris.point[n].x;
		y = i % size + tetris.point[n].y;
		sol_square[x * size + y] = '.';
		n++;
	}
	return (1);
}
