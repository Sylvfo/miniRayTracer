/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/14 19:52:48 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//effacer les mesures du temps
#include <sys/time.h>

void	raytracing(t_pix ***pix)
{
	constructing_camera(pix);
	init_viewport(pix);
	matrix_transformations(pix);
	main_intersections(pix);

/*	int i;
	i = 0;
	while (i < 1)
	{
		printf("cyl n %i, t1: %.4f, t2: %.4f t_count %i  \n", i, pix[540][450]->hits[3][i]->t1, pix[540][450]->hits[3][i]->t2, pix[540][450]->hits[3][i]->t_count);
		printf("cyl n %i, t1: %.4f, t2: %.4f t_count %i  \n", i, pix[480][450]->hits[3][i]->t1, pix[480][450]->hits[3][i]->t2, pix[540][450]->hits[3][i]->t_count);
		i++;
	}*/
	pix[0][0]->lux[1][0]->p_coord->t = 1;

	find_closest_obj(pix);
	prepare_computation(pix);
	new_light(pix);
	return ;
}
