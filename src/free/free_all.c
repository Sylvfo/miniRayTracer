/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:00:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 11:41:11 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <stdio.h> // Pour printf dans la version initiale

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

static void free_matrix(float *matrix)
{
	if (matrix)
	{
		free(matrix);
	}
}

// Fonctions pour libérer t_hits et son contenu
static void free_hits_content(t_hits *hit)
{
	if (hit)
	{
		free_coord(hit->r_dir);
		hit->r_dir = NULL;
		free_coord(hit->r_origin);
		hit->r_origin = NULL;
		// La structure t_hits elle-même est libérée par l'appelant (free_single_hits_array)
	}
}

static void free_single_hits_array(t_hits **hits_for_type, int count)
{
	if (hits_for_type)
	{
		for (int i = 0; i < count; i++)
		{
			if (hits_for_type[i])
			{
				free_hits_content(hits_for_type[i]);
				free(hits_for_type[i]);
				hits_for_type[i] = NULL;
			}
		}
		free(hits_for_type);
	}
}

static void free_all_hits_arrays_for_pixel(t_hits ****ppp_hits, t_num_obj *num_obj)
{
	if (!ppp_hits || !*ppp_hits || !num_obj)
	{
		return;
	}
	t_hits ***hits_array = *ppp_hits;

	// Type 0 (par exemple, AMBIENT, généralement 1 élément)
	// En se basant sur init_hits_alloc.c, num_obj->ambient_count est 1.
	free_single_hits_array(hits_array[0], 1); 
	// Type 1 (SPHERE)
	free_single_hits_array(hits_array[1], num_obj->sphere);
	// Type 2 (PLAN)
	free_single_hits_array(hits_array[2], num_obj->plan);
	// Type 3 (CYLINDER)
	free_single_hits_array(hits_array[3], num_obj->cylinder);
	// hits_array[4] est le terminateur NULL pour le tableau de types.

	free(hits_array); // Libère le tableau de t_hits** (t_hits ***)
	*ppp_hits = NULL;
}

// Fonction pour libérer t_comps et son contenu
static void free_comps(t_comps *comps)
{
	if (comps)
	{
		free_coord(comps->r_dir); comps->r_dir = NULL;
		free_coord(comps->r_origin); comps->r_origin = NULL;
		free_color(comps->obj_color); comps->obj_color = NULL;
		free_coord(comps->p_touch); comps->p_touch = NULL;
		free_coord(comps->v_eye); comps->v_eye = NULL;
		free_coord(comps->v_norm_parral); comps->v_norm_parral = NULL;
		free_coord(comps->v_point_to_light); comps->v_point_to_light = NULL;
		free_coord(comps->reflect_dir); comps->reflect_dir = NULL;
		free_coord(comps->scalar); comps->scalar = NULL;
		free_coord(comps->p_space); comps->p_space = NULL;
		free_matrix(comps->obj_inv); comps->obj_inv = NULL;
		free_matrix(comps->transp_inv); comps->transp_inv = NULL;
		free_coord(comps->origin_zero); comps->origin_zero = NULL;
		free_coord(comps->object_normal); comps->object_normal = NULL;
		// v_sphere_to_point et view_dir ne sont pas dans la struct t_comps de src/inc/minirt_data_struct.h
		// donc ils ne sont pas libérés ici.
		free(comps);
	}
}

// Fonction pour libérer le contenu d'un t_pix* (sans libérer le t_pix* lui-même)
static void free_pix_content(t_pix *pix_ptr, t_num_obj *num_obj)
{
	if (pix_ptr)
	{
		free_coord(pix_ptr->r_dir); pix_ptr->r_dir = NULL;
		free_coord(pix_ptr->r_origin); pix_ptr->r_origin = NULL;
		free_coord(pix_ptr->p_viewport); pix_ptr->p_viewport = NULL;
		free_coord(pix_ptr->p_viewport_world); pix_ptr->p_viewport_world = NULL;
		free_color(pix_ptr->color); pix_ptr->color = NULL;

		if (pix_ptr->hits)
		{
			free_all_hits_arrays_for_pixel(&(pix_ptr->hits), num_obj);
		}

		free_comps(pix_ptr->comps); pix_ptr->comps = NULL;
		
		// pix_ptr->ima, cam, obj, lux sont des pointeurs partagés et ne doivent pas être libérés ici.
	}
}

// Fonction pour libérer le tableau context->pix et son contenu
static void free_pix_array_memory(t_program_context *context)
{
	if (!context || !context->pix || !context->num_obj)
	{
		return;
	}

	// Assumant que context->width et context->height contiennent les dimensions
	// WND_WIDTH et WND_HEIGHT sont des macros globales, context->width/height sont initialisés avec celles-ci.
	for (int x = 0; x < context->width; x++)
	{
		if (context->pix[x])
		{
			for (int y = 0; y < context->height; y++)
			{
				if (context->pix[x][y])
				{
					free_pix_content(context->pix[x][y], context->num_obj);
					free(context->pix[x][y]);
					context->pix[x][y] = NULL;
				}
			}
			free(context->pix[x]);
			context->pix[x] = NULL;
		}
	}
	free(context->pix);
	context->pix = NULL;
}

// Définition de free_pix utilisée par init_data.c pour le nettoyage en cas d'erreur
void free_pix(t_pix ***pix_matrix, int allocated_rows, int num_cols, t_num_obj *num_obj)
{
	if (!pix_matrix)
		return;
	for (int i = 0; i < allocated_rows; i++)
	{
		if (pix_matrix[i])
		{
			for (int j = 0; j < num_cols; j++)
			{
				if (pix_matrix[i][j])
				{
					// free_pix_content est déjà défini statiquement dans ce fichier
					free_pix_content(pix_matrix[i][j], num_obj);
					free(pix_matrix[i][j]);
					pix_matrix[i][j] = NULL;
				}
			}
			free(pix_matrix[i]);
			pix_matrix[i] = NULL;
		}
	}
	free(pix_matrix);
}

void	free_all(t_program_context *context)
{
	if (!context)
		return;

	printf("Appel de free_all. Étape 1: Libération de context->pix.\n");
	// 1. Libérer context->pix et son contenu
	free_pix_array_memory(context);

	// Étapes suivantes (à implémenter) :
	// 2. Libérer context->obj et son contenu (si ce n'est pas déjà fait via pix ou si partagé différemment)
	//    (Note: obj est partagé par tous les pix, donc il faut une libération unique)
	//    free_obj_array(context->obj, context->num_obj);

	// 3. Libérer context->light et son contenu (similaire à obj)
	//    free_light_array(context->light, context->num_obj);

	// 4. Libérer context->camera et son contenu
	//    free_camera_content(context->camera);
	//    free(context->camera); context->camera = NULL;

	// 5. Libérer context->scene_components et son contenu
	//    free_scene_components(context->scene_components);
	//    free(context->scene_components); context->scene_components = NULL;
	
	// 6. Libérer context->num_obj
	//    free(context->num_obj); context->num_obj = NULL;

	// 7. Libérer les ressources MinilibX
	//    Il faut s'assurer que context->ima, context->mlx_ptr, context->mlx_win sont valides.
	//    L'ordre est important : image, puis fenêtre, puis display.
	//    if (context->ima && context->mlx_ptr)
	//    {
	//        if (context->ima->img)
	//            mlx_destroy_image(context->mlx_ptr, context->ima->img);
       // Ne pas free(context->ima) ici si c'est un pointeur vers pix[0][0]->ima
       // et que t_image a été alloué par init_ima.
       // La structure t_image elle-même (context->pix[0][0]->ima) doit être libérée.
       // Cela devrait être fait après avoir libéré context->pix pour éviter d'accéder à une zone libérée.
       // Ou, si context->ima est le seul propriétaire, le libérer ici.
       // Pour l'instant, on suppose que la structure t_image est libérée séparément si nécessaire.
	//    }
	//    if (context->mlx_win && context->mlx_ptr)
	//        mlx_destroy_window(context->mlx_ptr, context->mlx_win);
	//    if (context->mlx_ptr)
	//        mlx_destroy_display(context->mlx_ptr);
	//
	    // Libérer la structure t_image pointée par context->ima (qui est context->pix[0][0]->ima)
	    // Cette structure a été allouée par init_ima().
	    // Puisque context->pix est maintenant libéré, context->pix[0][0] n'est plus accessible.
	    // Il faut libérer context->ima (la structure t_image) avant de libérer context->mlx_ptr.
	    // Mais après mlx_destroy_image et mlx_destroy_window.
	    // free(context->ima); // Si context->ima est une copie ou le propriétaire.
	    // Si context->ima pointe vers pix[0][0]->ima, et que pix[0][0]->ima est alloué par init_ima,
	    // alors free(context->pix[0][0]->ima) aurait dû être fait avant free(context->pix[0][0]).
	    // C'est un point délicat. Pour l'instant, je vais supposer que la structure t_image
	    // est gérée par la libération de MinilibX ou doit être libérée explicitement.
	    // Le plus simple est de libérer la structure t_image *avant* de détruire le display,
	    // après avoir détruit l'image et la fenêtre qu'elle contient.
	    // free(context->ima); // après mlx_destroy_image et mlx_destroy_window

	// 8. Libérer la structure context elle-même
	//    free(context);
	//    context = NULL; // L'appelant devrait gérer cela.

	printf("Libération de context->pix terminée (théoriquement).\n");
}
