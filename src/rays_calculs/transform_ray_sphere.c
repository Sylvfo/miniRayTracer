/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:47:30 by syl               #+#    #+#             */
/*   Updated: 2025/03/11 17:15:11 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//You say you want to move the sphere, but what you
//really want, fundamentally, is for the distance between the sphere and the
//ray’s origin to increase or decrease, or the relationship between the ray’s
//direction and the sphere’s position to change,

//What if, instead of moving the sphere, you move the ray?

//whatever transformation you want to apply to the sphere,
//apply the inverse of that transformation to the ray


//applies the given transformation matrix to the given ray, 
//and returns a new ray with transformed origin and direction
// a new ray!!!
void transform(t_ray *ray, float *trans_matrix)
{
	t_ray	*new_ray;
	t_coord *transl;

	new_ray = malloc(sizeof(t_ray));
	new_ray->p_origin = translation(ray->p_origin, 3, 4, 5);// pointeur sur fonction??
	new_ray->v_dir = ray->v_dir;
	return 
}