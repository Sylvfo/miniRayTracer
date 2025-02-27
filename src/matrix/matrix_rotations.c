/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:07:11 by syl               #+#    #+#             */
/*   Updated: 2025/02/27 09:37:23 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// Multiplying a tuple by a rotation matrix will 
// rotate that tuple around an axis

// We’re only going to deal with the simplest rotations 
//here—rotating around the x, y, and z axes.

// The rotation will appear to be clockwise around the 
// corresponding axis when viewed along that axis,

//angles in radian in c
// 360° is 2pi. 180° = pi and 90° = 1/2 pi

// radian(deg) = (deg/180) * pi
// float value = (float)M_PI / 180.0f; M_PI part of math.h in double

// rotation around the X axis. 

//CREER MATRIX ROTATIONS DANS BASE DE DONNEE
// par exemple pix->matrix->rotationy;
// 

//dir = direction
// enum donc 4 = left et 5 right

t_coord	*rotations(t_coord *p_point, int axe, int dir, float radian)
{
	float	*m_rotation;
	t_coord	*p_new;

	if (check_rotation_values(p_point, axe, dir, radian) == false)
	{
		printf("problem with values in rotations \n");
		return (NULL);
	}
	if (axe == 0)
		m_rotation = create_rotation_x_matrix(radian);
	else if (axe == 1)
		m_rotation = create_rotation_y_matrix(radian);
	else if (axe == 2)
		m_rotation = create_rotation_z_matrix(radian);
	if (m_rotation == NULL)
		return (NULL);
	if (dir == right_h)
		m_rotation = inverted_matrix_44(m_rotation);
	p_new = matrix_multiplication_44_coord(m_rotation, p_point);
	return (p_new);
}

float	*create_rotation_x_matrix(float radian)
{
	float	*m_rotation;
	float	sinr;
	float	cosr;

	sinr = sin(radian);
	cosr = cos(radian);
	m_rotation = create_matrix(4, 4);
	matrix_fill(m_rotation, 0, 0, 1);
	matrix_fill(m_rotation, 1, 1, cosr);
	matrix_fill(m_rotation, 1, 2, -sinr);
	matrix_fill(m_rotation, 2, 1, sinr);
	matrix_fill(m_rotation, 2, 2, cosr);
	matrix_fill(m_rotation, 3, 3, 1);
	return (m_rotation);
}

float	*create_rotation_y_matrix(float radian)
{
	float	*m_rotation;
	float	sinr;
	float	cosr;

	sinr = sin(radian);
	cosr = cos(radian);
	m_rotation = create_matrix(4, 4);
	matrix_fill(m_rotation, 0, 0, cosr);
	matrix_fill(m_rotation, 0, 2, sinr);
	matrix_fill(m_rotation, 1, 1, 1);
	matrix_fill(m_rotation, 2, 0, -sinr);
	matrix_fill(m_rotation, 2, 2, cosr);
	matrix_fill(m_rotation, 3, 3, 1);
	return (m_rotation);
}

float	*create_rotation_z_matrix(float radian)
{
	float	*m_rotation;
	float	sinr;
	float	cosr;

	sinr = sin(radian);
	cosr = cos(radian);
	m_rotation = create_matrix(4, 4);
	matrix_fill(m_rotation, 0, 0, cosr);
	matrix_fill(m_rotation, 0, 1, -sinr);
	matrix_fill(m_rotation, 1, 0, sinr);
	matrix_fill(m_rotation, 1, 1, cosr);
	matrix_fill(m_rotation, 2, 2, 1);
	matrix_fill(m_rotation, 3, 3, 1);
	return (m_rotation);
}
