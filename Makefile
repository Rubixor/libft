# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdenoyel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:43:30 by mdenoyel          #+#    #+#              #
#    Updated: 2016/06/24 19:51:22 by mdenoyel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJ = ft_atoi.o \
	  ft_bzero.o \
	  ft_i128toa.o \
	  ft_isalnum.o \
	  ft_isalpha.o \
	  ft_isascii.o \
	  ft_isdigit.o \
	  ft_isprint.o \
	  ft_isspace.o \
	  ft_itoa.o \
	  ft_lst_pushback.o \
	  ft_lstadd.o \
	  ft_lstdel.o \
	  ft_lstdelone.o \
	  ft_lstinsert.o \
	  ft_lstiter.o \
	  ft_lstmap.o \
	  ft_lstnew.o \
	  ft_lstpushsort.o \
	  ft_memalloc.o \
	  ft_memccpy.o \
	  ft_memchr.o \
	  ft_memcmp.o \
	  ft_memcpy.o \
	  ft_memdel.o \
	  ft_memmove.o \
	  ft_memset.o \
	  ft_pgcd.o \
	  ft_putchar.o \
	  ft_putchar_fd.o \
	  ft_putendl.o \
	  ft_putendl_fd.o \
	  ft_putint128.o \
	  ft_putnbr.o \
	  ft_putnbr_fd.o \
	  ft_putstr.o \
	  ft_putstr_fd.o \
	  ft_size_bin.o \
	  ft_strcat.o \
	  ft_strchr.o \
	  ft_strcleanc.o \
	  ft_strclr.o \
	  ft_strcmp.o \
	  ft_strcpy.o \
	  ft_strdel.o \
	  ft_strdup.o \
	  ft_strdup_len.o \
	  ft_strequ.o \
	  ft_striter.o \
	  ft_striteri.o \
	  ft_strjoin.o \
	  ft_strlcat.o \
	  ft_strlen.o \
	  ft_strmap.o \
	  ft_strmapi.o \
	  ft_strncat.o \
	  ft_strncmp.o \
	  ft_strncpy.o \
	  ft_strnequ.o \
	  ft_strnew.o \
	  ft_strnstr.o \
	  ft_strrchr.o \
	  ft_strrev.o \
	  ft_strsplit.o \
	  ft_strstr.o \
	  ft_strsub.o \
	  ft_strsub_len.o \
	  ft_strtrim.o \
	  ft_swap.o \
	  ft_tolower.o \
	  ft_toupper.o \
	  ft_wcslen.o \

PRINTF = ft_printf.o \
		 pf_char.o \
		 pf_check_flags.o \
		 pf_check_len.o \
		 pf_check_modif.o \
		 pf_check_prec.o \
		 pf_display.o \
		 pf_init.o \
		 pf_int.o \
		 pf_intmaxt.o \
		 pf_long.o \
		 pf_longlong.o \
		 pf_newvar.o \
		 pf_short.o \
		 pf_sizet.o \
		 pf_string.o \
		 pf_treat.o \
		 pf_var_pushback.o \
		 pf_wintt.o \
		 pf_wchart.o

CFLAGS = -Wall -Wextra -Werror -g3

INC = -I ./includes/

%.o: %.c
	$(CC) $(CFLAGS) -c $(INC) $<

$(NAME) : $(OBJ) $(PRINTF)
	ar rc $(NAME) $(OBJ) $(PRINTF)
	ranlib $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJ) $(PRINTF)

fclean : clean
	$(RM) $(NAME) $(PRINTF)

re : fclean all

.PHONY : all clean re fclean
