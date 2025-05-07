/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_normals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:49:18 by syl               #+#    #+#             */
/*   Updated: 2025/05/06 11:35:10 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void	display_normal_as_color(t_pix *pix)
{
	t_coord	*n;

	n = malloc(sizeof(t_coord));

	copy_coord(n, pix->comps->v_norm_parral);
//	n = pix->comps->v_norm_parral;
//	normalize_vector_NA(n); // au cas où

	// On remappe les valeurs [-1, 1] vers [0, 255]
	pix->color->r = (unsigned char)((n->x + 1.0f) * 0.5f * 255);
	pix->color->g = (unsigned char)((n->y + 1.0f) * 0.5f * 255);
	pix->color->b = (unsigned char)((n->z + 1.0f) * 0.5f * 255);
}

void	display_dotNL_heatmap(t_pix *pix)
{
	float n_dot_l;
	int r, g, b;

	n_dot_l = dot_product(pix->comps->v_norm_parral, pix->comps->v_light_to_point);
	if (n_dot_l < 0)
		n_dot_l = 0;
	if (n_dot_l > 1)
		n_dot_l = 1;

	// heatmap : noir → rouge → jaune → blanc
	r = (int)(255 * n_dot_l);
	g = (int)(255 * n_dot_l * n_dot_l); // g augmente plus lentement
	b = (int)(80 * n_dot_l); // un peu de bleu, mais léger

	pix->color->r = r;
	pix->color->g = g;
	pix->color->b = b;
}

void	display_dotNL_as_color(t_pix *pix)
{
	float n_dot_l;
	int value;

	n_dot_l = dot_product(pix->comps->v_norm_parral, pix->comps->v_light_to_point);

	if (n_dot_l < 0)
		n_dot_l = 0; // pas de lumière "derrière"

	value = (int)(n_dot_l * 255.0f);
	if (value > 255)
		value = 255;

	pix->color->r = value;
	pix->color->g = value;
	pix->color->b = value;
}*/