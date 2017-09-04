# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2016/11/17 18:52:44 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME	= main.c\
						file_checker.c\
						piece_is_valid.c\
						get_pieces_list.c\
						fillit.c\
						add_and_remove_pieces.c\
						print_solution.c\
						ft_memset.c\
						ft_strcnew.c\
						ft_strlen.c\
						ft_putstr.c\
						ft_bzero.c\
						ft_memalloc.c\

SRCS_PATH = srcs/
SRCS			= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
NAME			= fillit
FLAG			= -Wall -Werror -Wextra
INC				= ./includes/
OBJ				= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) -I $(INC) $(OBJ) -o $(NAME)

%.o: %.c
	gcc -c $(FLAGS) -I includes $< -o $@

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
