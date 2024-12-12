/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 13:52:11 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
Розбиваємо команду на аргументи
*/
char	**parse_command(char *input)
{
	char	**args;
	char	*token;
	int		i;

	**args = malloc(100 * sizeof(char *));
	i = 0;
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t");
	while (token != NULL)
	{
		args[i++] = strdup(token);
		token = strtok(NULL, " \t");
	}
	args[i] = NULL;
	return (args);
}
