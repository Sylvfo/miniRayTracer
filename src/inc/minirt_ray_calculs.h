/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray_calculs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:16 by syl               #+#    #+#             */
/*   Updated: 2025/03/11 13:31:04 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_CALCULS_H
# define MINIRT_RAY_CALCULS_H

# include "minirt_data_struct.h"

//raytracing_main.c
void raytracing(t_pix ***pix);

//raycasting.c
t_ray *create_ray(t_coord *p_origin, t_coord *v_direction);
t_coord *position(t_ray *r_ray, float t);

//intersect_sphere.c
void intersect_sphere(t_pix *pix, int sphere_num);
void main_sphere(t_pix ***pix);

//ray_test.c 
void ray_testing();
void sphere_testing();
void test_ray(void);
void test_sphere(t_pix ***pix);
void test_normal_at(t_pix ***pix);

//closest_obj.c
void find_closest_obj(t_pix ***pix);
void closest_obj(t_pix *pix);

//intersect_sphere.c
t_coord *normal_at(t_obj *sphere, t_coord *point_on_sphere);

#endif