/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:29:28 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 22:28:05 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int quant, char **args, char **envr)
{
	char	*input;

	init_shell();
	if (quant == 0)
		while (args++ != 0)
			return (0);
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
