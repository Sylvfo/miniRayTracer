/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_vect_point_color.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:15:23 by syl               #+#    #+#             */
/*   Updated: 2025/04/23 11:51:39 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_VECT_POINT_COLOR_H
# define MINIRT_VECT_POINT_COLOR_H

# include "minirt_data_struct.h"

//create_point_vector.c
t_coord	*create_vector(float x, float y, float z);
t_coord	*create_point(float x, float y, float z);

//utils_print.c
void	print_vector(t_coord *v_vector);
void	print_point(t_coord *p_point);

// check_type_coord.c
bool	is_vector(t_coord *v_vector);
bool	is_point(t_coord *p_point);

////////////MATH/////////////
// add_substr.c
t_coord	*addition(t_coord *p_v_1, t_coord *p_v_2);
void addition_NA(t_coord *result, t_coord *p_v_1, t_coord *p_v_2);
t_coord	*substraction(t_coord *p_v_1, t_coord *p_v_2);
void substraction_p_to_v_NA(t_coord *v_result, t_coord *p_v_1, t_coord *p_v_2);

//vector_operations_length.c
t_coord	*scalar_mult(t_coord *v_1, float scale);
void	scalar_mult_NA(t_coord *result, t_coord *v_1, float scale);
float	length_vector(t_coord *v_1);
t_coord	*normalize_vector(t_coord *v_1);
void	normalize_vector_NA(t_coord *v_1);

//vector_operations.c
t_coord	*negat(t_coord *v_1);
void negat_NA(t_coord *result, t_coord *old);
float	dot_product(t_coord *v_1, t_coord *v_2);
t_coord	*cross_product(t_coord *v_1, t_coord *v_2);

///////// COLORS ////////////
//set_colors.c
t_color	*create_color(int r, int g, int b);
float	int_to_float(int value);
void	color_float_to_int(t_color *c_color);
int		float_to_byte(float f);
void	change_color(t_color *c_color, int r, int g, int b);
void	color_int_to_rgb(int int_color, t_color *rgb);

//color_operations.c
void	addition_color(t_color *c_1, t_color *c_2);
t_color	*substraction_color(t_color *c_1, t_color *c_2);
void	scalar_mult_color(t_color *c_1, float scale);
void	multipling_color(t_color *c_1, t_color *c_2);

//copy_coord.c
void copy_coord(t_coord *new, t_coord *origin);
void copy_color(t_color *new, t_color *origin);
void vector_fill(t_coord *vect, float x, float y, float z);

//math.c
float	simple_sqrt(float x);

#endif

