/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/03/12 15:21:57 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

//	s_coord p_exemplepoint;
//	s_coord v_exemplevector;
//	s_coord vn_exemplenormedvector;
//	s_color c_color;
//  float *m_matrix;
//	t_ray  *r_ray;

////////// DATAS //////////
//	row = m_matrix[0];
//	col = m_matrix[1];
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

typedef struct num_obj
{
	int		sphere;
	int		plan;
	int		cylinder;
	int		light;
}	t_num_obj;

typedef struct s_ray
{
	t_coord	*p_origin;
	t_coord	*v_dir;
//	t_coord	*v_norm;
}	t_ray;

////////// SCENE //////////
// object[0][0]->color = backgroud color
// object[1][0] spheres
// object[2][0] plans
// object[3][0] cylinder
typedef struct s_obj
{
	t_coord	*p_coord;
	t_color	*color;
	float	diam;
	float	height;
	t_coord	*v_axe;
	float	*m_identity;
	float	*m_tranf;// initialiser?? matrice de transformation. résultat de toutes les transformation. m_transf = Rotation * Transl * Scale
	float	*m_transl;
	float	*m_rot;
	float	*m_scale;
}	t_obj;

// mem array que obj
typedef struct s_hits
{
//	t_obj 		*obj;// necessaire?? On sait lequel c est avec [x][y]
	float		t1;
	float		t2;
	int	 		t_count;
}	t_hits;

// light[0][0] = ambiant light.
// light[1] = spotlight light.
// light[2] = other type of light (in bonus)
typedef struct s_light
{
	t_coord		*p_coord;
	float		ratio; //brightness
	t_color		*color;
}	t_light;

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
	struct t_camera	*saved_camera; // (si on se perd. ou camera origines)
//	float		caneva_width; // image
//	float		caneva_hight; // image
//	type de rendu. 
}	t_camera;

////////// ?? //////////
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;// ??
	int		line_length; // ??
	int		endian; // ?
	void	*mlx_ptr;
	void	*mlx_win;
	int		view_width;// wall??
	int		view_height; // wall??
	int		canva_height;
	int		canva_width;
	int     half_height;
	int		half_width;
	int		pixel_size;
}	t_image;

typedef struct s_matrix
{
	float	*m_rot_x;
	float	*m_rot_y;
	float	*m_rot_z;
	float	*m_transl;
	float	*m_identity;
}	t_matrix;

////////// CANVA //////////
typedef struct s_pix
{
	t_camera	*cam; // OK
	t_obj		***obj; // OK
	t_obj		***c_obj;//scene from camera a voir apres pour l instant sert à rien
	t_light		***lux; // OK
	t_image		*ima;
	t_matrix	*neo;
	t_coord		*p_origin_zero;
	//in each pixel. 
	int	vpx;// viewport x
	int vpy;// viewport y
	t_ray 		*r_ray; //ray pour les calculs. 
	t_ray		*r_original; // ray entre camera et coordonnes sur viewport
	t_color		*color; // OK
	t_obj		*closest_obj;
	//bon à voir si c est vraiment important vu que c est pour réflexion, réfraction et solid geom...
	t_hits		***hits; //array de hits  

	// 	data for calculation
	float		t1;
	float		t2;
	int			t_count;
}	t_pix;

#endif