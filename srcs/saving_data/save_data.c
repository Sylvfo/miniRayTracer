/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:56:15 by cmegret           #+#    #+#             */
/*   Updated: 2025/03/02 21:53:44 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minirt.h"

void	save_line(char *line, t_pix ***pix, t_num_obj *num_obj)
{
	if (line[0] == 'A' || line[0] == 'L')
		save_light(line, pix, num_obj);
	else if (line[0] == 'C')
		save_camera(line, pix);
	else if (line[0] == 's' && line[1] == 'p')
		save_object(line, pix, num_obj);
	else if (line[0] == 'p' && line[1] == 'l')
		save_object(line, pix, num_obj);
	else if (line[0] == 'c' && line[1] == 'y')
		save_object(line, pix, num_obj);
}
