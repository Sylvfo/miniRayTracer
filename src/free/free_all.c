/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:00:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 08:30:52 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void free_coord(t_coord *coord)
{
	if (coord)
		free(coord);
}

void free_color(t_color *color)
{
	if (color)
		free(color);
}

void free_comp(t_comps *comps)
{
	if (!comps)
		return;
	free_coord(comps->r_origin);
	free_coord(comps->r_dir);
	free_coord(comps->p_touch);
	free_coord(comps->v_eye);
	free_coord(comps->v_norm_parral);
	free_coord(comps->v_light_to_point);
	free_coord(comps->v_point_to_light);
	free_coord(comps->reflect_dir);
	free_coord(comps->scalar);
	free_coord(comps->view_dir);
	free_coord(comps->p_space);
	free_coord(comps->origin_zero);
	free_coord(comps->object_normal);
	free_color(comps->obj_color);
	if (comps->obj_inv)
		free(comps->obj_inv);
	if (comps->transp_inv)
		free(comps->transp_inv);
	free(comps);
}

void free_obj(t_obj *obj)
{
	if (!obj)
		return;
	free_coord(obj->p_coord);
	free_coord(obj->v_axe);
	free_coord(obj->v_axe_r);
	free_coord(obj->from);
	free_coord(obj->v_sph_camera);
	free_color(obj->color);
	if (obj->m_transl)
		free(obj->m_transl);
	if (obj->m_rot)
		free(obj->m_rot);
	if (obj->m_scale)
		free(obj->m_scale);
	if (obj->m_transf)
		free(obj->m_transf);
	if (obj->m_inv)
		free(obj->m_inv);
	free(obj);
}

void free_obj_2d(t_obj ***obj)
{
	int i, j;
	if (!obj)
		return;
	for (i = 0; obj[i] != NULL; i++)
	{
		for (j = 0; obj[i][j] != NULL; j++)
			free_obj(obj[i][j]);
		free(obj[i]);
	}
	free(obj);
}

void free_hits(t_hits *hit)
{
	if (!hit)
		return;
	free_coord(hit->r_origin);
	free_coord(hit->r_dir);
}

void free_hits_table(t_pix ***pix)
{
	int i, j, k, l;
	if (!pix)
		return;
	for (i = 0; pix[i] != NULL; i++)
	{
		for (j = 0; pix[i][j] != NULL; j++)
		{
			if (pix[i][j]->hits)
			{
				for (k = 0; pix[i][j]->hits[k] != NULL; k++)
				{
					l = 0;
					while (pix[i][j]->hits[k][l] != NULL)
					{
						free_hits(pix[i][j]->hits[k][l]);
						free(pix[i][j]->hits[k][l]);
						l++;
					}
					free(pix[i][j]->hits[k]);
				}
				free(pix[i][j]->hits);
				pix[i][j]->hits = NULL;
			}
		}
	}
}

void free_image(t_image *ima)
{
	if (!ima)
		return;
	if (ima->mlx_ptr && ima->img)
		mlx_destroy_image(ima->mlx_ptr, ima->img);
	free(ima);
}

void free_mlx(void *mlx_ptr, void *mlx_win)
{
	if (mlx_win && mlx_ptr)
		mlx_destroy_window(mlx_ptr, mlx_win);
	if (mlx_ptr)
		mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

void free_camera(t_camera *cam)
{
	if (!cam)
		return;
	free_coord(cam->p_coord);
	free_coord(cam->v_axe);
	free_coord(cam->p_zero);
	free_coord(cam->v_up);
	free_coord(cam->v_left);
	free_coord(cam->v_true_up);
	if (cam->m_orient)
		free(cam->m_orient);
	if (cam->m_transl)
		free(cam->m_transl);
	if (cam->m_transf)
		free(cam->m_transf);
	if (cam->m_inverse)
		free(cam->m_inverse);
	free(cam);
}

void free_lux(t_light **lux)
{
	int i;

	if (!lux)
		return;
	for (i = 0; lux[i] != NULL; i++)
	{
		free_coord(lux[i]->p_coord);
		free_color(lux[i]->color);
		free(lux[i]);
	}
	free(lux);
}

void free_comps(t_pix ***pix)
{
	int i, j;
	if (!pix)
		return;
	for (i = 0; pix[i] != NULL; i++)
	{
		for (j = 0; pix[i][j] != NULL; j++)
		{
			free_comp(pix[i][j]->comps);
			pix[i][j]->comps = NULL;
		}
	}
}

void free_pixel(t_pix ***pix)
{
	int i, j;
	if (!pix)
		return;
	for (i = 0; pix[i] != NULL; i++)
	{
		for (j = 0; pix[i][j] != NULL; j++)
		{
			free_coord(pix[i][j]->p_viewport);
			free_coord(pix[i][j]->p_viewport_world);
			free_coord(pix[i][j]->r_origin);
			free_coord(pix[i][j]->r_dir);
			free_color(pix[i][j]->color);
			free(pix[i][j]);
			pix[i][j] = NULL;
		}
		free(pix[i]);
	}
	free(pix);
}

void	free_all(t_program_context *context)
{
	if (!context)
		return;

	// rajouté par sylvie
	if (context->pix)
		free_hits_S(context->pix);

	// 1. Image
	if (context->ima)
	{
		free_image(context->ima);
		context->ima = NULL;
	}

	// 2. MLX
	if (context->mlx_ptr || context->mlx_win)
	{
		free_mlx(context->mlx_ptr, context->mlx_win);
		context->mlx_ptr = NULL;
		context->mlx_win = NULL;
	}

	// 3. num_obj
	if (context->num_obj)
	{
		free(context->num_obj);
		context->num_obj = NULL;
	}

	// 4. Caméra, Lumières, Objets, Hits, Comps, Pixels
	if (context->pix && context->pix[0] && context->pix[0][0])
	{
		if (context->pix[0][0]->cam)
		{
			free_camera(context->pix[0][0]->cam);
			context->pix[0][0]->cam = NULL;
		}
		if (context->pix[0][0]->lux)
		{
			free_lux(context->pix[0][0]->lux[1]);
			context->pix[0][0]->lux = NULL;
		}
		if (context->pix[0][0]->obj)
		{
			free_obj_2d(context->pix[0][0]->obj);
			context->pix[0][0]->obj = NULL;
		}
	}

	// 5. Hits (table complète)
//	if (context->pix)
//		free_hits_table(context->pix);
//
	// 6. Comps (table complète)
	if (context->pix)
		free_comps(context->pix);

	// 7. Pixels (table complète)
	if (context->pix)
	{
		free_pixel(context->pix);
		context->pix = NULL;
	}

	// 8. Contexte
	free(context);
}
