/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:09:12 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 12:47:56 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_coord	*copy_coord(t_coord *origin)
{
	t_coord *new;

	new->x = origin->x;
	new->y = origin->y;
	new->z = origin->z;
	new->t = origin->t;
	return (new);
}