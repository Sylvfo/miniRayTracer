/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:21:36 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/07 14:05:49 by cmegret          ###   ########.fr       */
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

#endif