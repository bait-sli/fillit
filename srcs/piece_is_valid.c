/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:57:03 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/18 10:27:25 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		number_of_points(char buf[21])
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
			n++;
		i++;
	}
	return (n);
}

static int		number_of_neighboors(char buf[21], int i)
{
	int		n;

	n = 0;
	if (i % 5 - 1 >= 0 && buf[i - 1] == '#')
		n++;
	if (i % 5 + 1 < 4 && buf[i + 1] == '#')
		n++;
	if (i / 5 - 1 >= 0 && buf[i - 5] == '#')
		n++;
	if (i / 5 + 1 < 4 && buf[i + 5] == '#')
		n++;
	return (n);
}

static int		check_neighboorhood(char buf[21])
{
	int		i;
	int		n;
	int		two_neighboors;

	i = 0;
	two_neighboors = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			n = number_of_neighboors(buf, i);
			if (n == 0)
				return (0);
			if (n > 1)
				two_neighboors = 1;
		}
		i++;
	}
	if (two_neighboors == 0)
		return (0);
	return (1);
}

int				check_is_valid(char buf[21])
{
	if (number_of_points(buf) != 4)
		return (0);
	if (!check_neighboorhood(buf))
		return (0);
	return (1);
}
