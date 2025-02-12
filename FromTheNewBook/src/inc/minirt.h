/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/02/12 10:32:51 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include "librairies/libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "minirt_data_struct.h"

//create_point_vector.c
t_coord *create_vector(float x, float y, float z);
t_coord *create_point(float x, float y, float z);

//utils_print.c
void print_vector(t_coord *v_vector);
void print_point(t_coord *p_point);

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

#endif