/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:28:33 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/17 19:41:35 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		resolve_fillit(char *file_name)
{
	int				fd;
	t_piece			*list;
	char			*sol_square;
	int				size;

	if ((list = ft_memalloc(sizeof(t_piece) * 27)) == 0)
		exit(EXIT_FAILURE);
	fd = open(file_name, O_RDONLY);
	get_pieces_list(fd, list);
	close(fd);
	size = fillit(&sol_square, list);
	free(list);
	print_solution(sol_square, size);
	free(sol_square);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		USAGE;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ERROR;
	if (file_checker(fd) == 0)
		ERROR;
	close(fd);
	resolve_fillit(av[1]);
	return (1);
}
