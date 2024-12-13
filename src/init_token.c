/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 19:59:24 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
init token
*/
void	init_token(t_token	*token)
{
	token = malloc(sizeof(t_token));
	if (!token)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token->tokens = NULL;
	token->count = 0;
}
