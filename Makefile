# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 15:07:50 by mlecuyer          #+#    #+#              #
#    Updated: 2021/01/15 15:51:36 by mlecuyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	ft_init_args.c \
			ft_check_flags.c \
			ft_print_char.c \
			ft_print_str.c \
			ft_print_int.c \
			ft_print_utils_1.c \
			ft_printf_utils_2.c \
			ft_printf.c \
			ft_print_hex.c \
			ft_print_p.c \
			ft_print_unsigned.c \
			ft_print_pourc.c \

OBJS	=	${SRCS:.c=.o}

NAME	=	libftprintf.a

LIBDIR	=	./libft/
LIBFT	=	libft.a

RM		=	rm -f

.c.o:
			${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
				make all -C $(LIBDIR)
				cp $(LIBDIR)/$(LIBFT) $(NAME)
				ar -rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}
			make clean -C $(LIBDIR)

fclean:		clean
				${RM} ${NAME}
				make fclean -C $(LIBDIR)

re:			fclean all

.PHONY:		all clean fclean re
