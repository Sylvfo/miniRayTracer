/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:21:36 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 14:36:14 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "minirt.h"
# include "minirt_data_struct.h"

t_pix		***init_data(t_num_obj *num_obj);

t_obj		***init_object(t_num_obj *num_obj);
bool		initialize_object_arrays(t_obj ***obj, t_num_obj *num_obj);
bool		init_obj_struct(t_obj **o, bool has_v_axe);
bool		allocate_object_arrays(t_obj ***obj, t_num_obj *num_obj);
void		free_object(t_obj ***obj, t_num_obj *num_obj);

void		free_pix(t_pix ***pix, int rows, int cols, t_num_obj *num_obj);

t_camera	*init_camera(void);

t_light		***init_light(t_num_obj *num_obj);

void		free_light_memory(t_light ***light, int count);
t_light		***init_light(t_num_obj *num_obj);
t_light		***allocate_light_arrays(t_num_obj *num_obj);
t_light		**init_light_array(int count);
bool		init_ambient_light(t_light ***light);
bool		init_one_spotlight(t_light *spot);
bool		init_spotlights(t_light ***light, t_num_obj *num_obj);

void		assign_camera_obj_light_to_pix(t_pix ***pix, t_camera *cam,
				t_obj ***obj, t_light ***lux);

t_hits		***init_hits(t_num_obj *num_obj);
void		assign_hits_to_pix(t_pix ***pix, t_num_obj *num_obj);
void		initialize_hits_arrays(t_hits ***hits, t_num_obj *num_obj);
bool		allocate_hits_arrays(t_hits ***hits, t_num_obj *num_obj);

t_color		*init_color(void);

bool		init_ima(t_program_context *context);

// Initialisation avancée de la scène
bool		init_scene_structures(t_pix ***pix);
void		init_pix_camera(t_pix ***pix);
void		init_pix_viewport(t_pix ***pix);
bool		init_obj_matrices(t_obj ***obj);
bool		init_hits_matrices(t_hits ***hits);
void		init_pix_comps(t_pix ***pix);

/* Fonctions de libération de mémoire */
void		free_all(t_program_context *context);

/* Fonctions de base */
void		free_matrix(float *matrix);
void		free_coord(t_coord *coord);
void		free_color(t_color *color);
void		free_ima(t_program_context *context);

/* Fonctions pour les hits */
void		free_hit_struct(t_hits *hit);
void		free_hits_array(t_hits **hits);
void		free_hits(t_program_context *context);

/* Fonctions pour les composants */
void		free_comps(t_comps *comps);
void		free_obj(t_obj *obj);
void		free_obj_array(t_obj **objs);

/* Fonctions pour les lumières */
void		free_light(t_light *light);
void		free_light_array(t_light **array, int count);
void		free_camera(t_camera *camera);

/* Fonctions pour les pixels */
void		free_pix_viewport(t_pix *pix);
void		free_pix_components(t_pix *pix);
void		free_pix_content(t_pix *pix);
void		free_pix(t_pix ***pix, int rows, int cols, t_num_obj *num_obj);

#endif