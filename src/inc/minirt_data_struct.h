/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/04/06 12:06:22 by syl              ###   ########.fr       */
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
	float	difuse;
	float	specular;
	float	diam;
	float	height;
	t_coord	*v_axe;
	float	*m_identity; //
	float	*m_tranf;// initialiser?? matrice de transformation. résultat de toutes les transformation. m_transf = Rotation * Transl * Scale
	float	*m_transl;
	float	*m_rot;
	float	*m_scale;
}	t_obj;

// mem array que obj
typedef struct s_hits
{
	float		t1;
	float		t2;
	int	 		t_count;
	t_ray		*r_ray_calculs;
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
//	t_coord		vn_axe_x;
//	t_coord		vn_axe_y;
//	t_coord		vn_axe_z;
	//taille de l image. 
	float		*m_transf; // initialiser comme identity matrix
//	float		caneva_width; // image
//	float		caneva_hight; // image	
//	float		viewport_width; // viewport L1
//	float		viewport_height; // L2
	//matrice transformation. 
	float		view_width;// wall??
	float		view_height; // wall??
	float		canva_height;
	float		canva_width;
	float    	half_height;
	float		half_width;
	float		pixel_size;
	struct t_camera	*saved_camera; // (si on se perd. ou camera origines) est-ce que c est enregistré dans init?? 
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
}	t_image;

typedef struct s_matrix
{
	float	*m_rot_x;
	float	*m_rot_y;
	float	*m_rot_z;
	float	*m_transl;
	float	*m_identity;
}	t_matrix;

typedef struct s_comps
{
	float	closestt;
	t_obj	*obj;//pointeur closest
	t_coord	*p_point;
	t_coord	*v_eye; //inverse du ray de base
	t_coord	*v_norm_parral;
	t_ray	*r_ray;
//	t_coord *v_light;
	bool	inside;
	int 	t_count;
}	t_comps;

////////// CANVA //////////
typedef struct s_pix
{
	t_camera	*cam; // OK
	t_obj		***obj; // OK
	t_obj		***c_obj;//scene from camera a voir apres pour l instant sert à rien
	t_light		***lux; // OK
	t_image		*ima;
	t_matrix	*neo;
	t_coord		*p_origin_zero;// a mettre dans camera??

	//in each pixel. 
	float	vpx;// viewport x
	float vpy;// viewport y
//	t_ray 		*r_ray; //ray pour les calculs. 
	t_ray		*r_original; // ray entre camera et coordonnes sur viewport
	t_color		*color; // OK

	t_hits		***hits; //array de hits pour les objets
//	int		t_count;//ici compter le nombre d intersection?
	t_comps	*comps; // ici on peut faire une array pour mettre les objets dans l ordre où ils se font toucher...
}	t_pix;

#endif