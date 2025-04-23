/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray_calculs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:16 by syl               #+#    #+#             */
/*   Updated: 2025/04/23 19:17:02 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_CALCULS_H
# define MINIRT_RAY_CALCULS_H

# include "minirt_data_struct.h"

bool init_a_deplacer(t_pix ***pix);
bool 	init_matrix_obj(t_obj ***obj);
bool 	init_matrix_hits(t_hits ***hits);
bool init_comps(t_pix ***pix);
bool init_lights(t_light ***lights);

//raytracing_main.c
void raytracing(t_pix ***pix);

// a effacer après
struct timeval time_now(struct timeval start, char *str);

//camera_construction.c 
void constructing_camera(t_pix ***pix);
void pixel_size(t_pix *pix);
//float *view_camera(t_coord *p_coordcam, t_coord *v_dircam);
void view_camera(t_camera *cam);

//viewport_construction.c
void init_viewport(t_pix ***pix);
void init_camera_pix_ray(t_pix *pix, t_camera *cam);
void init_viewport_x_y(t_pix *pix, int x, int y);

//raycasting.c
t_coord *position(t_coord *r_origin, t_coord *r_dir, float t);
void position_NA(t_coord *result, t_coord *r_origin, t_coord *r_dir, float t);

//m_transformations.c
void matrix_transformations(t_pix ***pix);
void apply_transformation(t_pix ***pix);

//intersect_sphere.c
void intersect_sphere(t_pix *pix, int sphere_num);
void main_intersections(t_pix ***pix);

//ray_test.c 
void ray_testing();
void sphere_testing();
void test_ray(void);
void test_sphere(t_pix ***pix);
void test_normal_at(void);

//closest_obj.c
void find_closest_obj(t_pix ***pix);
void closest_obj(t_pix *pix);
void prepare_computation(t_pix ***pix);
void save_in_comps(t_pix *pix, int a, int b);

//intersect_sphere.c
t_coord	*normal_at(t_obj *object, t_coord *point_on_object);
//void	normal_at_NA(t_pix *pix);
void	normal_at_NA(t_comps *comps);

void set_transformation(t_obj ***obj);
void set_transformation_light(t_light ***lux);
void transform_lights(t_light ***lux);
void transform_obj(t_pix *pix, float *m_transf, int obj_type, int obj_num);
//void transform_plan(t_pix *pix, float *m_transf, int plan_num);
//void transform(t_pix *pix, float *m_transf, int sphere_num);
void apply_transf_sph_center(t_pix *pix);
void update_world_position(t_obj *obj);
//transform_rotation.c
void rotation_from_vector(float *m_rot, t_coord *to);
void rotation_from_vector_NA(float *m_rot, t_coord *to, t_obj *obj);

void matrix_rotation_rodrigues(t_coord *axis, float angle, float *m_rot);

//intersect_plan.c
void intersect_plan(t_pix *pix, int plan_num);

//intersect_cylinder.c
void intersect_cylinder(t_pix *pix, int cyl_num);
bool	check_cap(t_pix *pix, float t, int cyl_num);
void intersect_caps(t_pix *pix, int cyl_num);

//new_light
void	new_light(t_pix ***pix);
void ComputeLighting(t_pix *pix);
float 	compute_pointlight(t_pix *pix, t_light *lux);
float light_intensity(t_pix *pix);//rajouter plusieurs lampes
float 	compute_ambient(t_pix *pix);
float	compute_specular(t_pix *pix, t_light *lux);


//shadows_.c
bool intersect_sphere_shadow(t_pix *pix, int sphere_num, int lux_num);
bool intersect_objects_shadow(t_pix *pix, int lux_num);

/*
//light.c
void main_light(t_pix ***pix);
float light_intensity(t_coord *P, t_coord *N, t_pix *pix);
float 	compute_ambient(t_pix *pix);
void ComputeLighting(t_pix *pix, float closestt, t_obj *sphere);
*/

//////////////TESTS

//camera
void test_camera3(void);
void test_camera2(t_pix ***pix);
void test_camera(t_pix ***pix);

#endif