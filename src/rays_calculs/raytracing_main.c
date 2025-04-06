/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/06 23:53:58 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void raytracing(t_pix ***pix)
{
	//à déplacer ensuite dans init_data
	constructing_camera(pix);
	init_viewport2(pix);
//	exit(0);
	// calculs matriciels pour déplacer et scale les objets. 
	set_transformation(pix[0][0]->obj);
	set_transformation_light(pix[0][0]->lux);
	transform_lights(pix[0][0]->lux);
	main_sphere(pix);
	//intersect plan
	// intersect Cylindre
	find_closest_obj(pix);
//	exit(1);
	prepare_computation(pix);
	new_light(pix);
	return;
}