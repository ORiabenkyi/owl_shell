/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 18:01:25 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
Run extended command
*/
void	execute_command(char **args, char **envr)
{
	pid_t	pid;
	int		i;
	char	*path;

	i = -1;
	path = find_path(args[0], envr);
	if (!path)
	{
		perror("find path");
		return ;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, &args[0], envr) == -1)
			perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		perror("fork");
}
