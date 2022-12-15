# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qujacob <qujacob@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 13:21:17 by qujacob           #+#    #+#              #
#    Updated: 2021/11/05 13:10:19 by qujacob          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

SRCDIR = ./srcs/
OBJDIR = ./objs/
INCDIR = ./includes/

SRCS =	push_swap.c errors_manager.c swap_functions.c push_functions.c \
		rotate_functions.c revrotate_functions.c little_algorithm.c \
		ps_utils.c ps_utils_2.c big_algorithm.c big_move.c big_push.c

SRCS_B =	checker.c swap_functions.c push_functions.c rotate_functions.c \
			revrotate_functions.c ps_utils.c ps_utils_2.c errors_manager.c

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR), $(OBJS))
OBJS_B = $(SRCS_B:.c=.o)
OBJS_B := $(addprefix $(OBJDIR), $(OBJS_B))

CC = gcc
FLAGS = -Wall -Wextra -Werror -g3 -I$(INCDIR)
RM = rm -rf
MKDIR = mkdir -p

all : $(NAME)
	@echo "$(NAME) created !\n"

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(MKDIR) $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "compiling $<..."

$(NAME) : libft $(OBJS)
	@echo "\n=============================================\n"
	@gcc $(FLAGS) $(OBJS) libft.a -o $@
	@echo "Creating $@..."
	@echo "\n=============================================\n"

bonus : $(NAME_B)
	@touch bonus
	@echo "$(NAME_B) (bonus) created !\n"

$(NAME_B) : libft $(OBJS_B)
	@echo "\n=============================================\n"
	@gcc $(FLAGS) $(OBJS_B) libft.a -o $@
	@echo "Creating $@..."
	@echo "\n=============================================\n"

libft :
	@echo "Creating libft..."
	@make -C libft
	@cp libft/includes/*.h $(INCDIR)
	@echo "\n=============================================\n"

clean:
	@$(RM) $(OBJDIR)
	@make fclean -C libft
	@rm -f bonus
	@echo "deleting objects..."

fclean:	clean
	@echo "\n"
	@$(RM) $(NAME) $(NAME_B)
	@make fclean -C libft
	@echo "deleting $(NAME)..."
	@echo "deleting libft..."
	@echo "\n=============================================\n"

re : fclean all

.PHONY: all clean fclean re libft bonus
