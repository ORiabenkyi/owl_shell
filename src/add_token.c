/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 20:27:56 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
add new token
*/
void add_token(t_token *token_list, const char *token)
{
    token_list->tokens = realloc(token_list->tokens, (token_list->count + 1) * sizeof(char *));
    if (!token_list->tokens)
	{
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    token_list->tokens[token_list->count] = strdup(token);
    if (!token_list->tokens[token_list->count])
	{
        perror("strdup");
        exit(EXIT_FAILURE);
    }
    token_list->count++;
}
