/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transf_testing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:57:22 by syl               #+#    #+#             */
/*   Updated: 2025/02/27 09:39:43 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void test_transformation(void)
{
	t_coord *p_point;
	float	*m_transl;
	t_coord	*p_result;
	float	*m_inverted;
	t_coord	*v_vector;
	t_coord	*new_v;

//	p_point = create_point(-3, 4, 5);

//	p_result = translation_inverse(p_point, 5, -3, 2);

//	p_result = matrix_multiplication_44_coord(m_inverted, p_point);
//	print_matrix(m_transl);
//	print_point(p_result);
	

	v_vector = create_vector(-3, 4, 5);
	new_v = translation(v_vector, 5, -3, 2);
	print_vector(new_v);

//	free(p_point);
//	free(p_result);
//	free(p_result);
}


void test_scaling(void)
{
	t_coord	*v_vector;
	t_coord	*new_v;
	float *m_scale;
	t_coord *new_point;


	t_coord *p_point = create_point(-4, 6, 8);
	new_point = scaling(p_point, 2, 3, 4);
	print_point(new_point);

	v_vector = create_vector(-4, 6, 8);
//	new_v = scaling(v_vector, 2, 3, 4);
	new_v = scaling_inverse(v_vector, 2, 3, 4);
	print_vector(new_v);

	t_coord *p_point = create_point(2, 3, 4);
	new_point = scaling(p_point, -1, 1, 1);
	print_point(new_point);

}

void test_rotation(void)
{
	t_coord *p_point;
	t_coord *p_new;
	t_coord *p_new2;
	float radian;
	float radian2;

	radian = ((float)M_PI/4);
	radian2 = ((float)M_PI/2);

	p_point = create_point(0, 1, 0);
	p_new = rotation_axe_x(p_point, radian);
	p_new2 = rotation_axe_x(p_point, radian2);

	print_point(p_new);
	print_point(p_new2);

	p_new2 = rotation_axe_x_inverse(p_point, radian);	
	print_point(p_new2);
	t_coord *p_point;
	t_coord *p_new;
	t_coord *p_new2;
	float radian;
	float radian2;

	radian = ((float)M_PI/4);
	radian2 = ((float)M_PI/2);

	//check y axe
	p_point = create_point(0, 0, 1);
	p_new = rotations(p_point, axe_y, left_h, radian);
	p_new2 = rotations(p_point, axe_y, left_h, radian2);
	print_point(p_new);
	print_point(p_new2);

	//check z axe
	p_point = create_point(0, 1, 0);
	p_new = rotations(p_point, axe_z, left_h, radian);
	p_new2 = rotations(p_point, axe_z, left_h, radian2);
	print_point(p_new);
	print_point(p_new2);

}*/
