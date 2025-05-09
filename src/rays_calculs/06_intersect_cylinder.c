/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_intersect_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:29:35 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 14:25:01 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	intersect_cylinder(t_pix *pix, int cyl_n)
{
	float	a;
	float	b;
	float	c;
	float	discriminant;

	a = pix->hits[3][cyl_n]->r_dir->x * pix->hits[3][cyl_n]->r_dir->x
		+ pix->hits[3][cyl_n]->r_dir->z * pix->hits[3][cyl_n]->r_dir->z;
	if (fabs(a) < EPSILON)
		return ;
	b = 2 * pix->hits[3][cyl_n]->r_origin->x * pix->hits[3][cyl_n]->r_dir->x
		+ 2 * pix->hits[3][cyl_n]->r_origin->z * pix->hits[3][cyl_n]->r_dir->z;
	c = pix->hits[3][cyl_n]->r_origin->x * pix->hits[3][cyl_n]->r_origin->x
		+ pix->hits[3][cyl_n]->r_origin->z * pix->hits[3][cyl_n]->r_origin->z
		- 1;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return ;
	pix->hits[3][cyl_n]->t_count = 2;
	cut_cylinder(pix, cyl_n, (-b - simple_sqrt(discriminant)) / (2 * a),
		(-b + simple_sqrt(discriminant)) / (2 * a));
	intersect_caps(pix, cyl_n);
}

void	cut_cylinder(t_pix *pix, int cyl_n, float t1, float t2)
{
	float	y1;
	float	y2;
	float	tmp;

	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	y1 = pix->hits[3][cyl_n]->r_origin->y + t1 * pix->hits[3][cyl_n]->r_dir->y;
	if (-pix->obj[3][cyl_n]->height < y1 && y1 < pix->obj[3][cyl_n]->height)
	{
		pix->hits[3][cyl_n]->t1 = t1;
		pix->hits[3][cyl_n]->t_count = 1;
	}
	y2 = pix->hits[3][cyl_n]->r_origin->y + t2 * pix->hits[3][cyl_n]->r_dir->y;
	if (-pix->obj[3][cyl_n]->height < y2 && y2 < pix->obj[3][cyl_n]->height)
	{
		pix->hits[3][cyl_n]->t2 = t2;
		pix->hits[3][cyl_n]->t_count++;
	}
}

bool	check_cap(t_pix *pix, float t, int cyl_n)
{
	float	x;
	float	z;

	x = pix->hits[3][cyl_n]->r_origin->x + t * pix->hits[3][cyl_n]->r_dir->x;
	z = pix->hits[3][cyl_n]->r_origin->z + t * pix->hits[3][cyl_n]->r_dir->z;
	if (x * x + z * z <= 1)
		return (true);
	return (false);
}

void	intersect_caps(t_pix *pix, int cyl_n)
{
	float	t;

	if (fabs(pix->hits[3][cyl_n]->r_dir->y) < EPSILON)
		return ;
	if (pix->obj[3][cyl_n]->closed_down == true)
	{
		t = (-pix->obj[3][cyl_n]->height - pix->hits[3][cyl_n]->r_origin->y)
			/ pix->hits[3][cyl_n]->r_dir->y;
		if (check_cap(pix, t, cyl_n) == true)
		{
			pix->hits[3][cyl_n]->t_count = 8;
			pix->hits[3][cyl_n]->t2 = t;
		}
	}
	if (pix->obj[3][cyl_n]->closed_up == true)
	{
		t = (pix->obj[3][cyl_n]->height - pix->hits[3][cyl_n]->r_origin->y)
			/ pix->hits[3][cyl_n]->r_dir->y;
		if (check_cap(pix, t, cyl_n) == true)
		{
			pix->hits[3][cyl_n]->t_count = 9;
			pix->hits[3][cyl_n]->t1 = t;
		}
	}
}
