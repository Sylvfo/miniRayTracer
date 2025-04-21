/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/04/21 17:10:58 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

/* Parse Utils */

void	skip_whitespace(const char **str);
int		parse_float(char **line, float *value);
int		parse_coordinates(char **line, float *x, float *y, float *z);
int		parse_color(char **line, float *r, float *g, float *b);
int		parse_dimension(char **line, float *dimension);
int		check_only_spaces(char *str);
int		validate_orientation_vector(float ox, float oy, float oz);
int		validate_fov(float fov);

/* Parsing */
void	parse_scene_file(const char *filename, t_pix ***pix, t_num_obj *num_obj);
void	process_buffer(char *buf, t_pix ***pix, t_num_obj *num_obj);
int		validate_ambient(char *line);
int		validate_light(char *line, t_num_obj *num_obj);
int		validate_camera(char *line);
int		validate_plane(char *line, t_num_obj *num_obj);
int		validate_cylinder(char *line, t_num_obj *num_obj);
int		validate_sphere(char *line, t_num_obj *num_obj);

#endif