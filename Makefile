# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 18:26:26 by dde-maga          #+#    #+#              #
#    Updated: 2024/03/19 16:15:23 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_UTILS = errors.c finds.c indexation.c quick_friend.c \
			small_sorts.c stack_a.c stack_b.c stacks.c turk_sort.c \
			turk_a.c turk_b.c
SRC_COMMANDS = push.c reverse_rotate.c rotate.c swap.c
SRC_LIB = ft_atol.c ft_calloc.c ft_putstr_fd.c ft_split.c \
			ft_substr.c ft_strlen.c ft_strdup.c ft_memcpy.c \
			ft_memset.c

SRC =	$(addprefix ./srcs/commands/, $(SRC_COMMANDS)) \
		$(addprefix ./srcs/utils/, $(SRC_UTILS)) \
		$(addprefix ./srcs/lib/, $(SRC_LIB))


SRCOBJ = obj/
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
OBJ = $(addprefix $(SRCOBJ), $(SRC:./srcs/%.c=%.o))


all: $(NAME)

$(NAME): $(OBJ)
	@${CC} ${CFLAGS} push_swap.c ${OBJ} -o $(NAME)

$(SRCOBJ)%.o: srcs/%.c
	@mkdir -p $(SRCOBJ)
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf $(SRCOBJ)


fclean: clean
	@rm -rf $(NAME)

re: fclean all

