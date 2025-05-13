/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_comps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:20:35 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 15:38:54 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/initialization.h"

static int	init_comps_vectors_allocs(t_comps *c, t_pix *pix)
{
	c->r_dir = malloc(sizeof(t_coord));
	c->r_origin = malloc(sizeof(t_coord));
	c->p_touch = malloc(sizeof(t_coord));
	c->v_eye = malloc(sizeof(t_coord));
	c->v_norm_parral = malloc(sizeof(t_coord));
	if (!c->r_dir || !c->r_origin || !c->p_touch || !c->v_eye
		|| !c->v_norm_parral)
		return (1);
	copy_coord(c->r_dir, pix->r_dir);
	copy_coord(c->r_origin, pix->r_origin);
	return (0);
}

static int	init_comps_vectors_creations(t_comps *c)
{
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
	if (!c->v_light_to_point || !c->v_sphere_to_point || !c->reflect_dir
		|| !c->scalar || !c->view_dir || !c->p_space || !c->origin_zero
		|| !c->object_normal || !c->transp_inv || !c->obj_inv
		|| !c->v_point_to_light)
		return (1);
	return (0);
}

static int	init_comps_vectors(t_comps *c, t_pix *pix)
{
	if (init_comps_vectors_allocs(c, pix) != 0)
		return (1);
	if (init_comps_vectors_creations(c) != 0)
		return (1);
	return (0);
}

static int	init_comps_basic(t_comps *c, t_pix *pix)
{
	c->closestt = INT_MAX;
	c->t_count = 0;
	c->obj = pix->obj[0][0];
	c->type = NONE;
	c->obj_color = malloc(sizeof(t_color));
	if (!c->obj_color)
		return (1);
	copy_color(c->obj_color, pix->obj[0][0]->color);
	return (0);
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
			if (init_comps_basic(pix[x][y]->comps, pix[x][y]) != 0)
			{
				fprintf(stderr,
					"Erreur: init_comps_basic pixel [%d][%d]\n", x, y);
			}
			if (init_comps_vectors(pix[x][y]->comps, pix[x][y]) != 0)
			{
				fprintf(stderr,
					"Erreur: init_comps_vectors pixel [%d][%d]\n", x, y);
			}
			y++;
		}
		x++;
	}
}
