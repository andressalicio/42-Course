# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ande-sou <ande-sou@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:28:32 by ande-sou          #+#    #+#              #
#    Updated: 2021/04/01 19:28:32 by ande-sou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	=   ft_printf.c \
			prints/ft_printc.c \
			prints/ft_printdi.c \
			prints/ft_printu.c \
			prints/ft_printx.c \
			prints/ft_printp.c \
			prints/ft_prints.c \
			prints/ft_printls.c \
			prints/ft_printn.c \
			prints/ft_putspaces.c \
			prints/ft_putzero.c \
			utils/ft_strlen.c \
			utils/ft_strdup.c \
			utils/ft_putchar.c \
			utils/ft_putwchar.c\
			utils/ft_putnbr_base.c\
			utils/ft_putnbr.c\
			flags/ft_flags.c \
			flags/ft_minus.c \
			flags/ft_flagsd.c \
			flags/ft_flagsx.c \
			flags/getnextparam.c \
			

OBJS	= $(SRCS:.c=.o)
GCC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
INCLUD	= -I .

.c.o:
			$(GCC) $(CFLAGS) $(INCLUD) -c $< -o $(<:.c=.o)

all : 		$(NAME)

$(NAME) :	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean :
			rm -f $(OBJS)

bonus :		all

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY: 	all clean fclean re bonus