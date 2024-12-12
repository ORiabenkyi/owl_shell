/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:29:28 by oriabenk          #+#    #+#             */
/*   Updated: 2024/12/12 17:42:41 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	init_shell(void)
{
	struct sigaction	s_sa;

	s_sa.sa_handler = handle_signal;
	sigemptyset(&s_sa.sa_mask);
	s_sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &s_sa, NULL);
	sigaction(SIGQUIT, &s_sa, NULL);
	load_history_from_file(HISTORY_FILE);
	return (0);
}
