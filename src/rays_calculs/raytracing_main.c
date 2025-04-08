/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/08 14:32:51 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void raytracing(t_pix ***pix)
{
	//creation de la camera
	constructing_camera(pix);
	//creation du viewport
	init_viewport(pix);
	// calculs matriciels pour déplacer et scale les objets
	set_transformation(pix[0][0]->obj);
	// pareil pour les lumières
	set_transformation_light(pix[0][0]->lux);
	// pareil pour les lumières

	main_intersections(pix);

	//trie les intersection selon la plus proche du viewport (et camera)
	find_closest_obj(pix);
	prepare_computation(pix);

	transform_lights(pix[0][0]->lux);
	//intersect rayons avec sphere
	new_light(pix);
	return;
}