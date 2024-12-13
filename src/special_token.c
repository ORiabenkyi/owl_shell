/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 20:11:14 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
init token
*/
void	special_token(const char *ptr, t_token	*token)
{
	char quote;
	char buffer[1024];
	int buf_index;

	buf_index = 0;
	quote = *ptr++;
	while (*ptr && *ptr != quote)
	{
		if (*ptr == '\\' && *(ptr + 1))
		{
			buffer[buf_index++] = *(++ptr); // Екранований символ
		}
		else
		{
			buffer[buf_index++] = *ptr;
		}
		ptr++;
	}
	if (*ptr == quote)
	{
		ptr++; // Закриваємо лапки
	}
	buffer[buf_index] = '\0';
	add_token(token, buffer);
	buf_index = 0;
}
