/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:29:28 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 14:15:39 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int quant, char **args, char **envr)
{
	char	*input;

	init_shell();
	while (1)
	{
		input = readline("osh> ");
		if (!input)
		{
			printf("\nGood buy!\n");
			break ;
		}
		if (*input)
		{
			add_history(input);
			run_input(input, envr);
		}
	}
	save_history_to_file(HISTORY_FILE);
	return (0);
}
