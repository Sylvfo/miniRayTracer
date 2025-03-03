/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/02/28 13:45:14 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

// not to interract with the last object touched. no neg value. 1 is for safety
# define RAY_T_MIN 0.0001f
// really large floating number. 1.0 × 10³⁰ (10 puiss 30) 1 suivi de 30 zeros
// pk zero???
# define RAY_T_MAX 0.0e30f 

//	s_coord p_exemplepoint;
//	s_coord v_exemplevector;
//	s_coord vn_exemplenormedvector;
//	s_color c_color;
//  float *m_matrix;
//	t_ray  *r_ray;

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
	int		t;// type 0 for vector and 1 for point.
}	t_coord;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
	int		rgb;
}	t_color;

typedef struct s_ray
{
	t_coord	*p_origin;
	t_coord	*v_dir;
	t_coord	*v_norm;
}	t_ray;

/// OBJETS
// 2d array of pointers
// object[0][0]->color = backgroud color
// so if no object, it does point on something and we can have 
//a view with nothing. MANDATORY??
// or if we remove all objects. 
// object[1][0] spheres
// object[2][0] plans
// object[3][0] cylinder...*/
typedef struct s_obj
{
	t_coord	*p_coord;
	t_color	*color;
	float	diam;
	float	height;
	t_coord	*v_axe;
}	t_obj;

/// LIGHTS
//2d array of pointers.  
// light[0][0] = ambiant light.
// light[1] = spotlight light.
// light[2] = other type of light (in bonus)
typedef struct s_light
{
	t_coord		*p_coord;
	float		ratio; //brightness
	t_color		*color;
}	t_light;

typedef struct num_obj
{
	int		sphere;
	int		plan;
	int		cylinder;
	int		light;
}	t_num_obj;

typedef struct s_camera
{
	t_coord		*p_coord;
	t_coord		*v_axe;
	float		fov;
	//a voir
	t_coord		vn_axe_x;
	t_coord		vn_axe_y;
	t_coord		vn_axe_z;
//	float		viewport_width; // viewport L1
//	float		viewport_height; // L2
	t_coord		v_origin_camera; // m dans pixel
	// distance viewport camera???
	t_camera	*saved_camera; // (si on se perd. ou camera origines)
	float		caneva_width; // image
	float		caneva_hight; // image
}	t_camera;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;// ??
	int		line_length; // ??
	int		endian; // ?
	void	*mlx_ptr;
	void	*mlx_win;
}	t_image;

typedef struct s_matrix
{
	float	*m_rot_x;
	float	*m_rot_y;
	float	*m_rot_z;
	float	*m_transl;
	float	*m_identidy;
}	t_matrix;

typedef struct s_pix
{
	//same for all
	t_camera	*cam;
	t_obj		***obj;
	t_obj		***c_obj;//scene from camera
	t_light		***lux;
	t_image		*ima;
	t_matrix	*neo;

	//in each pixel. 
	t_coord		*v_d; // vecteur entre camera et coordonnes sur viewport
	t_color		*color;
	t_obj		*closest_obj;
// closest object
// 	data for calculation	
	float		t1;
	float		t2;
}	t_pix;

#endif