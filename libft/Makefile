# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 15:12:09 by ande-sou          #+#    #+#              #
#    Updated: 2021/02/18 15:12:09 by ande-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_strdup.c \

SRCS_2	=	ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

OBJS	= ${SRCS:.c=.o}
OBJS_2	= ${SRCS_2:.c=.o}
GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a

.c.o:
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : 		${NAME}

${NAME} :	${OBJS_2} ${OBJS}
			ar rc ${NAME} ${OBJS_2} ${OBJS}
			ranlib ${NAME}

clean :
			rm -f ${OBJS_2} ${OBJS}

fclean :	clean
			rm -f ${NAME}
			rm -f test.out

re :		fclean all

.PHONY: 	all clean fclean re 
