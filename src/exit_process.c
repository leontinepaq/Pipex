/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:23:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/02/26 15:25:33 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void exit_process(t_vars *vars, char *error_message, int exit_code)
{
	perror(error_message);
	free_vars(vars);
	exit(exit_code);
}