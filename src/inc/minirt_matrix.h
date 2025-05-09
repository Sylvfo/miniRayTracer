/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:38:36 by syl               #+#    #+#             */
/*   Updated: 2025/05/09 16:33:01 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATRIX_H
# define MINIRT_MATRIX_H

# include "minirt_data_struct.h"

///////// MATRIX ////////////

//matrix_print.c
void	print_matrix(float *m_matrix);
void	print_matrix_44(float *m);

//matrix_transl_scale.c
void	translation_matrix_coord(t_obj *obj);
void	scaling_matrix_coord(t_obj *obj);
void	fill_translation_matrix(float *m_transl, float x, float y, float z);

//matrix_creation.c
float	*create_matrix(unsigned int row, unsigned int col);
void	init_matrix_zero(float *m_matrix);
void	matrix_fill(float *m_matrix, int row, int col, float number);
float	*create_indentity_matrix_44(void);

//matrix_utils.c
void	matrix_from_coord(t_coord *p_v_1, float coord[4]);
bool	check_matrix_44_coord(float *m_a, t_coord *p_v_1);

//matrix_operations.c
void	matrix_division(float *m_matrix, float div);

//matrix_transposing.c
void	transpose_matrix_NA(float *result, float *m);
//utile???
void	transposing_matrix_44(float *m_matrix);
void	copy_matrix_44(float *m_result, float *m_matrix);
 
//matrix_check.c
bool	check_matrix_44(float *m_a);
bool	check_matrix_33(float *m_a);
bool	check_matrix_22(float *m_a);
bool	check_matrix_44_44(float *m_a, float *m_b);

//matrix_rotation_rodrigues.c 
void	rotation_from_vector_NA(t_obj *obj);
void	matrix_rotation_rodrigues(t_obj *obj, float angle, float c, float s);

//matrix_multiplication.c
void	matrix_point_multiplication_new(t_coord *result, float *m, t_coord *p);
void	matrix_mult_2(float *ma, float *mb);
void	matrix_mult_3(float *res, float *ma, float *mb);


//INVERSION///
//matrix_determinant.c
//float	determinant_22(float *m_22);
//float	determinant_33(float *m_33);
//float	determinant_44(float *m_44);


void	new_inverse_matrix_44(float *m_inverted, float *m_matrix);
void	new_submatrix_33(float *m_submatrix, float *m_matrix, int row_to_rm, int col_to_rm);
float	new_minor_33(float *m);
void	new_minor_44(float *m_minor, float *m_matrix);
float	new_determinant_44(float *m_matrix, float *m_minor);
void	init_stack_matrix_33(float *m_matrix);
void	init_stack_matrix_44(float *m_matrix);
void	transposing_matrix_44(float *m_matrix);


int	get_curr_row(int i, float width);
int	get_curr_col(int i, float width);
int	check_submatrix(float *m_matrix, int row_rm, int col_rm);
float	cofactors(int row, int col);
//void	inverse_matrix_44(float *m_inverted, float *m_matrix);



//matrix_minors.c
//float	minor_33(float *m_matrix, int row, int col);
//float	minor_44(float *m_matrix, int row, int col);
//float	cofactors(int row, int col);
//void	matrix_cofactors_44NA(float *m_matrix, float *m_cofactors);


//matrix_submatrix.c
//float	*submatrix_44NA(float *m_matrix, float *m_submatrix, int row_to_rm, int col_to_rm);

//float	*submatrix(float *m_matrix, int row_to_remove, int col_to_remove);
//int		get_curr_row(int i, float width);
//int		get_curr_col(int i, float width);
//int		check_submatrix(float *m_matrix, int row_rm, int col_rm);

//test_inverting.c
//float	*inverted_matrix_44(float *m_matrix);
//float	*inverted_matrix_44_NA(float *m_matrix);
//void	matrix_cofactors_44(float *m_matrix, float *m_cofactors);
//void inverted_matrix_44_NA(float *m_inverted, float *m_matrix, float *m_submatrix);

////////////////!!!GPT
//int inverse4x4(float *src, float *dest);



#endif