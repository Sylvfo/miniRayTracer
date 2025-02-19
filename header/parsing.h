/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/02/19 14:08:07 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

/* Scene parsing */
void	parse_scene_file(const char *filename);
void	parse_line(char *line);

/* Object parsing */
int		validate_sphere(char *line);
int		validate_plane(char *line);
int		validate_cylinder(char *line);

/* Camera parsing */
int		validate_camera(char *line);

/* Lighting parsing */
int		validate_light(char *line);
int		validate_ambient(char *line);

/* Parsing utilities */
int		parse_coordinates(char **line, float *x, float *y, float *z);
int		parse_color(char **line, int *r, int *g, int *b);
int		parse_dimension(char **line, float *dimension);
int		parse_float(char **line, float *value);

/* Validation utilities */
int		check_only_spaces(char *str);
int		validate_orientation_vector(float ox, float oy, float oz);
int		validate_fov(float fov);
void	error_exit(const char *msg);

#endif
