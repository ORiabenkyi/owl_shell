# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:21:02 by oriabenk          #+#    #+#              #
#    Updated: 2024/12/12 20:50:53 by ORiabenkyi       ###   ########.fr        #
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
LDFLAGS		= -lreadline
NAME		=	minishell
COMPILE 	= 	cc
FLAGS 		= 	-Wall -Werror -Wextra

LIBFT		=	libft.a
LIBFTDIR	=	src/libft

CFILES 		= 	src/minishell.c \
				src/run_input.c \
				src/save_history_to_file.c \
				src/parse_command.c \
				src/load_history_from_file.c \
				src/init_shell.c \
				src/handle_signal.c \
				src/handle_builtin.c \
				src/free_args.c \
				src/execute_command.c \
				src/find_path.c \
				src/add_token.c \
				src/init_token.c \
				src/special_token.c \
				src/tokenize_input.c \
				src/free_token_list.c
OFILES 		= 	$(CFILES:.c=.o)

# ----- Rules -----
# make your life more ordered

all: ${LIBFT} ${NAME}

$(LIBFT):
	@make -C ${LIBFTDIR}
	@echo "$(GREEN)libefty creation successful$(WHITE)\n"

$(NAME):
	$(COMPILE) $(FLAGS) $(CFILES) $(LIBFTDIR)/$(LIBFT) $(LDFLAGS) -o $(NAME)

clean:
	@make clean -C $(LIBFTDIR)
	@echo "$(PURPLE)Objects were removed - clean.$(WHITE)\n"

fclean:
	@make fclean -C $(LIBFTDIR)
	@echo "$(ORANGE)Names were removed - fclean.$(WHITE)\n"
	@@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re re_bonus bonus party