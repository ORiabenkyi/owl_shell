/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 22:31:16 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
обробка сигналів
*/
int	run_input(char *input, char **envr)
{
	 char	**args;
	t_token	*com_token;

	com_token = tokenize_input(input);
	/*old stily*/

	// for (int i = 0; i < com_token->count - 1; i++)
	// { // -1, щоб уникнути NULL-токена
	// 	printf("Токен[%d]: %s\n", i, com_token->tokens[i]);
	// }
    free_token_list(com_token);

	args = envr;
	args++;
	// args = parse_command(input);
	// if (args[0])
	// {
	// 	if (!handle_builtin(args))
	// 	{
	// 		execute_command(args, envr);
	// 	}
	// }
	// free_args(args);
	free(input);
	return (0);
}
