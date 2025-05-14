/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:00:00 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 12:02:39 by cmegret          ###   ########.fr       */
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

	// Pointeur pour stocker la référence aux objets partagés
	t_obj		***obj_to_free = NULL;
	// t_light		***light_to_free = NULL; // Pour les étapes futures
	// t_camera	*camera_to_free = NULL; // Pour les étapes futures

	// Capturer les pointeurs vers les données partagées avant de libérer la matrice pix
	// Il est crucial que context->pix, context->pix[0] et context->pix[0][0] soient valides ici.
	if (context->pix && context->pix[0] && context->pix[0][0])
	{
		obj_to_free = context->pix[0][0]->obj;
		// light_to_free = context->pix[0][0]->lux; // Sera utilisé plus tard
		// camera_to_free = context->pix[0][0]->cam; // Sera utilisé plus tard
	}

	printf("Appel de free_all.\n");
	
	// 1. Libérer context->pix et son contenu (les structures t_pix elles-mêmes et leurs membres non partagés)
	printf("Étape 1: Libération de context->pix.\n");
	free_pix_array_memory(context); // context->pix devient NULL ici

	// 2. Libérer context->obj (la structure de données des objets, qui était partagée)
	printf("Étape 2: Libération de context->obj.\n");
	if (obj_to_free && context->num_obj)
	{
		free_object(obj_to_free, context->num_obj); // free_object est défini dans init_object_free.c
		obj_to_free = NULL; // Bonne pratique
	}
	else
	{
		printf("  -> obj_to_free ou context->num_obj est NULL, rien à libérer pour les objets.\n");
	}

	// Étapes suivantes (à implémenter) :
	// 3. Libérer context->light (shared)
	//    printf("Étape 3: Libération de context->light.\n");
	//    if (light_to_free && context->num_obj)
	//    {
	//        free_light_all(light_to_free, context->num_obj); // Assumer/créer free_light_all
	//        light_to_free = NULL;
	//    }

	// 4. Libérer context->camera (shared)
	//    printf("Étape 4: Libération de context->camera.\n");
	//    if (camera_to_free)
	//    {
	//        free_camera_memory(camera_to_free); // Assumer/créer free_camera_memory
	//        camera_to_free = NULL;
	//    }

	// 5. Libérer context->scene_components (si applicable)
	//    free_scene_components(context->scene_components);

	// 7. Libérer les ressources MinilibX (après avoir libéré les structures qui les utilisent)
	//    printf("Étape 7: Libération des ressources MinilibX et de context->ima.\n");
	//    if (context->ima) // context->ima pointe vers la structure t_image allouée
	//    {
	//        if (context->ima->mlx_ptr && context->ima->img)
	//            mlx_destroy_image(context->ima->mlx_ptr, context->ima->img);
	//        // La structure t_image elle-même (context->ima) sera libérée après les appels mlx_destroy_*
	//    }
	//    if (context->mlx_win && context->mlx_ptr)
	//        mlx_destroy_window(context->mlx_ptr, context->mlx_win);
	//    if (context->mlx_ptr)
	//        mlx_destroy_display(context->mlx_ptr); // Libère aussi mlx_ptr
	//
	//    if (context->ima) // Libérer la structure t_image
	//    {
	//        free(context->ima);
	//        context->ima = NULL;
	//    }
	//    context->mlx_ptr = NULL; // mlx_destroy_display s'en charge
	//    context->mlx_win = NULL; // mlx_destroy_window s'en charge

	// 6. Libérer context->num_obj
	printf("Étape 6: Libération de context->num_obj.\n");
	if (context->num_obj)
	{
		free(context->num_obj);
		context->num_obj = NULL;
	}

	// 8. Libérer la structure context elle-même
	printf("Étape 8: Libération de la structure context.\n");
	free(context);
	// context = NULL; // L'appelant doit gérer la mise à NULL de son pointeur

	printf("Libération des ressources terminée (étapes 1, 2, 6, 8 partiellement implémentées).\n");
}
