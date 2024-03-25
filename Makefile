# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 18:26:26 by dde-maga          #+#    #+#              #
#    Updated: 2024/03/25 12:59:29 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER_NAME = checker

SRC_UTILS = errors.c finds.c indexation.c quick_friend.c \
			small_sorts.c stack_a.c stack_b.c stacks.c turk_sort.c \
			turk_a.c turk_b.c
SRC_COMMANDS = push.c reverse_rotate.c rotate.c swap.c rotate_turk.c
SRC_LIB = 	ft_atol.c ft_calloc.c ft_putstr_fd.c ft_split.c \
			ft_substr.c ft_strlen.c ft_strdup.c ft_memcpy.c \
			ft_memset.c ft_lstadd_back.c ft_lstclear.c ft_lstnew.c \
			ft_strcmp.c
SRC_GNL = gnl.c gnl_utils.c
SRC_CHECKER = aux_func.c

SRC =	$(addprefix ./srcs/commands/, $(SRC_COMMANDS)) \
		$(addprefix ./srcs/utils/, $(SRC_UTILS)) \
		$(addprefix ./srcs/lib/, $(SRC_LIB)) \
		$(addprefix ./srcs/lib/gnl/, $(SRC_GNL)) \

BONUS = $(addprefix ./bonus/, $(SRC_CHECKER))


SRCOBJ = obj/
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
OBJ = $(addprefix $(SRCOBJ), $(SRC:./srcs/%.c=%.o))
BONUS_OBJ = $(addprefix $(SRCOBJ), $(BONUS:./bonus/%.c=%.o))

all: $(NAME)

bonus: $(CHECKER_NAME)

$(SRCOBJ)%.o: bonus/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(SRCOBJ)%.o: srcs/%.c
	@mkdir -p $(SRCOBJ)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) push_swap.c $(OBJ) -o $(NAME)
	@echo Done sort!

$(CHECKER_NAME): $(OBJ) $(BONUS_OBJ)
	@@$(CC) $(CFLAGS) ./bonus/checker.c $(OBJ) $(BONUS_OBJ) -o $(CHECKER_NAME)
	@echo Done Checker!

clean:
	@rm -rf $(SRCOBJ)
	@rm -rf $(BONUS_OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(CHECKER_NAME)

re: fclean all



