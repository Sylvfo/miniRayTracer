/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/02/26 14:46:04 by syl              ###   ########.fr       */
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
# include "minirt_ray_calculs.h"
# include "minirt_vect_point_color.h"

// voir quelle taille....
# define EPSILON 0.001
# define PI 3.1415926535
# define PIRAD 0.017453   //pi already divided by 180 to find radian. 

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