/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:29:59 by syl               #+#    #+#             */
/*   Updated: 2025/03/10 10:28:03 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//GOOD
void test_ray(void)
{
	t_coord *p_point;
	t_coord *v_vect;
	t_ray *r_ray;
	t_coord *p_result;

	p_point = create_point(2, 3, 4);
	v_vect = create_vector(1, 0, 0);
	r_ray = create_ray(p_point, v_vect);
	p_result = position(r_ray, 0);
	printf("\n 0 gives ");
	print_point(p_result);

	p_result = position(r_ray, 1);
	printf("\n 1 gives ");
	print_point(p_result);

	p_result = position(r_ray, -1);
	printf("\n -1 gives ");
	print_point(p_result);

	p_result = position(r_ray, 2.5);
	printf("\n 2.5 gives ");
	print_point(p_result);
}

void	test_sphere(t_pix ***pix)
{
	int x = 0;
	int y = 0;
	//create ray
	t_coord *p_camera;
	t_coord *v_vect;
	p_camera = create_point(0, 0, -5);//camera
	v_vect = create_vector(1, 0, 0);// entre camera et point
	pix[x][y]->r_ray = create_ray(p_camera, v_vect);

	intersect_sphere(pix[x][y], 0);

	printf("t1 is %.2f \n", pix[0][0]->t1);
	printf("t2 is %.2f \n", pix[0][0]->t2);
}