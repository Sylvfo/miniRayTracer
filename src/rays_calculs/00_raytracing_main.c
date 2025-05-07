/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 10:16:41 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


#include <sys/time.h>

void raytracing(t_pix ***pix)
{
	//pour mesurer. A effacer
	struct timeval start;
	gettimeofday(&start, NULL);

	if (init_a_deplacer(pix) == false)
		exit(0);
	start = time_now(start, " init");

	//creation de la camera
	constructing_camera(pix);
	start = time_now(start, " camera");
	//creation du viewport
	init_viewport(pix);
	// calculs matriciels pour déplacer et scale les objets
	start = time_now(start, " viewport");

	matrix_transformations(pix);
	start = time_now(start, " set_transf");

	//intersect rayons avec sphere
	main_intersections(pix);
	start = time_now(start, " intersections");

	//trie les intersection selon la plus proche du viewport (et camera)
	find_closest_obj(pix);
	start = time_now(start, " closest obj");

	prepare_computation(pix);
	start = time_now(start, " prepare computation");
	
	new_light(pix);
	start = time_now(start, " new lights");
	return;
}




