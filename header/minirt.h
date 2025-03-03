/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/03/02 19:20:00 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include "../lib/minilibx-linux/mlx_int.h"
# include "../lib/libft/libft.h"
# include "minirt_data_struct.h"
# include "parsing.h"

# define EPSILON 0.001
# define PI 3.1415926535
# define PIRAD 0.017453   //pi already divided by 180 to find radian. 

# define WND_WIDTH 1800
# define WND_HEIGHT 1000
# define VIEWP_WIDTH 1800
# define VIEWP_HIGHT 1000

int	main(int argc, char **argv);

#endif