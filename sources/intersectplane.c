/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectplane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:20:40 by syl               #+#    #+#             */
/*   Updated: 2025/01/24 15:32:56 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void intersectrayplane(t_pix *pix, t_plane *plane)
{
	float DdotN;
	float t;

	DdotN = dot_product(pix->D, plane->normal);
	if (DdotN == 0.0)
		return ;//false??

	t = dot_product(substraction_point(plane->point, pix->global->cam), plane->normal) / DdotN;
/*	if (t <= RAY_T_MIN || t >= pix->t1);
	{
	//	pix->color = 0x62414e;
		return;
	}*/
	pix->t1 = t;
//	pix->color = 253;
//	pix->color = plane->color;
//	return (true)
}


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


	// CO = O - sphere.center  do product of the ray with himself
	// Dot Product: The dot product of a vector with itself is computed by 
	//⟨P−C,P−C⟩=(Px−Cx)2+(Py−Cy)2+(Pz−Cz)2⟨P−C,P−C⟩
	// Square of rr: The right-hand side of the equation is r2r2, which is just a scalar valu