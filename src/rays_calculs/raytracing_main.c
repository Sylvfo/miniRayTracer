/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/07 17:23:30 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void raytracing(t_pix ***pix)
{
	//creation de la camera
	constructing_camera(pix);
	//creation du viewport
	init_viewport2(pix);
	// calculs matriciels pour déplacer et scale les objets
	set_transformation(pix[0][0]->obj);
	// pareil pour les lumières
	set_transformation_light(pix[0][0]->lux);
	// pareil pour les lumières
	transform_lights(pix[0][0]->lux);
	//intersect rayons avec sphere
	main_sphere(pix);
	//intersect plan
	// intersect Cylindre

	//trie les intersection selon la plus proche du viewport (et camera)
	find_closest_obj(pix);
	prepare_computation(pix);
	new_light(pix);
	return;
}