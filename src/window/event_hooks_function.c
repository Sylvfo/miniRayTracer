/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:33:55 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 10:34:19 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	ft_exit(t_program_context *context)
{
	(void) context;
	free_all(context);
	exit(0);
	return (0);
}

int	ft_keys(int keycode, t_program_context *context)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("ESC pressed.\nWindow closed\n");
		(void) context;
		free_all(context);
		exit(0);
		return (0);
	}
	return (0);
}
