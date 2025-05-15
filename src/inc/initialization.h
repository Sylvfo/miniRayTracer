/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:21:36 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 10:33:13 by cmegret          ###   ########.fr       */
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

t_camera	*init_camera(void);

t_light		***init_light(t_num_obj *num_obj);

void		free_light_array(t_light **array, int count);
void		free_light_memory(t_light ***light, int count);
t_light		***init_light(t_num_obj *num_obj);
t_light		***allocate_light_arrays(t_num_obj *num_obj);
t_light		**init_light_array(int count);
bool		init_ambient_light(t_light ***light);
bool		init_one_spotlight(t_light *spot);
bool		init_spotlights(t_light ***light, t_num_obj *num_obj);

void		assign_camera_obj_light_to_pix(t_pix ***pix, t_camera *cam,
				t_obj ***obj, t_light ***lux);

void		initialize_hits_arrays(t_hits ***hits, t_num_obj *num_obj);
bool		allocate_hits_arrays(t_hits ***hits, t_num_obj *num_obj);

t_color		*init_color(void);

bool		init_ima(t_pix ***pix);

// Initialisation avancée de la scène
bool		init_scene_structures(t_pix ***pix);
void		init_pix_camera(t_pix ***pix);
void		init_pix_viewport(t_pix ***pix);
bool		init_obj_matrices(t_obj ***obj);
bool		init_hits_matrices(t_hits ***hits);
void		init_pix_comps(t_pix ***pix);

void		free_object(t_obj ***obj, t_num_obj *num_obj);
void		free_and_null(void **ptr_addr);
void		clear_obj_members(t_obj *obj_ptr);
void		free_obj_array_items(t_obj **obj_array, int count);

t_hits		***init_hits(t_num_obj *num_obj);
void		assign_hits_to_pix(t_pix ***pix, t_hits ***hits,
				t_num_obj *num_obj);
void		init_hits_spheres(t_hits ***hits, t_num_obj *num_obj);
void		init_hits_plans(t_hits ***hits, t_num_obj *num_obj);
void		init_hits_cylinders(t_hits ***hits, t_num_obj *num_obj);
void		init_hits_background(t_hits ***hits);

#endif