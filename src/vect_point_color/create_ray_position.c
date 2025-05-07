/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:17:39 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 17:20:05 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void position_NA(t_pix *pix, t_coord *r_dir, float t)
{
    t_coord    tmp;
	t_coord	*r_dir_norm;

	r_dir_norm = create_vector(0,0,0);
	copy_coord(r_dir_norm, r_dir);
	normalize_vector_NA(r_dir_norm);
    scalar_mult_NA(&tmp, r_dir_norm, t);
	addition_NA(pix->comps->p_touch, pix->cam->p_coord, &tmp);
}
