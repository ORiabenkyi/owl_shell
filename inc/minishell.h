/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:29:45 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 14:15:25 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define HISTORY_FILE ".msh_history"

int		init_shell(void);

void	load_history_from_file(const char *filename);
void	save_history_to_file(const char *filename);

char	**parse_command(char *input);
void	execute_command(char **args);

void	free_args(char *args[]);

int		handle_builtin(char **args);
void	handle_signal(int sig);

int		run_input(char **input, char **envr);