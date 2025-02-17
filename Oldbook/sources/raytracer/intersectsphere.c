/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectsphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:45:30 by syl               #+#    #+#             */
/*   Updated: 2025/01/26 15:29:56 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minirt.h"

//p 25 dans computer graphics from scratch
void IntersectRaySphere(t_pix *pix, t_sphere *sphere)
{
	float discriminant;
	float a;
	float b;
	float c;
	t_vect3d *CO;

	CO = malloc(sizeof(t_vect3d));
	CO->x = -sphere->center->x;
	CO->y = -sphere->center->y;
	CO->z = -sphere->center->z;
	a = dot_product(pix->D, pix->D);
	b = 2 * dot_product(CO, pix->D);
	c = dot_product(CO, CO) - (sphere->radius * sphere->radius);

	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
	{
		pix->t1 = INT_MAX;
		pix->t2 = INT_MAX;
		return;
	}
	pix->t1 =(-b + sqrt(discriminant)) / (2*a);
	pix->t2 = (-b - sqrt(discriminant)) / (2*a);
	free (CO);
}