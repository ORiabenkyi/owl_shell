/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:29:45 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 20:33:41 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../src/libft/libft.h"

# define HISTORY_FILE ".msh_history"

typedef struct s_token {
    char **tokens;
    int count;
} t_token;

int		init_shell(void);

void	load_history_from_file(const char *filename);
void	save_history_to_file(const char *filename);

char	**parse_command(char *input);
void	execute_command(char **args, char **envr);

void	free_args(char *args[]);

int		handle_builtin(char **args);
void	handle_signal(int sig);

char	*find_path(char *cmd, char **envp);
int		run_input(char *input, char **envr);

/*token blok*/
void    add_token(t_token *token_list, const char *token);
void	init_token(t_token	*token);
void	special_token(const char *ptr, t_token	*token);
t_token	*tokenize_input(const char *input);
void	free_token_list(t_token *token_list);

#endif
