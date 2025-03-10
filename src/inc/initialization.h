/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:21:36 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/10 15:47:23 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "minirt.h"
# include "minirt_data_struct.h"

t_pix		***init_pix(int rows, int cols);
t_pix		***init_data(t_num_obj *num_obj);
t_obj		***init_object(t_num_obj *num_obj);
void		free_object(t_obj ***obj, t_num_obj *num_obj);
t_camera	*init_camera(void);
void		free_light_memory(t_light ***light, int count);
t_light		**init_light_array(int count);
t_light		***allocate_light_arrays(t_num_obj *num_obj);
bool		init_ambient_light(t_light ***light);
bool		init_spotlights(t_light ***light, t_num_obj *num_obj);
t_light		***init_light(t_num_obj *num_obj);


//fonction sylvie
bool	init_matrix_ref(t_pix ***pix);
void		link_pix_matrix(t_pix ***pix, t_matrix *neo);
bool	init_ima(t_pix ***pix);
void	link_pix_ima(t_pix ***pix, t_image *ima);
void	assign_hits_to_pix(t_pix ***pix, t_hits ***hits, t_num_obj *num_obj);
t_hits ***init_hits(t_num_obj *num_obj);
#endif