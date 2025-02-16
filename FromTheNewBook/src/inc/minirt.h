/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/02/16 13:37:05 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include "librairies/libft/libft.h"
//# include <mlx.h>
# include "../../lib/minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "minirt_data_struct.h"
# include "minirt_tests.h"

// voir quelle taille....
#define EPSILON 0.001

//create_point_vector.c
t_coord *create_vector(float x, float y, float z);
t_coord *create_point(float x, float y, float z);

//utils_print.c
void print_vector(t_coord *v_vector);
void print_point(t_coord *p_point);

////////////MATH/////////////

// check_type_coord.c
bool is_vector(t_coord *v_vector);
bool is_point(t_coord *p_point);

// add_substr.c
t_coord *addition(t_coord *p_v_1, t_coord *p_v_2);
t_coord *substraction(t_coord *p_v_1, t_coord *p_v_2);

//vector_operations_length.c
t_coord *scalar_mult(t_coord *v_1, float scale);
float	length_vector(t_coord *v_1);
t_coord *normalize_vector(t_coord *v_1);

//vector_operations.c
t_coord *negat(t_coord *v_1); 
float dot_product(t_coord *v_1, t_coord *v_2);
t_coord *cross_product(t_coord *v_1, t_coord *v_2);

///////// MATRIX ////////////

//matrix_print.c
void print_matrix(float **m_matrix, unsigned int row, unsigned int col);

//matrix_creation2.c
float *create_matrix2(unsigned int row, unsigned int col);
void	init_matrix_zero2(float *m_matrix);
void print_matrix2(float *m_matrix);
void matrix_fill2(float *m_matrix, int row, int col, float number);

//matrix_comparison.c
bool	matrix_comparision(float *m_a, float *m_b);

//matrix_operations.c
float *matrix_multiplication_44(float *m_a, float *m_b);
bool	check_matrix_44_44(float *m_a, float *m_b);

//matrix_mult_matrix_p_v.c
t_coord *matrix_multiplication_44_coord(float *m_a, t_coord *p_v_1);
bool	check_matrix_44_coord(float *m_a, t_coord *p_v_1);
void	matrix_from_coord(t_coord *p_v_1, float coord[4]);
void fill_point_vector(t_coord *new_point_vector, int count, float sum);

//matrix_identity.c
float *create_indentity_matrix_44(void);

//matrix_testing.c
bool test_multiplication(void);
void test_multiplication2(void);
void test_multiplication3(void);

//matrix_transposing.c
void	transposing_matrix_44(float *m_matrix);
void	copy_matrix_44_stack(float *m_matrix, float *m_tmp);

//matrix_check.c
bool	check_matrix_44(float *m_a);

//matrix_inverting.c
float determinant_22(float *m_22);

//test_inverting.c
void test_inverting(void);


///////// COLORS ////////////

//set_colors.c
t_color *create_color(int r, int g, int b);
static float int_to_float(int value);
void    color_float_to_int(t_color *c_color);
static int	float_to_byte(float f);
void	change_color(t_color *c_color, int r, int g, int b);

//color_operations.c
void	addition_color(t_color *c_1, t_color *c_2);
t_color *substraction_color(t_color *c_1, t_color *c_2);
void 	scalar_mult_color(t_color *c_1, float scale) ;
void	multipling_color(t_color *c_1, t_color *c_2);

// avant parsingdsf
t_pix ***init_data_test(void);
t_pix ***init_pix_test(t_pix ***pix);
void	link_pix_ima(t_pix ***pix, t_image *ima);
//void	color_image(t_image *ima);
void	pix_to_window(t_pix ***pix);

//////// DRAWINGS ////////////
void	pix_drawings(t_pix ***pix);
void color_pixels2(t_pix ***pix);
void	color_pixels(t_pix ***pix);
void color_pixels3(t_pix ***pix);

///////// EXERCICES BOOK ////////////
void projectile(t_pix ***pix);


/////// IMAGE /////////

//event_hooks
void	image_hooks(t_image *ima);
int		ft_keys(int keycode, t_image *ima);
int		ft_exit(t_image *ima);

//init_image.c
t_image *init_image(void);
void	my_mlx_pixel_put(t_image *ima, int x, int y, int color);

/////// TERMINATE /////////
void	free_matrix_44(float **m_matrix);
void	free_matrix_33(float **m_matrix);
void	free_matrix_22(float **m_matrix);
//void	free_matrix(float **m_matrix);

#endif