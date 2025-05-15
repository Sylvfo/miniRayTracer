/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:02:20 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 22:08:32 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_ALL_H
# define FREE_ALL_H

# include "minirt_data_struct.h"

void	free_all(t_program_context *context);
void	free_matrix(float *matrix);
void	free_coord(t_coord *coord);
void	free_color(t_color *color);
void	free_ima(t_program_context *context);
void	free_obj(t_obj *obj);
void	free_obj_array(t_obj **objs);
void	free_comps(t_comps *comps);
void	free_hits(t_program_context *context);
void	free_light(t_light *light);
void	free_light_array(t_light **array, int count);
void	free_camera(t_camera *camera);
void	free_pix_viewport(t_pix *pix);
void	free_pix_components(t_pix *pix);
void	free_pix_content(t_pix *pix);
void	free_pix(t_pix ***pix, int rows, int cols);

#endif