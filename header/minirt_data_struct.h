/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/02/19 13:53:20 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

# define RAY_T_MIN 0.0001f // not to interract with the last object touched. no neg value. 1 is for safety
# define RAY_T_MAX 0.0e30f // really large floating number. So it means 1.0 × 10³⁰ (10 puissance 30) 1 suivi de 30 zeros

//	s_coord p_exemplepoint;
//	s_coord v_exemplevector;
//	s_coord vn_exemplenormedvector;
typedef	struct s_coord {
	float x;
	float y;
	float z;
	int	t;// type 0 for vector and 1 for point.
}	t_coord;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;


//////////////////////
/// OBJETS
// 2d array of pointers
// object[0][0]->color = backgroud color
// so if no object, it does point on something and we can have a view with nothing. MANDATORY??
// or if we remove all objects. 
// object[1][0] spheres
// object[2][0] plans
// object[3][0] cylinder...

//info sur nombre objets de chaque type...
/*
typedef struct s_objet 
{
	type
	dimaetre...
}*/

typedef struct	s_sphere {
	t_coord		*center;
	int			radius;
	int			color;
}	t_sphere;

//plan
typedef struct	s_plane {
	t_coord		*point;
	t_coord		*normal; // normal, so 90° from the point
	int			color;
}	t_plane;

//cylindre
typedef struct	s_cyl {
	t_coord		*center;
	t_coord		*axis;
	int			height;
	int			diam;
	int			color;
}	t_cyl;

///////////////////////////
/// LIGHTS
//2d array of pointers.  
// light[0][0] = ambiant light.
// light[1] = spotlight light.
// light[2] = other type of light (in bonus)
typedef struct s_spotlight { //bulb??
	t_coord		*coord;
	float		ratio;
//	int			color;	not in mandatory part
} t_spotlight;

typedef struct s_camera {
	t_coord		vn_axe_x;
	t_coord		vn_axe_y;
	t_coord		vn_axe_z;
	float		viewport_width; // viewport L1
	float		viewport_height; // L2

	t_coord		v_origin_camera; // m dans pixel
	// distance viewport camera???
	float		center;// ???
	struct t_camera	*saved_camera; // (si on se perd. ou camera origines)
	float		caneva_width; // image
	float		caneva_hight; // image
}	t_camera;

// 1 data struct
typedef struct s_image {
	void			*img;
	char			*addr;
	int				bits_per_pixel;// ??
	int				line_length; // ??
	int				endian; // ?
	void			*mlx_ptr;
	void			*mlx_win;
}	t_image;

// 2Darray of pointers
typedef struct	s_pix {
	//same for all
	t_camera	*camera;
	t_image		*img;
//	t_objects	***scene;
//	t_lights	***lux;


	//in each pixel. 
	t_coord		*D; // vecteur entre camera et coordonnes sur viewport
	int			color;
// closest object

// 	data for calculation	
	float		t1;
	float		t2;
//...
}	t_pix;

#endif