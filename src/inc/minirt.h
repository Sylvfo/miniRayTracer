/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/04/21 17:07:24 by cmegret          ###   ########.fr       */
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
# include "free_all.h"
# include "parsing.h"

# define WND_WIDTH 1920
# define WND_HEIGHT 1080


int		main(int argc, char **argv);
void	error_exit(const char *msg, t_pix ***pix, t_num_obj *num_obj);

#endif