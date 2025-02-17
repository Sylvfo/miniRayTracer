/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:21:19 by syl               #+#    #+#             */
/*   Updated: 2025/02/17 16:29:52 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_PARSING_H
# define MINIRT_PARSING_H

# include "minirt_data_struct.h"

// avant parsingdsf
t_pix	***init_data_test(void);
t_pix	***init_pix_test(t_pix ***pix);
void	link_pix_ima(t_pix ***pix, t_image *ima);
//void	color_image(t_image *ima);

#endif