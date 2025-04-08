/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:06:16 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/08 09:16:49 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVING_H
# define SAVING_H

# include "minirt.h"

void	save_line(char *line, t_pix ***pix, t_num_obj *num_obj);
void	process_line(char *buf, t_pix ***pix, t_num_obj *num_obj);
void	save_scene_file(const char *filename, t_pix ***pix, t_num_obj *num_obj);
void	save_light(char *line, t_pix **pix, t_num_obj *num_obj);
void	save_camera(char *line, t_pix **pix);
void	save_sphere(char *line, t_pix **pix, t_num_obj *num_obj);
void	save_plane(char *line, t_pix **pix, t_num_obj *num_obj);
void	save_cylinder(char *line, t_pix **pix, t_num_obj *num_obj);

#endif