/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raytracing_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:27:13 by syl               #+#    #+#             */
/*   Updated: 2025/05/15 10:52:02 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	raytracing(t_pix ***pix)
{
	constructing_camera(pix);
	init_viewport(pix);
	matrix_transformations(pix);
	main_intersections(pix);
	pix[0][0]->lux[1][0]->p_coord->t = 1;
	find_closest_obj(pix);
	prepare_computation(pix);
	new_light(pix);
	return ;
}
