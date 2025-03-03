/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:21:19 by syl               #+#    #+#             */
/*   Updated: 2025/03/03 17:43:01 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

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
//init_data.c
bool		init_data(t_pix ***pix, t_num_obj *num_obj);

/* Camera initialization */
t_camera	*init_camera(void);
//bool		init_pix(t_pix ***pix, int rows, int cols);
void		free_all(t_pix ***pix);
bool	init_pix(t_pix ****pix);
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

/* Parsing utilities */
void		free_all(t_pix ***pix);

/* Save functions */
void		save_line(char *line, t_pix ***pix, t_num_obj *num_obj);
void		save_light(char *line, t_pix ***pix, t_num_obj *num_obj);
void		save_camera(char *line, t_pix ***pix);
void		save_plane(char *line, t_pix ***pix, t_num_obj *num_obj);
void		save_sphere(char *line, t_pix ***pix, t_num_obj *num_obj);
void		save_cylinder(char *line, t_pix ***pix, t_num_obj *num_obj);

//init_image.c
t_image	*init_image(void);

//init_matrix_ima.c
bool		init_matrix_ref(t_pix ***pix);
void		link_pix_matrix(t_pix ***pix, t_matrix *neo);
bool		init_ima(t_pix ***pix);
void		link_pix_ima(t_pix ***pix, t_image *ima);

//init_scene.c
bool		init_scene(t_pix ***pix, t_num_obj *num_obj);
void	link_pix_scene(t_pix ***pix, t_camera *cam, t_obj ***obj, t_light ***lux);

#endif