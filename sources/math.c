/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:28:57 by sforster          #+#    #+#             */
/*   Updated: 2025/01/24 15:32:06 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

float dot_product(t_vect3d *va, t_vect3d *vb)
{
	float	dot;

	dot = (va->x * vb->x) + (va->y * vb->y) + (va->z * vb->z);
	return (dot);
}

t_vect3d *vect_from_points(t_3dpoint *a, t_3dpoint *b)
{
	t_vect3d *new;

	new = malloc(sizeof(t_vect3d));
	new->x = a->x - b->x;
	new->y = a->y - b->y;
	new->z = a->z - b->z;
	return (new);
}

float	lenght_vector(t_vect3d *vect)
{
	float	length;

	length = sqrt((vect->x * vect->x) + (vect->y * vect->y) + (vect->z * vect->z));
	return (length);	
}

void normalize_vector(t_vect3d *vect)
{
	float magnitude;

	magnitude = sqrt((vect->x * vect->x) + (vect->y * vect->y) + (vect->z * vect->z));
	vect->x /= magnitude;
	vect->y /= magnitude;
	vect->z /= magnitude;
}

t_3dpoint *pointonline(t_pix *pix, float closestt)
{
	t_3dpoint *P;
	float D_norm;// pas bien compris vecteur directionnel normalisé
	
	P = malloc(sizeof(t_3dpoint));
	D_norm = sqrt(pix->D->x * pix->D->x + pix->D->y * pix->D->y + pix->D->z * pix->D->z);
	if (D_norm == 0)
	{
		P = pix->global->cam;
		return (P);
	}
	P->x = pix->global->cam->x + closestt * (pix->D->x / D_norm);
	P->y = pix->global->cam->y + closestt * (pix->D->y / D_norm);
	P->z = pix->global->cam->z + closestt * (pix->D->z / D_norm);
}

t_vect3d	*addition(t_vect3d *a, t_vect3d *b)
{
	t_vect3d	*new_vect;

	new_vect = malloc(sizeof(t_vect3d));
	new_vect->x = a->x + b->x;
	new_vect->y = a->y + b->y;
	new_vect->z = a->z + b->z;
	return (new_vect);
}

t_vect3d	*substraction_point(t_3dpoint *a, t_3dpoint *b)
{
	t_vect3d	*new_p;

	new_p = malloc(sizeof(t_vect3d));
	new_p->x = a->x - b->x;
	new_p->y = a->y - b->y;
	new_p->z = a->z - b->z;
	return (new_p);
}

t_vect3d	*substraction(t_vect3d *a, t_vect3d *b)
{
	t_vect3d	*new_vect;

	new_vect = malloc(sizeof(t_vect3d));
	new_vect->x = a->x - b->x;
	new_vect->y = a->y - b->y;
	new_vect->z = a->z - b->z;
	return (new_vect);
}

t_vect3d	*multiplication(t_vect3d *a, float n)
{
	a->x *= n;
	a->y *= n;
	a->z *= n;
	return (a);
}

t_vect3d	*cross_product(t_vect3d *a, t_vect3d *b)
{
	t_vect3d	*new_vect;

	new_vect = malloc(sizeof(t_vect3d));
	new_vect->x = (a->y * b->z) - (a->z * b->y);
	new_vect->y = (a->z * b->x) - (a->x * b->z);
	new_vect->z = (a->x * b->y) - (a->y* b->x);
	return (new_vect);
}

float	carre(float n)
{
	return n * n;
}