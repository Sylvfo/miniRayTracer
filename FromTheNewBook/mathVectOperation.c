/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathVectOperation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:43:15 by sforster          #+#    #+#             */
/*   Updated: 2025/02/06 16:10:37 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirtnew.h"

// to know the opposit of a vectore
t_3Dcoord negat(t_3Dcoord v_1) 
{
	t_3Dcoord v_new;

	if (is_vector(v_1) == false)
		return (NULL);
	new.x = -t1.x;
	new.y = -t1.y;
	new.y = -t1.z;
	new.t = t1.t;
	return (v_new);	
}

// to scale vector ++ . 0.5 to make it half
t_3Dcoord scalar_mult(t_3Dcoord v_1, float scale) 
{
	t_3Dcoord v_new;

	if (is_vector(v_1) == false)
		return (NULL);
	v_new.x = scale * v_1.x;
	v_new.y = scale * v_1.y;
	v_new.y = scale * v_1.z;

	return (v_new);	
}

float length_vector(t_3Dcoord v_1, float scale) // magnitude or the size (length) of a vector
{
	float length;

	if (is_vector(v_1) == false)
		return (NULL);
	length = sqrt((v_1->x * v_1->x) + (v_1->y * v_1->y) + (v_1->z * v_1->z)); // pas besoin d ajouter le t c est juste?
	return (length);	
}

// convert a vector in a unit vector by divinding it by its length.
// aprox...
void normalize_vector(t_3Dcoord v1) //!!! diviser zero...
{
	t_3Dcoord new;
	float	length;

	if (length = length_vector(v1) == NULL)
		return ;
	if (length == 0)
	{
		printf("error in normalization \n");
		return;
	}
	// optimiser avec multiplication factor...
	new.x = vx.x / length;
	new.y = vx.y / length;
	new.z = vx.z / length;
	return(new);
}

//avec les angles et les cosin...
float dot_product(t_3Dcoord v1, t_3Dcoord v2)
{
	float	dot;

	if (is_vector(v1) == false)
		return (NULL);
	dot = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (dot);	
}

// You get a new vector that is perpendicular to both of the original vectors.
//order is important
t_3Dcoord cross_product(t_3Dcoord v1, t_3Dcoord v2)
{
	t_3Dcoord new;

	if (is_vector(v1) == false)
		return (NULL);
	new_vect.x = (v1->y * v2->z) - (v1->z * v2->y);
	new_vect.y = (v1->z * v2->x) - (v1->x * v2->z);
	new_vect.z = (v1->x * v2->y) - (v1->y* v2->x);
	return (new);
}

bool is_vector(t_3Dcoord v1)
{
	if (v1.t != 0)
	{
		printf("Not a vector\n");
		return (false);
	}
	return (true);
}
