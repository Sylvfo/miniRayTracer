/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:00:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 20:28:18 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Fonctions d'assistance pour libérer des types de données spécifiques
static void free_coord(t_coord *coord)
{
	if (coord)
	{
		free(coord);
	}
}

static void free_color(t_color *color)
{
	if (color)
	{
		free(color);
	}
}

// Fonction auxiliaire pour libérer une caméra
static void free_camera(t_camera *cam)
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

// Fonction auxiliaire pour libérer les composants (comps)
static void free_comps(t_comps *comps)
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
	
	if (comps->obj_color)
		free_color(comps->obj_color);
	if (comps->obj_inv)
		free(comps->obj_inv);
	if (comps->transp_inv)
		free(comps->transp_inv);
	
	// Note: comps->obj n'est pas libéré ici car il semble être 
	// un pointeur vers un objet géré ailleurs dans le code
		
	free(comps);
}

// Fonction auxiliaire pour libérer un objet
static void free_obj(t_obj *obj)
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

// Fonction auxiliaire pour libérer un hit
static void free_hits(t_hits *hit)
{
	if (!hit)
		return;
	
	//printf("Freeing hit at %p\n", (void*)hit);
	free_coord(hit->r_origin);
	free_coord(hit->r_dir);
	//free(hit);
}

// Fonction auxiliaire pour libérer la table complète des hits
static void	free_hits_table(t_hits ***hits)
{
	int	i;
	int	j;

	if (!hits)
		return ;
	for (i = 0; i < 4; i++)
	{
		if (!hits[i])
			continue ;
		j = 0;
		while (hits[i][j] != NULL)
		{
			if (hits[i][j]->r_dir)
				free(hits[i][j]->r_dir);
			if (hits[i][j]->r_origin)
				free(hits[i][j]->r_origin);
			free(hits[i][j]);
			j++;
		}
		free(hits[i]);
	}
	//free(hits);
}

// Fonction principale de libération de mémoire
void free_all(t_program_context *context)
{
	int i, j, k;
	
	if (!context)
		return;

	// 1. Image et MLX
	if (context->ima)
	{
		if (context->ima->mlx_ptr && context->ima->img)
			mlx_destroy_image(context->ima->mlx_ptr, context->ima->img);
		free(context->ima);
		context->ima = NULL;
	}
	if (context->mlx_win && context->mlx_ptr)
		mlx_destroy_window(context->mlx_ptr, context->mlx_win);
	if (context->mlx_ptr)
		mlx_destroy_display(context->mlx_ptr);
	free(context->mlx_ptr);
	context->mlx_ptr = NULL;
	context->mlx_win = NULL;

	// 2. Tableau de pixels
	if (context->pix)
	{
		// Libérer les ressources partagées (une seule fois)
		if (context->pix[0] && context->pix[0][0])
		{
			// 2.1 Camera (une seule pour tous les pixels)
			free_camera(context->pix[0][0]->cam);
			
			// 2.2 Objets (partagés par tous les pixels)
			if (context->pix[0][0]->obj)
			{
				for (i = 0; context->pix[0][0]->obj[i] != NULL; i++)
				{
					for (j = 0; context->pix[0][0]->obj[i][j] != NULL; j++)
						free_obj(context->pix[0][0]->obj[i][j]);
					free(context->pix[0][0]->obj[i]);
				}
				free(context->pix[0][0]->obj);
			}
			
			// 2.3 Lumières (partagées par tous les pixels)
			if (context->pix[0][0]->lux)
			{
				for (i = 0; context->pix[0][0]->lux[i] != NULL; i++)
				{
					for (j = 0; context->pix[0][0]->lux[i][j] != NULL; j++)
					{
						free_coord(context->pix[0][0]->lux[i][j]->p_coord);
						free_color(context->pix[0][0]->lux[i][j]->color);
						free(context->pix[0][0]->lux[i][j]);
					}
					free(context->pix[0][0]->lux[i]);
				}
				free(context->pix[0][0]->lux);
			}
		}
		
		// 3. Libérer chaque pixel
		for (i = 0; i < context->width; i++)
		{
			if (context->pix[i])
			{
				for (j = 0; j < context->height; j++)
				{
					if (context->pix[i][j])
					{
						// 3.1 Coord et Color par pixel
						free_coord(context->pix[i][j]->p_viewport);
						free_coord(context->pix[i][j]->p_viewport_world);
						free_coord(context->pix[i][j]->r_origin);
						free_coord(context->pix[i][j]->r_dir);
						free_color(context->pix[i][j]->color);
						
						// 3.2 Hits par pixel
						//free_hits_table(context->pix[i][j]->hits);
						
						// 3.2 Hits par pixel
						if (context->pix[i][j]->hits)
						{
							// Se débarrasser de tous les tableaux de hits
							for (k = 0; context->pix[i][j]->hits[k] != NULL; k++)
							{
								int l = 0;
								while (context->pix[i][j]->hits[k][l] != NULL)
								{
									free_hits(context->pix[i][j]->hits[k][l]);
									free(context->pix[i][j]->hits[k][l]);
									l++;
								}
								free(context->pix[i][j]->hits[k]);
							}
							free(context->pix[i][j]->hits);
						}
						free(context->pix[i][j]->hits);
						
						// 3.3 Comps par pixel
						free_comps(context->pix[i][j]->comps);
						
						// Libérer le pixel lui-même
						free(context->pix[i][j]);
					}
				}
				free(context->pix[i]);
			}
		}
		free(context->pix);
	}
	
	// 4. Nombre d'objets
	if (context->num_obj)
		free(context->num_obj);
		
	// 5. Contexte lui-même
	free(context);
}
