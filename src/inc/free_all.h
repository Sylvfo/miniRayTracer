/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:02:20 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/14 12:02:40 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_ALL_H
# define FREE_ALL_H

# include "minirt_data_struct.h"

// Declaration for free_pix, used in init_data.c for cleanup
void free_pix(t_pix ***pix_matrix, int allocated_rows, int num_cols, t_num_obj *num_obj);

#endif