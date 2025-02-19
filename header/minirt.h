/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/02/19 08:54:08 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/minilibx-linux/mlx_int.h"
# include "../lib/libft/libft.h"
# include <math.h>

# include "minirt_data_struct.h"

int		main(int argc, char **argv);
void	parse_scene_file(const char *filename);
int		validate_ambient(char *line);
int		validate_light(char *line);
int		validate_camera(char *line);
int		check_only_spaces(char *str);
int		parse_coordinates(char **line, float *x, float *y, float *z);
int		parse_color(char **line, int *r, int *g, int *b);
int		validate_sphere(char *line);
int		validate_plane(char *line);
int		validate_cylinder(char *line);

#endif