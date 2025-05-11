/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:34:26 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 15:27:57 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
** Libère une structure t_light et tous ses champs dynamiquement alloués.
*/
void	free_light(t_light *light)
{
	if (!light)
		return ;
	if (light->p_coord)
		free(light->p_coord);
	if (light->color)
		free(light->color);
	free(light);
}
