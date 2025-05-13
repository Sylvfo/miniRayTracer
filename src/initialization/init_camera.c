/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:09:34 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 18:07:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
/*	camera->p_coord = malloc(sizeof(t_coord));
	camera->v_axe = malloc(sizeof(t_coord));
	if (!camera->p_coord || !camera->v_axe)
	{
		free(camera->p_coord);
		free(camera->v_axe);
		free(camera);
		return (NULL);
	}
	camera->p_coord->x = 0.0f;
	camera->p_coord->y = 0.0f;
	camera->p_coord->z = 0.0f;
	camera->p_coord->t = 1;
	camera->v_axe->x = 0.0f;
	camera->v_axe->y = 0.0f;
	camera->v_axe->z = 1.0f;
	camera->v_axe->t = 0;
	camera->fov = 90.0f;*/
	return (camera);
}
