/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 10:08:17 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 12:21:01 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/**
 * @brief copy r2 into r1
 * 
 * 	r1 = r2
 * 
 * @param t_ray *r1, t_ray *r2
 * 
 * @return void
 */
/*t_ray *copy_ray(t_ray *r2)
{
	t_ray *r1;

	r1 = malloc(sizeof(t_ray));
	r1->p_origin = malloc(sizeof(t_coord));
	r1->v_dir = malloc(sizeof(t_coord));
	r1->p_origin->x = r2->p_origin->x;
	r1->p_origin->y = r2->p_origin->y;
	r1->p_origin->z = r2->p_origin->z;
	r1->p_origin->t = r2->p_origin->t;
	r1->v_dir->x = r2->v_dir->x;
	r1->v_dir->y = r2->v_dir->y;
	r1->v_dir->z = r2->v_dir->z;
	r1->v_dir->t = r2->v_dir->t;

	//normaliser?? vraiment??
	r1->v_dir = normalize_vector(r1->v_dir);
	return(r1);
}*/
