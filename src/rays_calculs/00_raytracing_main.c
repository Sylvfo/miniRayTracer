/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 14:09:32 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//effacer les mesures du temps
#include <sys/time.h>

struct timeval time_now(struct timeval start, char *str)
{
	struct timeval now;
	gettimeofday(&now, NULL);

	double duration = (now.tv_sec - start.tv_sec) + (now.tv_usec - start.tv_usec) / 1e6;
	printf("Time at %s : %.8f \n", str, duration);
	return (now);
}

void	raytracing(t_pix ***pix)
{
	struct timeval	start;
	struct timeval	total;

	gettimeofday(&start, NULL);
	gettimeofday(&total, NULL);
//	if (init_a_deplacer(pix) == false)
//		exit(0);
	start = time_now(start, " init");
	constructing_camera(pix);
	start = time_now(start, " camera");
	init_viewport(pix);
	start = time_now(start, " viewport");
	matrix_transformations(pix);
	start = time_now(start, " set_transf");
	main_intersections(pix);
	start = time_now(start, " intersections");
	find_closest_obj(pix);
	start = time_now(start, " closest obj");
	prepare_computation(pix);
	start = time_now(start, " prepare computation");
	new_light(pix);
	start = time_now(start, " new lights");
	total = time_now(total, " total");
	return ;
}

