/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray_calculs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:12:16 by syl               #+#    #+#             */
/*   Updated: 2025/03/08 10:20:49 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RAY_CALCULS_H
# define MINIRT_RAY_CALCULS_H

# include "minirt_data_struct.h"

//raycasting_main.c
t_ray *create_ray_(t_coord *p_origin, t_coord *v_direction);
t_coord *position(t_ray *r_ray, float t);

//intersect_sphere.c
//t_sphere *init_sphere(void); // a effacer


//ray_test.c 
void ray_testing();
void sphere_testing();

#endif