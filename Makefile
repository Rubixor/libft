# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdenoyel <mdenoyel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:43:30 by mdenoyel          #+#    #+#              #
#    Updated: 2018/03/09 14:47:52 by mdenoyel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

INC =			-I ./includes

CC =			clang

RM =			rm -rf

CFLAGS = 		-Wall -Wextra -Werror -Weverything -pipe

OBJ =			ft_abs.o \
				ft_atod.o \
				ft_atoi.o \
				ft_atol.o \
				ft_atonum.o \
				ft_i128toa.o \
				ft_isalnum.o \
				ft_isalpha.o \
				ft_isascii.o \
				ft_isdigit.o \
				ft_isprint.o \
				ft_isspace.o \
				ft_itoa.o \
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
				ft_swap.o \
				ft_tolower.o \
				ft_toupper.o \
				ft_wcslen.o \
				get_next_line.o

DIR_MEMORY =	memory
MEMORY =		ft_memalloc.o \
				ft_memccpy.o \
				ft_memchr.o \
				ft_memcmp.o \
				ft_memcpy.o \
				ft_memdel.o \
				ft_memmove.o \
				ft_memset.o \
				ft_bzero.o

DIR_STRING =	string
STRING =		ft_strcat.o \
				ft_strchr.o \
				ft_strcleanc.o \
				ft_strclr.o \
				ft_strcmp.o \
				ft_strcpy.o \
				ft_strdel.o \
				ft_strdup.o \
				ft_strdup_len.o \
				ft_strequ.o \
				ft_strisdigit.o \
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
				ft_strtrim.o

DIR_LIST =		list
LIST =			ft_lst_pushback.o \
				ft_lstadd.o \
				ft_lstdel.o \
				ft_lstdelone.o \
				ft_lstinsert.o \
				ft_lstiter.o \
				ft_lstmap.o \
				ft_lstnew.o \
				ft_lstpushsort.o

DIR_SCANF =		scanf
SCANF =			ft_sscanf.o \
				convs/sf_run_char.o \
				convs/sf_run_double.o \
				convs/sf_run_hex.o \
				convs/sf_run_int.o \
				convs/sf_run_str.o \
				convs/sf_run_unsigned.o \
				sf_set_flags.o \
				sf_set_maxlen.o

#DIR_PRINTF =	printf
#PRINTF =		ft_printf.o \
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
				pf_wchart.o \
				pf_wintt.o

BUILD_DIR =		./build_dir

ALL_DIRS =		$(BUILD_DIR) \
				$(BUILD_DIR)/$(DIR_MEMORY) \
				$(BUILD_DIR)/$(DIR_STRING) \
				$(BUILD_DIR)/$(DIR_LIST) \
				$(BUILD_DIR)/$(DIR_SCANF) \
				$(BUILD_DIR)/$(DIR_SCANF)/convs \
#				$(BUILD_DIR)/$(DIR_PRINTF)

ALL_OBJS=$(OBJ:%.o=$(BUILD_DIR)/%.o) \
		$(MEMORY:%.o=$(BUILD_DIR)/$(DIR_MEMORY)/%.o) \
		$(STRING:%.o=$(BUILD_DIR)/$(DIR_STRING)/%.o) \
		$(LIST:%.o=$(BUILD_DIR)/$(DIR_LIST)/%.o) \
		$(SCANF:%.o=$(BUILD_DIR)/$(DIR_SCANF)/%.o) \
#		$(PRINTF:%.o=$(BUILD_DIR)/$(DIR_PRINTF)/%.o)

ALL_SRCS=$(OBJ:%.o=%.c) \
		$(MEMORY:%.o=$(DIR_MEMORY)/%.c) \
		$(STRING:%.o=$(DIR_STRING)/%.c) \
		$(LIST:%.o=$(DIR_LIST)/%.c) \
		$(SCANF:%.o=$(DIR_SCANF)/%.c) \
#		$(PRINTF:%.o=$(DIR_PRINTF)/%.c)

all : $(NAME)

help :
	@echo $(ALL_OBJS)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -I ./includes/ -c $< -o $@


$(NAME) : $(ALL_DIRS) $(ALL_OBJS)
	ar rc $(NAME) $(ALL_OBJS)
	ranlib $(NAME)

$(ALL_DIRS) :
	mkdir -p $@

all_dirs : $(ALL_DIRS)

clean :
	$(RM) $(BUILD_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean re fclean
