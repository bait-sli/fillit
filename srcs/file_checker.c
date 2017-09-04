/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:22:27 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/18 14:25:42 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_format(char buf[21], int last)
{
	int		i;

	i = 0;
	while (i < 21)
	{
		if (i % 5 == 4 || (i == 20 && last == 0))
		{
			if (buf[i] != '\n')
				return (0);
		}
		else if (i != 20)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (0);
		}
		i++;
	}
	return (1);
}

static int		piece_checker(char buf[21], int last)
{
	if (check_format(buf, last) == 0)
		return (0);
	if (check_is_valid(buf) == 0)
		return (0);
	return (1);
}

int				file_checker(int fd)
{
	int		n;
	int		ret;
	char	buf[21];

	n = 0;
	while ((ret = read(fd, buf, 21)) == 21)
	{
		if (piece_checker(buf, 0) == 0)
			return (0);
		n++;
	}
	if (ret != 20 || n > 25 || piece_checker(buf, 1) == 0)
		return (0);
	return (1);
}
