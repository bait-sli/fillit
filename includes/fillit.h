/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:43:08 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/18 10:50:28 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# define USAGE {ft_putstr("usage: fillit file_path\n");return (0);}
# define ERROR {ft_putstr("error\n");return (0);}

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_piece
{
	char		name;
	t_point		point[4];
}				t_piece;

void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_putstr(char const *s);
int				ft_strlen(char const *s);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_strcnew(size_t size, char c);
int				file_checker(int fd);
int				check_is_valid(char buf[21]);
int				is_one_block(char buf[21]);
int				get_pieces_list(int fd, t_piece list[27]);
int				resolve_fillit(char *file_name);
int				fillit(char **sol_square, t_piece list[27]);
int				try_add_piece(t_piece tetris, char *sol_square,
								int size, int i);
int				remove_piece(t_piece tetris, char *sol_square, int size, int i);
int				print_solution(char *sol_square, int size);

#endif
