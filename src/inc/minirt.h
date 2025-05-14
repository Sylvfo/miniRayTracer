/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/05/14 11:24:26 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../../lib/libft/libft.h"
//# include "../../lib/minilibx-linux/mlx_int.h"
# include "../../lib/minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "minirt_data_struct.h"
# include "minirt_matrix.h"
# include "free_all.h"
# include "parsing.h"
# include "initialization.h"
# include "saving.h"
# include "minirt_vect_point_color.h"
# include "minirt_ray_calculs.h"
# include "minirt_vect_point_color.h"
# include "minirt_window.h"

# define WND_WIDTH 1080
# define WND_HEIGHT 900

# define BAKGROUND_COLOR 12701914
# define EPSILON 0.001
# define PI 3.1415926535
# define PIRAD 0.017453
# define SHININESS 80.0

enum e_obj_type
{
	NONE,
	SPHERE,
	PLAN,
	CYLINDER,
};

enum e_axes
{
	axe_x,
	axe_y,
	axe_z,
	left_h,
	right_h,
};

int		main(int argc, char **argv);
void	error_exit(const char *msg, t_program_context *context);

/* ************************************************************************** */
/*                                                                            */
/*                              FREE                                          */
/*                                                                            */
/* ************************************************************************** */

void				free_all(t_program_context *context);

#endif