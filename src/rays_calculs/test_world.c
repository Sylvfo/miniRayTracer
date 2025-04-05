/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:15:21 by syl               #+#    #+#             */
/*   Updated: 2025/04/05 13:36:13 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void test_word()*/

void test_shade_intersection(void)
{
	t_coord *p;
	t_coord *v;

	t_ray 	*ray;

	p = create_point(0, 0, -5);
	v = create_vector(0, 0, 1);
	ray = create_ray(p, v);
	
}