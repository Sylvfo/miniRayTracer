/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hits_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:47:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/15 08:17:42 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	initialize_hits_arrays(t_hits ***hits, t_num_obj *num_obj)
{
	init_hits_background(hits);
	init_hits_spheres(hits, num_obj);
	init_hits_plans(hits, num_obj);
	init_hits_cylinders(hits, num_obj);
}
