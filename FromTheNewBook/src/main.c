/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:07 by sforster          #+#    #+#             */
/*   Updated: 2025/02/12 15:29:45 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

//Docstring

int main(void)
{
	t_pix ***pix;
	
	pix = init_data_test();
	pix_drawings(pix);
	pix_to_window(pix);
	image_hooks(pix[0][0]->ima);
//	terminate()
	return (0);
}