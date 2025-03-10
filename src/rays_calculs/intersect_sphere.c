/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:00:12 by syl               #+#    #+#             */
/*   Updated: 2025/03/10 10:29:36 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//The sphere() function should return a unique value each time it is invoked.
//New function

// si t1 et / ou t2 négatifs, c est que c est derrière la camera

//NEWONE!!
void intersect_sphere(t_pix *pix, int sphere_num)// changer num sphere
{
	(void) sphere_num;
	float discriminant;
	float a;
	float b;
	float c;
	//faire boucle while après

	//arguments c'est ray et sphere

//	# the vector from the sphere's center, to the ray origin
	t_coord *v_sph_camera;
	v_sph_camera = substraction(pix->r_ray->p_origin, pix->obj[1][0]->p_coord);
	a = dot_product(pix->r_ray->v_dir, pix->r_ray->v_dir);
	b = 2 * dot_product(pix->r_ray->v_dir, v_sph_camera);
	c = dot_product(v_sph_camera, v_sph_camera) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
	{
		pix->t_count = 0;
		pix->t1 = INT_MAX;//necessaire??
		pix->t2 = INT_MAX;//necessaire??
		return;
	}
	pix->t1 =(-b + sqrt(discriminant)) / (2*a);
	pix->t2 = (-b - sqrt(discriminant)) / (2*a);
	return ;
}