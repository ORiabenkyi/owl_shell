/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ORiabenkyi <o.riabenkyi@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 22:27:04 by ORiabenkyi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
обробка сигналів
*/
t_token	*tokenize_input(const char *input)
{
	t_token *token_list;
	const char *ptr;
	char buffer[1024];
	int buf_index;

	token_list = NULL;
	init_token(token_list);
	ptr = input;
	buf_index = 0;
    while (*ptr)
	{
		if (isspace(*ptr))
		{
			ptr++;
			continue;
		}
		else if (*ptr == '"' || *ptr == '\'')
		{
			special_token(ptr, token_list);
            continue;
        }
		else if (strchr("|><&;", *ptr))
		{
            if (buf_index > 0)
			{ // Додаємо попередній токен
                buffer[buf_index] = '\0';
                add_token(token_list, buffer);
                buf_index = 0;
            }

            // Розпізнаємо оператори з кількох символів (&&, ||)
            if ((*ptr == '&' || *ptr == '|') && *(ptr + 1) == *ptr) {
                buffer[buf_index++] = *ptr++;
            }
            buffer[buf_index++] = *ptr++;
            buffer[buf_index] = '\0';
            add_token(token_list, buffer);
            buf_index = 0;
            continue;
		}
        else if (*ptr == '\\' && *(ptr + 1))
		{
            buffer[buf_index++] = *(++ptr);
        } else
		{
            buffer[buf_index++] = *ptr;
        }
        ptr++;
    }

    // Додаємо останній токен, якщо є
    if (buf_index > 0)
	{
        buffer[buf_index] = '\0';
        add_token(token_list, buffer);
    }

    // Завершальний NULL-токен
	add_token(token_list, NULL);
	return (token_list);
}