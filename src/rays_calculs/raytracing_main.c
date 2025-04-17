/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 14:04:24 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

#include <sys/time.h>

void raytracing(t_pix ***pix)
{
	//pour mesurer. A effacer
	struct timeval start;
	gettimeofday(&start, NULL);

	//creation de la camera
	constructing_camera(pix);
	start = time_now(start, " camera");
	//creation du viewport
	init_viewport(pix);
	// calculs matriciels pour déplacer et scale les objets
	start = time_now(start, " viewport");

	matrix_transformations(pix);
	//set_transformation(pix[0][0]->obj);
	// pareil pour les lumières
	set_transformation_light(pix[0][0]->lux);
	// pareil pour les lumières
	start = time_now(start, " set_transf");

	main_intersections(pix);
	start = time_now(start, " intersections");
	//trie les intersection selon la plus proche du viewport (et camera)
	find_closest_obj(pix);
	start = time_now(start, " closest obj");

	prepare_computation(pix);

	start = time_now(start, " prepare computation");
	transform_lights(pix[0][0]->lux);
	start = time_now(start, " transform lights");
	//intersect rayons avec sphere
	new_light(pix);
	start = time_now(start, " new lights");
	return;
}