/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:21:06 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/16 17:24:44 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_solution(char *sol_square, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		write(1, sol_square + i * size, size);
		write(1, "\n", 1);
		i++;
	}
	return (1);
}
