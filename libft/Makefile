# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ameta <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 15:50:28 by ameta             #+#    #+#              #
#    Updated: 2020/11/23 15:50:39 by ameta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
      ft_memcmp.c \
      ft_strjoin.c \
      ft_toupper.c \
      ft_bzero.c \
      ft_memcpy.c \
      ft_strlcat.c \
      ft_calloc.c \
      ft_memmove.c \
      ft_strlcpy.c \
      ft_isalnum.c \
      ft_memset.c \
      ft_strlen.c \
      ft_isalpha.c \
      ft_putchar_fd.c \
      ft_strmapi.c \
      ft_isascii.c \
      ft_putendl_fd.c \
      ft_strncmp.c \
      ft_isdigit.c \
      ft_putnbr_fd.c \
      ft_strrchr.c \
      ft_isprint.c \
      ft_putstr_fd.c \
      ft_strtrim.c \
      ft_memccpy.c \
      ft_strchr.c \
      ft_substr.c \
      ft_memchr.c \
      ft_strdup.c \
      ft_tolower.c \
      ft_itoa.c \
      ft_strnstr.c \
      ft_split.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
