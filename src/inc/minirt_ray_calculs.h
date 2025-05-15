/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray_calculs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:16 by syl               #+#    #+#             */
/*   Updated: 2025/05/11 20:31:15 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_CALCULS_H
# define MINIRT_RAY_CALCULS_H

# include "minirt_data_struct.h"

void	raytracing(t_pix ***pix);

void	view_camera(t_camera *cam);
void	pixel_size(t_pix *pix);
void	constructing_camera(t_pix ***pix);

void	init_camera_pix_ray(t_pix *pix);
void	init_viewport_x_y(t_pix *pix, int x, int y);
void	init_viewport(t_pix ***pix);

void	apply_transformation_obj(t_pix *pix);
void	apply_transformation(t_pix ***pix);
void	set_transformation_obj(t_obj *obj);
void	set_transformation(t_obj ***obj);
void	matrix_transformations(t_pix ***pix);

void	intersect_pix_obj(t_pix *pix);
void	main_intersections(t_pix ***pix);

void	intersect_plan(t_pix *pix, int plan_num);
void	intersect_sphere(t_pix *pix, int sph_num);

void	cut_cylinder(t_pix *pix, int cyl_n, float t1, float t2);
bool	check_cap(t_pix *pix, float t, int cyl_n);
void	intersect_caps(t_pix *pix, int cyl_n);
void	intersect_cylinder(t_pix *pix, int cyl_n);

void	save_in_comps(t_pix *pix, int a, int b);
void	closest_obj(t_pix *pix);
void	find_closest_obj(t_pix ***pix);
void	prepare_comps_plan(t_pix *pix);

void	prepare_computation_pix(t_pix *pix);
void	normal_caps(t_comps *comps);
void	normal_at_na(t_comps *comps);
void	prepare_computation(t_pix ***pix);

float	light_intensity(t_pix *pix);
void	new_light(t_pix ***pix);

void	prepare_v_light(t_pix *pix, int lux_num);
bool	intersect_objects_shadow(t_pix *pix, int lux_num);
bool	intersect_sphere_shadow(t_pix *pix, int sphere_num, int lux_num);
bool	intersect_plan_shadow(t_pix *pix, int pln_num, int lux_num);
bool	intersect_cylinder_shadow(t_pix *pix, int cyl_num, int lux_num);

float	compute_pointlight(t_pix *pix, t_light *lux);
float	compute_specular(t_pix *pix, t_light *lux);

#endif