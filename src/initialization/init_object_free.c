/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:34:22 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 11:52:54 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	free_obj_background(t_obj ***obj)
{
	if (obj[0] && obj[0][0])
	{
			free(obj[0][0]->p_coord); obj[0][0]->p_coord = NULL;
			free(obj[0][0]->color); obj[0][0]->color = NULL;
			free(obj[0][0]->m_transl); obj[0][0]->m_transl = NULL;
			free(obj[0][0]->m_rot); obj[0][0]->m_rot = NULL;
			free(obj[0][0]->m_scale); obj[0][0]->m_scale = NULL;
			free(obj[0][0]->m_transf); obj[0][0]->m_transf = NULL;
			free(obj[0][0]->m_inv); obj[0][0]->m_inv = NULL;
			free(obj[0][0]->v_axe_r); obj[0][0]->v_axe_r = NULL;
			free(obj[0][0]->from); obj[0][0]->from = NULL;
			free(obj[0][0]->v_sph_camera); obj[0][0]->v_sph_camera = NULL;
		free(obj[0][0]);
		obj[0][0] = NULL;
	}
	free(obj[0]);
	obj[0] = NULL;
}

static void	free_obj_spheres(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	if (obj[1])
	{
		while (i < count && obj[1][i])
		{
				free(obj[1][i]->p_coord); obj[1][i]->p_coord = NULL;
				free(obj[1][i]->color); obj[1][i]->color = NULL;
				free(obj[1][i]->m_transl); obj[1][i]->m_transl = NULL;
				free(obj[1][i]->m_rot); obj[1][i]->m_rot = NULL;
				free(obj[1][i]->m_scale); obj[1][i]->m_scale = NULL;
				free(obj[1][i]->m_transf); obj[1][i]->m_transf = NULL;
				free(obj[1][i]->m_inv); obj[1][i]->m_inv = NULL;
				free(obj[1][i]->v_axe_r); obj[1][i]->v_axe_r = NULL;
				free(obj[1][i]->from); obj[1][i]->from = NULL;
				free(obj[1][i]->v_sph_camera); obj[1][i]->v_sph_camera = NULL;
			free(obj[1][i]);
				obj[1][i] = NULL;
			i++;
		}
		free(obj[1]);
		obj[1] = NULL;
	}
}

static void	free_obj_plans(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	if (obj[2])
	{
		while (i < count && obj[2][i])
		{
				free(obj[2][i]->p_coord); obj[2][i]->p_coord = NULL;
				free(obj[2][i]->color); obj[2][i]->color = NULL;
				free(obj[2][i]->v_axe); obj[2][i]->v_axe = NULL;
				free(obj[2][i]->m_transl); obj[2][i]->m_transl = NULL;
				free(obj[2][i]->m_rot); obj[2][i]->m_rot = NULL;
				free(obj[2][i]->m_scale); obj[2][i]->m_scale = NULL;
				free(obj[2][i]->m_transf); obj[2][i]->m_transf = NULL;
				free(obj[2][i]->m_inv); obj[2][i]->m_inv = NULL;
				free(obj[2][i]->v_axe_r); obj[2][i]->v_axe_r = NULL;
				free(obj[2][i]->from); obj[2][i]->from = NULL;
				free(obj[2][i]->v_sph_camera); obj[2][i]->v_sph_camera = NULL;
			free(obj[2][i]);
				obj[2][i] = NULL;
			i++;
		}
		free(obj[2]);
		obj[2] = NULL;
	}
}

static void	free_obj_cylinders(t_obj ***obj, int count)
{
	int	i;

	i = 0;
	if (obj[3])
	{
		while (i < count && obj[3][i])
		{
				free(obj[3][i]->p_coord); obj[3][i]->p_coord = NULL;
				free(obj[3][i]->color); obj[3][i]->color = NULL;
				free(obj[3][i]->v_axe); obj[3][i]->v_axe = NULL;
				free(obj[3][i]->m_transl); obj[3][i]->m_transl = NULL;
				free(obj[3][i]->m_rot); obj[3][i]->m_rot = NULL;
				free(obj[3][i]->m_scale); obj[3][i]->m_scale = NULL;
				free(obj[3][i]->m_transf); obj[3][i]->m_transf = NULL;
				free(obj[3][i]->m_inv); obj[3][i]->m_inv = NULL;
				free(obj[3][i]->v_axe_r); obj[3][i]->v_axe_r = NULL;
				free(obj[3][i]->from); obj[3][i]->from = NULL;
				free(obj[3][i]->v_sph_camera); obj[3][i]->v_sph_camera = NULL;
			free(obj[3][i]);
				obj[3][i] = NULL;
			i++;
		}
		free(obj[3]);
		obj[3] = NULL;
	}
}

void	free_object(t_obj ***obj, t_num_obj *num_obj)
{
	if (!obj)
		return ;
	if (!num_obj) // Vérification ajoutée pour num_obj
	{
		free(obj); // Si num_obj est NULL, on ne peut pas libérer les sous-éléments en toute sécurité, donc on libère juste obj.
		return ;
	}
	free_obj_background(obj);
	free_obj_spheres(obj, num_obj->sphere);
	free_obj_plans(obj, num_obj->plan);
	free_obj_cylinders(obj, num_obj->cylinder);
	free(obj);
}
