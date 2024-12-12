/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 14:13:54 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
обробка сигналів
*/
int	run_input(char **input, char **envr)
{
	char	**args;

	args = parse_command(input);
	if (args[0])
	{
		if (!handle_builtin(args))
		{
			execute_command(args);
		}
	}
	free_args(args);
	free(input);
}
