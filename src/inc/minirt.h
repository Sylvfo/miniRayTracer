/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/02/17 16:48:57 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include "librairies/libft/libft.h"
//# include "../../lib/minilibx-linux/mlx_int.h"
# include "../../lib/minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "minirt_data_struct.h"
# include "minirt_tests.h"
# include "minirt_matrix.h"
# include "minirt_window.h"
# include "minirt_parsing.h"

// voir quelle taille....
# define EPSILON 0.001

# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define RESET  "\033[0m"
# define GREEN1 "\033[0;32m"   // Vert normal
# define GREEN2 "\033[1;32m"   // Vert clair
# define GREEN3 "\033[0;92m"   // Vert brillant
# define GREEN4 "\033[0;36m"   // Cyan-vert

//create_point_vector.c
t_coord	*create_vector(float x, float y, float z);
t_coord	*create_point(float x, float y, float z);

//utils_print.c
void	print_vector(t_coord *v_vector);
void	print_point(t_coord *p_point);

////////////MATH/////////////
// check_type_coord.c
bool	is_vector(t_coord *v_vector);
bool	is_point(t_coord *p_point);

// add_substr.c
t_coord	*addition(t_coord *p_v_1, t_coord *p_v_2);
t_coord	*substraction(t_coord *p_v_1, t_coord *p_v_2);

//vector_operations_length.c
t_coord	*scalar_mult(t_coord *v_1, float scale);
float	length_vector(t_coord *v_1);
t_coord	*normalize_vector(t_coord *v_1);

//vector_operations.c
t_coord	*negat(t_coord *v_1);
float	dot_product(t_coord *v_1, t_coord *v_2);
t_coord	*cross_product(t_coord *v_1, t_coord *v_2);

///////// COLORS ////////////
//set_colors.c
t_color	*create_color(int r, int g, int b);
float	int_to_float(int value);
void	color_float_to_int(t_color *c_color);
int		float_to_byte(float f);
void	change_color(t_color *c_color, int r, int g, int b);

//color_operations.c
void	addition_color(t_color *c_1, t_color *c_2);
t_color	*substraction_color(t_color *c_1, t_color *c_2);
void	scalar_mult_color(t_color *c_1, float scale);
void	multipling_color(t_color *c_1, t_color *c_2);

/////// TERMINATE /////////

#endif