/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:12:13 by sforster          #+#    #+#             */
/*   Updated: 2025/05/07 17:28:24 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TESTS_H
# define MINIRT_TESTS_H

///////// EXERCICES BOOK ////////////
void	projectile(t_pix ***pix);

//matrix_testing.c
bool	test_multiplication(void);
void	test_multiplication2(void);
void	test_multiplication3(void);
void	test_submatrix(void);
void	test_minor_33(void);
void	test_determinant_33(void);
void	test_invert_44(void);
void	test_mult_product_inverse(void);

//matrix_transf_testing.c
void	test_transformation(void);
void	test_scaling(void);

//ray_test.c 
void	ray_testing();
void	sphere_testing();
void	test_ray(void);
void	test_sphere(t_pix ***pix);
void	test_normal_at(void);

//camera
void	test_camera3(void);
void	test_camera2(t_pix ***pix);
void	test_camera(t_pix ***pix);

#endif