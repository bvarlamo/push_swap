# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarlamo <bvarlamo@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 10:17:55 by bvarlamo          #+#    #+#              #
#    Updated: 2022/01/25 10:07:12 by bvarlamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH=	push_swap.c sorting.c helpers.c operations.c operations2.c\

NAME	=	push_swap

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

lib=./Libft

INCLUDES	=		libft/libft.a

PUSHO=	$(PUSH:.c=.o)

all :		$(NAME)

${NAME}:	${PUSHO}
		make -C ${lib}
		${CC} ${CFLAGS} ${PUSHO} $(INCLUDES) -o ${NAME}

clean :
	make clean -C ${lib}
	$(RM) ${PUSHO}

fclean :	clean
	$(RM) $(NAME)
	$(RM) $(PUSHO)
	make clean -C ${lib}
	make fclean -C ${lib}

re :		fclean all