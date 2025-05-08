/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_vect_point_color.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:15:23 by syl               #+#    #+#             */
/*   Updated: 2025/05/08 10:56:47 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_VECT_POINT_COLOR_H
# define MINIRT_VECT_POINT_COLOR_H

# include "minirt_data_struct.h"

// add_substr.c
void	substraction_p_to_v_NA(t_coord *v_result, t_coord *p_v_1, t_coord *p_v_2);
void	addition_NA(t_coord *result, t_coord *p_v_1, t_coord *p_v_2);

// check_type_coord.c
bool	is_vector(t_coord *v_vector);
bool	is_point(t_coord *p_point);

//create_point_vector.c
t_coord	*create_vector(float x, float y, float z);
t_coord	*create_point(float x, float y, float z);

//utils_print.c
void	print_vector(t_coord *v_vector);
void	print_point(t_coord *p_point);

//vector_operations.c
void	negat_NA(t_coord *result, t_coord *old);
float	dot_product(t_coord *v_1, t_coord *v_2);
void	cross_product_NA(t_coord *result, t_coord *v_1, t_coord *v_2);
void	position_NA(t_pix *pix, t_coord *r_dir, float t);

//vector_operations_length.c
void	scalar_mult_NA(t_coord *result, t_coord *v_1, float scale);
float	length_vector(t_coord *v_1);
void	normalize_vector_NA(t_coord *v_1);

//math.c
float	simple_sqrt(float x);

//copy_coord.c
void	copy_coord(t_coord *new, t_coord *origin);
void	copy_color(t_color *new, t_color *origin);
void	vector_fill(t_coord *vect, float x, float y, float z);

//color_operation.c
void	scalar_mult_color(t_color *c_1, float scale);
float	int_to_float(int value);
void	color_float_to_int(t_color *c_color);
int		float_to_byte(float f);
void	color_int_to_rgb(int int_color, t_color *rgb);

//set_colors.c
t_color	*create_color(int r, int g, int b);
void	change_color(t_color *c_color, int r, int g, int b);

#endif

