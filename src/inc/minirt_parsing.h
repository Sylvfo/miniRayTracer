/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:21:19 by syl               #+#    #+#             */
/*   Updated: 2025/02/28 12:32:22 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

# include "minirt_data_struct.h"

// AUSSI CHECK 
// ET TERMINATE

/// SYLVIE
// avant parsingdsf
t_pix	***init_data_test(void);
t_pix	***init_pix_test(t_pix ***pix);
void	link_pix_ima(t_pix ***pix, t_image *ima);
//void	color_image(t_image *ima);

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
void	process_buffer(char *buf);
void	skip_whitespace(const char **str);

/* Validation utilities */
int		check_only_spaces(char *str);
int		validate_orientation_vector(float ox, float oy, float oz);
int		validate_fov(float fov);

#endif