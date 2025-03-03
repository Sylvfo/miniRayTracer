/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/03/03 13:12:45 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

/* Scene parsing */
void		parse_scene_file(const char *filename, t_pix ***pix,
				t_num_obj *num_obj, const char *type);
void		parse_line(char *line, t_num_obj *num_obj);
void		process_buffer(char *buf, t_num_obj *num_obj, const char *type,
				t_pix ***pix);

/* Object parsing */
int			validate_sphere(char *line, t_num_obj *num_obj);
int			validate_plane(char *line, t_num_obj *num_obj);
int			validate_cylinder(char *line, t_num_obj *num_obj);

/* Camera parsing */
int			validate_camera(char *line);

/* Lighting parsing */
int			validate_light(char *line, t_num_obj *num_obj);
int			validate_ambient(char *line);

/* Parsing utilities */
int			parse_coordinates(char **line, float *x, float *y, float *z);
int			parse_color(char **line, float *r, float *g, float *b);
int			parse_dimension(char **line, float *dimension);
int			parse_float(char **line, float *value);
void		skip_whitespace(const char **str);

/* Validation utilities */
int			check_only_spaces(char *str);
int			validate_orientation_vector(float ox, float oy, float oz);
int			validate_fov(float fov);
void		error_exit(const char *msg);

/* Data initialization */
bool		init_data(t_pix ***pix, t_num_obj *num_obj);

/* Camera initialization */
t_camera	*init_camera(void);

/* Object initialization */
void		free_obj_memory(t_obj ***obj, int count);
t_obj		**init_object_array(int count);
t_obj		***allocate_obj_arrays(t_num_obj *num_obj);
t_obj		***init_obj(t_num_obj *num_obj);

/* Light initialization */
void		free_light_memory(t_light ***light, int count);
t_light		**init_light_array(int count);
t_light		***allocate_light_arrays(t_num_obj *num_obj);
t_light		***init_light(t_num_obj *num_obj);

void		free_all(t_pix ***pix);

void		save_line(char *line, t_pix ***pix, t_num_obj *num_obj);
void		save_light(char *line, t_pix ***pix, t_num_obj *num_obj);
void		save_camera(char *line, t_pix ***pix);
void		save_plane(char *line, t_pix ***pix, t_num_obj *num_obj);
void		save_sphere(char *line, t_pix ***pix, t_num_obj *num_obj);
void		save_cylinder(char *line, t_pix ***pix, t_num_obj *num_obj);

#endif
