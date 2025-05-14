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

void	free_coord(t_coord *coord);
void	free_color(t_color *color);
void	free_comp(t_comps *comps);
void	free_obj(t_obj *obj);
void	free_obj_2d(t_obj ***obj);
void	free_hits(t_hits *hit);
void	free_hits_table(t_pix ***pix);
void	free_image(t_image *ima);
void	free_mlx(void *mlx_ptr, void *mlx_win);
void 	free_camera(t_camera *cam);
void	free_lux(t_light **lux);
void	free_comps(t_pix ***pix);
void	free_pixel(t_pix ***pix);
void	free_all(t_program_context *context);

#endif