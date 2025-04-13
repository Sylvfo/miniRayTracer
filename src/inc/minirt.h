/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/04/13 17:07:51 by syl              ###   ########.fr       */
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
# include "parsing.h"
# include "initialization.h"
# include "saving.h"
# include "minirt_tests.h"
# include "minirt_matrix.h"
# include "minirt_window.h"
# include "minirt_ray_calculs.h"
# include "minirt_vect_point_color.h"

//a effacer
#include <sys/time.h>

// voir quelle taille....
# define EPSILON 0.001
# define PI 3.1415926535
# define PIRAD 0.017453   //pi already divided by 180 to find radian. 

# define WND_WIDTH 300
# define WND_HEIGHT 300
//# define VIEWP_WIDTH 1800 //dplacé dans ima
//# define VIEWP_HIGHT 1000 // déplace dans ima
# define BAKGROUND_COLOR 11152468 //11152468
# define DIST_VIEWP_ORIGIN 10 //Normalement c est 1 ou -1

// not to interract with the last object touched. no neg value. 1 is for safety
# define RAY_T_MIN 0.0001f
// really large floating number. 1.0 × 10³⁰ (10 puiss 30) 1 suivi de 30 zeros
// pk zero???
# define RAY_T_MAX 0.0e30f 

# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define RESET  "\033[0m"
# define GREEN1 "\033[0;32m"   // Vert normal
# define GREEN2 "\033[1;32m"   // Vert clair
# define GREEN3 "\033[0;92m"   // Vert brillant
# define GREEN4 "\033[0;36m"   // Cyan-vert

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
void	error_exit(const char *msg);

#endif