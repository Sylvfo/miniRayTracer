/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:42:30 by syl               #+#    #+#             */
/*   Updated: 2025/02/28 13:22:04 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
/*
t_sphere *init_sphere(void) // a effacer
{
	t_sphere *sphere;

	sphere = malloc(sizeof(t_scene));

	sphere = malloc(sizeof(t_sphere));
	sphere->center = malloc(sizeof(t_coord));
	sphere->center->x = 0;
	sphere->center->y = 0;
	sphere->center->z = 0;
	sphere->radius = 1;
	sphere->color = 7536700;

	return (sphere)
}

// intersect(sphere, ray), which returns the collection 
// of t values where the ray intersects the sphere.

//For the tangent case, both intersections will have the same t value,
//as mentioned earlier

void	intersect_sphere(t_sphere *sphere, t_ray *r_ray)
{
	t_coord *v_origin_center; // dans data struct
	t_coord *p_center_sph; // dans data struct
	float a;
	float b;
	float c;
	float discriminant;
	
	p_center_sph = create_point(0, 0, 0);
	v_origin_center = substraction(r_ray->p_origin, p_center_sph);
	a = dot_product(r_ray->v_dir, r_ray->v_dir);
	b = 2 * dot_product(r_ray->v_dir, v_origin_center);
	c = dot_product(v_origin_center, v_origin_center) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
	{
//		pix->t1 = INT_MAX;
//		pix->t2 = INT_MAX;
		return;
	}
	pix->t1 =(-b + sqrt(discriminant)) / (2*a);
	pix->t2 = (-b - sqrt(discriminant)) / (2*a);
	return ();
}*/
