/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:06:16 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/12 10:18:13 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVING_H
# define SAVING_H

# include "minirt.h"

typedef struct s_cylinder_params
{
	t_coord	coord;
	t_coord	orientation;
	t_color	color;
	float	diameter;
	float	height;
}	t_cylinder_params;

// Ces fonctions prennent maintenant t_program_context *context
void	save_line(char *line, t_program_context *context);
void	process_line(char *buf, t_program_context *context);
void	save_scene_file(const char *filename, t_program_context *context);

// Signatures modifiées pour accepter t_program_context *context
void	save_light(char *line, t_program_context *context);
void	save_camera(char *line, t_program_context *context);
void	save_sphere(char *line, t_program_context *context);
void	save_plane(char *line, t_program_context *context);
void	save_cylinder(char *line, t_program_context *context);

#endif