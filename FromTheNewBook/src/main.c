/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:07 by sforster          #+#    #+#             */
/*   Updated: 2025/02/07 22:17:12 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

//Docstring

int main(void)
{
///	t_pix ***pix;
	t_coord *v_vector;

//	check_file
//	pix = parsing();

	v_vector = create_vector(5, 12, 3);
	print_vector(v_vector);
	free(v_vector);
//	terminate()
	return (0);
}