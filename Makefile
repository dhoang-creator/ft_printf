# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dhoang <dhoang@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/01 07:46:05 by dhoang        #+#    #+#                  #
#    Updated: 2020/05/07 13:45:37 by dhoang        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	conv_char.c conv_digit.c conv_string.c conv_hex.c \
		ft_itoa.c ft_itoa_base.c printf_utils.c ft_printf.c \
		parser.c printer.c setter.c

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Werror -Wextra

HEADER = .

all: $(NAME)


$(NAME): $(OBJ)
		ar rc $@ $^
		ranlib $(NAME)
%.o: %.c $(HEADER)
		gcc $(CCFLAGS) -o $@ -c $< -I$(HEADER)
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re:
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all clean fclean re
