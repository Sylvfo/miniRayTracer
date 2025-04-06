/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:17:39 by syl               #+#    #+#             */
/*   Updated: 2025/04/06 14:36:20 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//Ray casting is the process of creating a ray, or line, and finding 
//the intersections of that ray with the objects in a scene.

/*
typedef struct s_ray
{
	t_coord *p_origin;
	t_coord *v_direction;
	t_coord *v_norm;
} t_ray; */

// origin = camera
t_ray *create_ray(t_coord *p_origin, t_coord *v_direction)
{
	t_ray *r_ray;

	if (is_point(p_origin) == false)
		return (NULL);
	if (is_vector(v_direction) == false)
		return (NULL);
	r_ray = malloc(sizeof(t_ray));
	if (!r_ray)
		return (NULL);
	r_ray->p_origin = p_origin;
	r_ray->v_dir = v_direction;
	return (r_ray);
}

t_coord *position(t_ray *r_ray, float t)
{
	// Calculer le nouveau point en ajoutant l'origine et la direction multipliée par t
	return addition(r_ray->p_origin, scalar_mult(r_ray->v_dir, t));
}
