/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:30:35 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 13:32:54 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
обробка сигналів
*/
void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\nPushed Ctrl-C. Execution stoped.\n");
		printf("osh> ");
		fflush(stdout);
	}
	else if (sig == SIGQUIT)
	{
		return ;
	}
}
