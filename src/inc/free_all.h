/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:02:20 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/11 15:39:45 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_ALL_H
# define FREE_ALL_H

# include "minirt_data_struct.h"

// Libère une structure t_obj et tous ses champs dynamiquement alloués.
void	free_obj(t_obj *obj);
// Libère une structure t_light et tous ses champs dynamiquement alloués.
void	free_light(t_light *light);
// Libère une structure t_camera et tous ses champs dynamiquement alloués.
void	free_camera(t_camera *cam);
// Libère un tableau d'objets
void	free_obj_tab(t_obj ***obj, int nb_type, int *nb_obj);
// Libère un tableau de lumières
void	free_light_tab(t_light ***lux, int nb_type, int *nb_lux);
// Libère un tableau de hits
void	free_hits_tab(t_hits ***hits, int nb_type, int *nb_hits);
// Libère une structure comps
void	free_comps(t_comps *comps);
// Libère une image
void	free_image(t_image *ima);
// Libère une caméra (récursif sur saved_camera)
void	free_camera(t_camera *cam);
// Libère tous les pixels et leurs sous-éléments
void	free_pix(t_pix ***pix, int x, int y, t_num_obj *num_obj);
// Fonction principale pour tout libérer
void	free_all(t_pix ***pix, int x, int y, t_num_obj *num_obj);

#endif