/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/04/17 15:19:44 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

//	s_coord p_exemplepoint;
//	s_coord v_exemplevector;
//	s_coord vn_exemplenormedvector;
//	s_coord *r_ray;
//	s_color c_color;
//  float *m_matrix;

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

////////// SCENE //////////
// object[0][0]->color = backgroud color
// object[1][0] spheres
// object[2][0] plans
// object[3][0] cylinder
typedef struct s_obj
{
// donné dans le parsing
	t_coord	*p_coord;
	t_color	*color;
	float	difuse;
	float	specular;
	float	diam;
	float	height;
	t_coord	*v_axe;
	bool	closed_up; // for cylinder, for bonus...
	bool	closed_down; // for cylinder, for bonus...
// 	pour calcul transf matrix
	float	*m_identity; //
	float	*m_tranf;// matrice de transformation. résultat de toutes les transformation. m_transf = Rotation * Transl * Scale
	float	*m_transl;
	float	*m_rot;
	//	float	*m_rot_x;
//	float	*m_rot_y;
//	float	*m_rot_z;
	float	*m_scale;
// v norm parr pour calcul lumières	
	t_coord *v_norm_parral_plan;
	int		obj_type;
// un truc pour obj modifié pour calculs quand on déplace un objet....	
}	t_obj;

// mem array que obj
typedef struct s_hits
{
	float		t1;
	float		t2;
	int	 		t_count;
	t_coord		*r_origin;
	t_coord		*r_dir;
	int			obj_type;
}	t_hits;

// light[0][0] = ambiant light.
// light[1] = spotlight light.
// light[2] = other type of light (in bonus)
typedef struct s_light
{
	t_coord		*p_coord;
	float		ratio; //brightnessss
	t_color		*color;
	float		*m_identity;
	float		*m_tranf;
	float		*m_transl;
	t_coord		*p_world;
}	t_light;

typedef struct s_camera
{
	t_coord		*p_coord;
	t_coord		*v_axe;
	float		fov;
	float		*m_transf; // initialiser comme identity matrix
	float 		*m_inverse;
	t_coord		*p_origin_zero;// utilisé dans intersect sphere// a mettre ailleurs?
	float		view_width;// viewport
	float		view_height; // viewport
	float		canva_height; // taille image ima_h
	float		canva_width; // taille image ima_w
	float    	half_height;//est-ce que c est vraiment important laisser dans data struct? O
	float		half_width;// pareil, on utilise 1 fois...
	float		pixel_size;
	struct t_camera	*saved_camera; // (si on se perd. ou camera origines) est-ce que c est enregistré dans init?? 
//	int			render_type; pour les bonus. type render, type preview
}	t_camera;

////////// ?? //////////
// a mettre dans camera pour eviter trop de pointeurs??
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

typedef struct s_comps
{
//	dans closestt?
	t_coord	*r_origin;
	t_coord	*r_dir;
	float	closestt;
	int 	t_count;
	int		obj_type;
	t_obj	*obj;//pointeur closest

// dans prepare computation
	t_coord	*p_touch;//
	t_coord	*v_eye; //inverse du ray de base
	t_coord	*v_norm_parral;
	bool	inside;
}	t_comps;

////////// CANVA //////////
typedef struct s_pix
{
	// a la limite on pourrait mettre dans 1 seul pointeur....
	t_camera	*cam;
	t_image		*ima;// on peut mettre ima dans cam pour faire moins de pointeurs.
	t_obj		***obj;
	t_light		***lux;
	
	//different in each pixel. 
	// une fois ray calculé plus besoin....
	float		vpx;// viewport x
	float 		vpy;// viewport y
	t_coord		*p_viewport; // point sur le viewport avec xy. 
	//ray original à garder =)
	t_coord		*r_origin;
	t_coord		*r_dir;
	t_color		*color; // OK
	t_hits		***hits; //array de hits pour stocker les intersections objets
	t_comps		*comps; // ici on peut faire une array pour mettre les objets dans l ordre où ils se font toucher...
//	t_matrix	*neo;
//	int			t_count;//ici compter le nombre d intersection?
}	t_pix;

/* apparement ça sert à rien...
typedef struct s_matrix
{
	float	*m_rot_x;
	float	*m_rot_y;
	float	*m_rot_z;
	float	*m_transl;
	float	*m_identity;
}	t_matrix;*/

#endif