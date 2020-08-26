# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mretha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 14:05:28 by mretha            #+#    #+#              #
#    Updated: 2019/06/19 14:26:08 by mretha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = 	main.c \
	tet_solver.c \
	tet_map.c \
	tet_read_check_covert.c \
	tet_print.c

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)


$(NAME):
	make -C libft/ fclean && make -C libft/
	make -C get_next_line/ fclean && make -C get_next_line/
	gcc $(CFLAGS) $(SRC) libft/*.o get_next_line/*.o -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"


clean:
	@rm -rf $(OBJ)
	@echo "\033[32mRemoved Object Files\033[0m"


fclean: clean
	@rm $(NAME)
	@echo "\033[32mRemoved Executable\033[0m"


re: fclean all
