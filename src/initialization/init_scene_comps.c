/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:20:35 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 20:59:55 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initialization.h"

static void	init_comps_vectors(t_comps *c, t_pix *pix)
{
	c->r_dir = malloc(sizeof(t_coord));
	c->r_origin = malloc(sizeof(t_coord));
	copy_coord(c->r_dir, pix->r_dir);
	copy_coord(c->r_origin, pix->r_origin);
	c->p_touch = malloc(sizeof(t_coord));
	c->v_eye = malloc(sizeof(t_coord));
	c->v_norm_parral = malloc(sizeof(t_coord));
	c->v_light_to_point = create_vector(0, 0, 0);
	c->v_sphere_to_point = create_vector(0, 0, 0);
	c->reflect_dir = create_vector(0, 0, 0);
	c->scalar = create_vector(0, 0, 0);
	c->view_dir = create_vector(0, 0, 0);
	c->p_space = create_point(0, 0, 0);
	c->origin_zero = create_point(0, 0, 0);
	c->object_normal = create_vector(0, 0, 0);
	c->transp_inv = create_matrix(4, 4);
	c->obj_inv = create_matrix(4, 4);
	c->v_point_to_light = create_point(0, 0, 0);
}

static void	init_comps_basic(t_comps *c, t_pix *pix)
{
	c->closestt = INT_MAX;
	c->t_count = 0;
	c->obj = pix->obj[0][0];
	c->type = NONE;
	copy_color(c->obj_color, pix->obj[0][0]->color);
}

void	init_pix_comps(t_pix ***pix)
{
	int	x;
	int	y;

	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			init_comps_basic(pix[x][y]->comps, pix[x][y]);
			init_comps_vectors(pix[x][y]->comps, pix[x][y]);
			y++;
		}
		x++;
	}
}
