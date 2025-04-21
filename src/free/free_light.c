/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:34:26 by cmegret           #+#    #+#             */
/*   Updated: 2025/04/19 16:34:32 by cmegret          ###   ########.fr       */
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
	free(light->p_coord);
	free(light->color);
	free(light->m_identity);
	free(light->m_tranf);
	free(light->m_transl);
	free(light->p_world);
	free(light);
}
