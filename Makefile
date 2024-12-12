# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:21:02 by oriabenk          #+#    #+#              #
#    Updated: 2024/12/12 14:22:49 by oriabenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Colors -----
# make your life more colored

CYAN = \033[38;5;6m
GREEN = \033[38;5;10m
YELLOW = \033[38;5;3m
BLUE = \033[38;5;4m
PURPLE = \033[38;5;99m
ORANGE = \033[38;5;172m
WHITE = \033[0m
BRIGHTBLUE = \033[38;5;12m

# ----- Variables -----
NAME		=	minishell
COMPILE 	= 	cc
FLAGS 		= 	-Wall -Werror -Wextra

LIBFT		=	libft.a
LIBFTDIR	=	src/libft

CFILES 		= 	src/*.c
OFILES 		= 	$(CFILES:.c=.o)

# ----- Rules -----
# make your life more ordered

all: ${LIBFT} ${NAME}

$(LIBFT):
	@make -C ${LIBFTDIR}
	@echo "$(GREEN)libefty creation successful$(WHITE)\n"

$(NAME):
	$(COMPILE) $(FLAGS) $(CFILES) $(LIBFTDIR)/$(LIBFT) -o $(NAME)

clean:
	@make clean -C $(LIBFTDIR)
	@echo "$(PURPLE)Objects were removed - clean.$(WHITE)\n"

fclean:
	@make fclean -C $(LIBFTDIR)
	@echo "$(ORANGE)Names were removed - fclean.$(WHITE)\n"
	@@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re re_bonus bonus party