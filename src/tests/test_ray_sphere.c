/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ray_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:29:59 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 12:22:38 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void	test_translation(void)
{
	t_ray *ray;
	t_coord *p_point;
	t_coord *v_vect;
	t_ray *new;

	p_point = create_point(1, 2, 3);
	v_vect = create_vector(0, 1, 0);
	ray = create_ray(p_point, v_vect);
	translation
	
}*/
/*
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
}*/
/*
//OK GOOD
void	test_sphere(t_pix ***pix)
{
	int x = 0;
	int y = 0;
	//create ray
	t_coord *p_camera;
	t_coord *v_vect;

	//testp 59 YES
	p_camera = create_point(0, 0, -5);//camera
	v_vect = create_vector(0, 0, 1);// entre camera et point
	pix[x][y]->r_ray = create_ray(p_camera, v_vect);
	intersect_sphere(pix[x][y], 0);
	printf("p 59 t1 is %.2f ", pix[0][0]->t1);
	printf("t2 is %.2f  tcount %i \n", pix[0][0]->t2, pix[0][0]->t_count);

	//teste p 60.1 YES
	p_camera = create_point(0, 1, -5);//camera
	v_vect = create_vector(0, 0, 1);// entre camera et point
	pix[x][y]->r_ray = create_ray(p_camera, v_vect);
	intersect_sphere(pix[x][y], 0);
	printf("p 60.1 t1 is %.2f ", pix[0][0]->t1);
	printf("t2 is %.2f  tcount %i \n", pix[0][0]->t2, pix[0][0]->t_count);

	//teste p 60.2 YES
	p_camera = create_point(0, 2, -5);//camera
	v_vect = create_vector(0, 0, 1);// entre camera et point
	pix[x][y]->r_ray = create_ray(p_camera, v_vect);
	intersect_sphere(pix[x][y], 0);
	printf("p 60.2 t1 is %.2f ", pix[0][0]->t1);
	printf("t2 is %.2f  tcount %i \n", pix[0][0]->t2, pix[0][0]->t_count);

	//teste p 61 YES
	p_camera = create_point(0, 0, 0);//camera
	v_vect = create_vector(0, 0, 1);// entre camera et point
	pix[x][y]->r_ray = create_ray(p_camera, v_vect);
	intersect_sphere(pix[x][y], 0);
	printf("p 61 t1 is %.2f ", pix[0][0]->t1);
	printf("t2 is %.2f  tcount %i \n", pix[0][0]->t2, pix[0][0]->t_count);

	//teste p 62 YES
	p_camera = create_point(0, 0, 5);//camera
	v_vect = create_vector(0, 0, 1);// entre camera et point
	pix[x][y]->r_ray = create_ray(p_camera, v_vect);
	intersect_sphere(pix[x][y], 0);
	printf("p 62 t1 is %.2f ", pix[0][0]->t1);
	printf("t2 is %.2f  tcount %i \n", pix[0][0]->t2, pix[0][0]->t_count);

}*/


//OK GOOD
/* void test_normal_at(t_pix ***pix)
{
	t_coord *p_point;
	t_coord *result;

	p_point = create_point(1, 0, 0);
	result = normal_at(pix[0][0]->obj[1][0], p_point);
	printf("\n test 1 : ");
	print_vector(result);


	p_point->x = 0;
	p_point->y = 1;
	p_point->z = 0;
	result = normal_at(pix[0][0]->obj[1][0], p_point);
	printf("\n test 2 : ");
	print_vector(result);	

	
	p_point->x = 0;
	p_point->y = 0;
	p_point->z = 1;
	result = normal_at(pix[0][0]->obj[1][0], p_point);
	printf("\n test 3 : ");
	print_vector(result);	


	
	p_point->x = 0.577350269;
	p_point->y = 0.577350269;
	p_point->z = 0.577350269;
	result = normal_at(pix[0][0]->obj[1][0], p_point);
	printf("\n test 4 : ");
	print_vector(result);	
} */

/*
void ray_testing()
{
	t_coord *p_origin;
	t_coord *v_vect;
	t_ray	*r_test;
	t_coord	*p_result;

	printf("in testing\n");

	p_origin = create_point(2, 3, 4);
	is_point(p_origin);
	v_vect = create_vector(1, 0, 0);

	r_test = create_ray(p_origin, v_vect);
	(void) r_test;
	
	
	printf("in testing2\n");
	r_test = create_ray(p_origin, v_vect);
	p_result = position(r_test, 0);
	printf("0 : ");
	print_point(p_result);
	printf("\n 1 : ");
	p_result = position(r_test, 1);
	print_point(p_result); 
	printf("\n -1 : ");
	p_result = position(r_test, -1);
	print_point(p_result);
	printf("\n 2.5 : ");
	p_result = position(r_test, 2.5);
	print_point(p_result);
	printf("\n");
}*/