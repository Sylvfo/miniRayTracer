/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray_calculs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:16 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 10:21:57 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_CALCULS_H
# define MINIRT_RAY_CALCULS_H

# include "minirt_data_struct.h"

bool	init_a_deplacer(t_pix ***pix);
bool	init_matrix_obj(t_obj ***obj);
bool	init_matrix_hits(t_hits ***hits);
bool	init_comps(t_pix ***pix);
bool	init_lights(t_light ***lights);

// a effacer après
struct timeval	time_now(struct timeval start, char *str);
//////////////////////////////////

//00_raytracing_main.c
void	raytracing(t_pix ***pix);

//01_camera_construction.c
void	constructing_camera(t_pix ***pix);
void	view_camera(t_camera *cam);
void	pixel_size(t_pix *pix);

//02_viewport_construction.c
void	init_viewport(t_pix ***pix);
void	init_camera_pix_ray(t_pix *pix, t_camera *cam);
void	init_viewport_x_y(t_pix *pix, int x, int y);

//03_m_transformations.c
void	matrix_transformations(t_pix ***pix);
void	set_transformation(t_obj ***obj);
void	apply_transformation(t_pix ***pix);

//04_intersect_main.c
void	main_intersections(t_pix ***pix);
void	intersect_pix_obj(t_pix *pix);

//05_intersect_sphere_plan.c
void	intersect_sphere(t_pix *pix, int sphere_num);
void	intersect_plan(t_pix *pix, int plan_num);

//06_intersect_cylinder.c
void	intersect_cylinder(t_pix *pix, int cyl_num);
void	cut_cylinder(t_pix *pix, int cyl_num, float t1, float t2);
bool	check_cap(t_pix *pix, float t, int cyl_num);
void	intersect_caps(t_pix *pix, int cyl_num);

//07_closest_obj.c
void	find_closest_obj(t_pix ***pix);
void	closest_obj(t_pix *pix);
void	save_in_comps(t_pix *pix, int a, int b);

//08_prepare_comps.c
void	prepare_computation(t_pix ***pix);
void	normal_at_NA(t_comps *comps);
void	normal_caps(t_comps *comps);

//09_light_shadow_main.c
void	new_light(t_pix ***pix);
float	light_intensity(t_pix *pix);

//10_shadows.c
void	prepare_v_light(t_pix *pix, int lux_num);
bool	intersect_objects_shadow(t_pix *pix, int lux_num);
bool	intersect_sphere_shadow(t_pix *pix, int sphere_num, int lux_num);
bool	intersect_plan_shadow(t_pix *pix, int pln_num, int lux_num);
bool	intersect_cylinder_shadow(t_pix *pix, int pln_num, int lux_num);

//11_light.c
float	compute_pointlight(t_pix *pix, t_light *lux);
float	compute_specular(t_pix *pix, t_light *lux);

#endif