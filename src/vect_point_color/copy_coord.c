/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:09:12 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 14:14:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	copy_coord(t_coord *new, t_coord *origin)
{
	new->x = origin->x;
	new->y = origin->y;
	new->z = origin->z;
	new->t = origin->t;
}

void	copy_color(t_color *new, t_color *origin)
{
	new->r = origin->r;
	new->g = origin->g;
	new->b = origin->b;
	new->rgb = origin->rgb;
}

void	vector_fill(t_coord *vect, float x, float y, float z)
{
	vect->x = x;
	vect->y = y;
	vect->z = z;
}
