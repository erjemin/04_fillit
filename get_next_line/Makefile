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

NAME =	get_next_line.a
FILES =	get_next_line.c

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -c $(FILES) -I.
	ar -rc $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
