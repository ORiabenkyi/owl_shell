/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 20:33:27 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
free token
*/
void	free_token_list(t_token *token_list)
{
	for (int i = 0; i < token_list->count; i++)
	{
		free(token_list->tokens[i]);
	}
	free(token_list->tokens);
	free(token_list);
}
