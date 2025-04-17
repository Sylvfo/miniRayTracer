/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:38:36 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 15:46:21 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATRIX_H
# define MINIRT_MATRIX_H

# include "minirt_data_struct.h"

///////// MATRIX ////////////
//matrix_creation.c
float	*create_matrix(unsigned int row, unsigned int col);
void	init_matrix_zero(float *m_matrix);
void	matrix_fill(float *m_matrix, int row, int col, float number);
float	*create_indentity_matrix_44(void);

//matrix_comparison.c
bool	matrix_comparision(float *m_a, float *m_b);

//matrix_operations.c
float	*matrix_multiplication_44(float *m_a, float *m_b);
void	matrix_division(float *m_matrix, float div);

//matrix_mult_matrix_p_v.c
t_coord	*matrix_multiplication_44_coord(float *m_a, t_coord *p_v_1);
bool	check_matrix_44_coord(float *m_a, t_coord *p_v_1);
void	matrix_from_coord(t_coord *p_v_1, float coord[4]);
void	fill_point_vector(t_coord *new_point_vector, int count, float sum);

//matrix_utils.c
void	print_matrix(float *m_matrix);

//matrix_transposing.c
void	transposing_matrix_44(float *m_matrix);
void	copy_matrix_44_stack(float *m_matrix, float *m_tmp);

//INVERSION///
//matrix_determinant.c
float	determinant_22(float *m_22);
float	determinant_33(float *m_33);
float	determinant_44(float *m_44);

//matrix_minors.c
float	minor_33(float *m_matrix, int row, int col);
float	minor_44(float *m_matrix, int row, int col);
float	cofactors(int row, int col);

//matrix_submatrix.c
float	*submatrix(float *m_matrix, int row_to_remove, int col_to_remove);
int		get_curr_row(int i, float width);
int		get_curr_col(int i, float width);
int		check_submatrix(float *m_matrix, int row_rm, int col_rm);

//test_inverting.c
float	*inverted_matrix_44(float *m_matrix);
void	matrix_cofactors_44(float *m_matrix, float *m_cofactors);

//matrix_check.c
bool	check_matrix_44(float *m_a);
bool	check_matrix_33(float *m_a);
bool	check_matrix_22(float *m_a);
bool	check_matrix_44_44(float *m_a, float *m_b);

///////// MATRIX TRANSFORMATION ////////////

//matrix_translation.c
float *create_translation_matrix(float x, float y, float z);
t_coord *translation(t_coord *p_point, float x, float y, float z);
t_coord *translation_inverse(t_coord *p_point, float x, float y, float z);
void translation_on_identity(float *m_identity, float x, float y, float z);

//matrix_scaling.c
t_coord *scaling(t_coord *v_p_old, float x, float y, float z);
float *create_scaling_matrix(float x, float y, float z);
t_coord *scaling_inverse(t_coord *v_p_old, float x, float y, float z);

//matrix_rotation.c
//float *create_rotation_x_matrix(float radian);
//t_coord *rotation_axe_x(t_coord *p_point, float radian);
//t_coord *rotation_axe_x_inverse(t_coord *p_point, float radian);
//float *_x_matrix_inverse(float radian);

//matrix_rotations.c
t_coord *rotations(t_coord *p_point, int axe, int dir,  float radian);
float *create_rotation_x_matrix(float radian);
float *create_rotation_y_matrix(float radian);
float *create_rotation_z_matrix(float radian);

//matrix_rotations_utils.c
float degree_to_radian(float degree);
bool	check_rotation_values(t_coord *p_point, int axe, int dir, float radian);

#endif