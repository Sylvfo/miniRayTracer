/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:08:28 by syl               #+#    #+#             */
/*   Updated: 2025/03/11 13:20:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


void sphere_testing()
{
	t_ray *r_test;
	t_coord *p_origin;
	t_coord *v_vect;
	t_sphere *s_sphere;


	p_origin = create_point(0, 0, -5);
	v_vect = create_vector(0, 0, 1);
	r_test = create_ray(p_origin, v_vect);
	s_sphere = init_sphere();
}*/