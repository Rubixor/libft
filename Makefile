# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 14:16:43 by mdenoyel          #+#    #+#              #
#    Updated: 2016/11/22 15:04:11 by mdenoyel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJ = create_tab.o \
	  create_win.o \
	  draw_lines.o \
	  main.o \
	  parsing.o

CFLAGS = -Wall -Wextra -Werror

INC = -I ./libft/includes/ -I ./

LIB = ./libft/libftprintf.a

%.o : %.c
	$(CC) $(CFLAGS) -c $(INC) $<

$(NAME) : $(OBJ)
	@make -C ./libft/ re
	$(CC) $(OBJ) -o $(NAME) $(LIB) -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
