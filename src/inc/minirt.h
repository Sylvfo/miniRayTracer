/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/03/03 17:35:34 by sforster         ###   ########.fr       */
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
# include "minirt_tests.h"
# include "minirt_matrix.h"
# include "minirt_window.h"
# include "minirt_parsing.h"
# include "minirt_ray_calculs.h"
# include "minirt_vect_point_color.h"

// voir quelle taille....
# define EPSILON 0.001
# define PI 3.1415926535
# define PIRAD 0.017453   //pi already divided by 180 to find radian. 

# define WND_WIDTH 1000
# define WND_HEIGHT 1000
# define VIEWP_WIDTH 1800
# define VIEWP_HIGHT 1000

# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define RESET  "\033[0m"
# define GREEN1 "\033[0;32m"   // Vert normal
# define GREEN2 "\033[1;32m"   // Vert clair
# define GREEN3 "\033[0;92m"   // Vert brillant
# define GREEN4 "\033[0;36m"   // Cyan-vert

enum e_axes
{
	axe_x,
	axe_y,
	axe_z,
	left_h,
	right_h,
};

#endif