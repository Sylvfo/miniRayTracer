/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:25:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 16:29:07 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_light(t_light *light)
{
	if (!light)
		return ;
	free_coord(light->p_coord);
	free_color(light->color);
	free(light);
}

void	free_light_array(t_light **array, int count)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < count)
	{
		free_light(array[i]);
		i++;
	}
	free(array);
}

void	free_camera(t_camera *camera)
{
	if (!camera)
		return ;
	if (camera->v_left)
		free(camera->v_left);
	if (camera->v_up)
		free(camera->v_up);
	if (camera->v_true_up)
		free(camera->v_true_up);
	if (camera->m_orient)
		free(camera->m_orient);
	if (camera->m_transl)
		free(camera->m_transl);
	if (camera->m_transf)
		free(camera->m_transf);
	if (camera->m_inverse)
		free(camera->m_inverse);
	if (camera->p_zero)
		free(camera->p_zero);
	if (camera->p_coord)
		free(camera->p_coord);
	if (camera->v_axe)
		free(camera->v_axe);
	free(camera);
}
