# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/17 20:34:13 by mapandel          #+#    #+#              #
#    Updated: 2017/03/19 17:53:54 by mapandel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		game_2048

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror -Weverything

#			Sources

SRC =		sources/main.c \
			sources/game.c \
			sources/game_start.c \
			sources/game_new_piece.c \
			sources/fill_window.c \
			sources/game_up.c \
			sources/game_down.c \
			sources/game_left.c \
			sources/game_right.c \


OBJ =		$(SRC:.c=.o)

#			Library Path

LIBPATH =	libft/libft.a

#			Colors

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

#			Main Rules

.PHONY: all re glu clean fclean

$(NAME):
	@cd libft; $(MAKE) -f Makefile
	@echo "$(CYA)--::Compil Game_2048::--$(DEF)"
	@make $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH) -lncurses

all: $(NAME)

re: fclean all

glu: fclean all clean

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

#			Clean Rules

clean:
	@cd libft; $(MAKE) -f Makefile clean
	@echo "$(PUR)--::Binary Delection::--$(DEF)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)--::Executable and Library Delection::--$(DEF)"
	@rm -rf $(NAME) $(LIBPATH)
