/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 18:04:57 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
обробка сигналів
*/
int	handle_builtin(char **args)
{
	int	i;

	i = 0;
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
			fprintf(stderr, "Очікується аргумент для cd\n");
		else if (chdir(args[1]) != 0)
			perror("cd");
		return (1);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		printf("\nGood buy!\n");
		save_history_to_file(HISTORY_FILE);
		exit(0);
	}
	else if (strcmp(args[0], "history") == 0)
	{
		i = -1;
		HIST_ENTRY **entries = history_list();
		if (entries)
			while (entries[++i])
				printf("%d: %s\n", i + 1, entries[i]->line);
	}
	return (i);
}
