/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/05/07 11:58:45 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

//mneme
//= memoire à allouer avant

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
	int		obj_type;
	bool	closed_up; // for cylinder, for bonus...
	bool	closed_down; // for cylinder, for bonus...
// 	pour calcul transf matrix
	float	*m_transl; // IMPORTANT
	float	*m_rot; // IMPORTANT
	float	*m_scale; // IMPORTANT
	float	*m_transf;// matrice de transformation. résultat de toutes les transformation. m_transf = Rotation * Transl * Scale
	float	*m_inv;
	t_coord *v_axe_r; // pour matrix rotation IMPORTANT
	t_coord *from;// pour matrix rotation IMPORTANT
	//for inverted
	t_coord *v_sph_camera; //IMPORTANT DANS INTERSECT SPHERE
	float	radius; //UTILISE??
//	float	*m_submatrix;//??
	//calcul intersect sphere
//	t_coord	*p_world;
	//pour normal at
//	t_coord *origin_zero;
//	t_coord *p_object_space;
//	t_coord *object_normal;
//	float 	*transp_inv;
	// pour intersect shadow
//	t_coord *v_light_to_point;
// un truc pour obj modifié pour calculs quand on déplace un objet....	
	//	float	*m_rot_x;
//	float	*m_rot_y;
//	float	*m_rot_z;
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
//	float		*m_identity;
//	float		*m_transf;// pas forcément besoin?
//	float		*m_transl;
//	t_coord		*p_world;
}	t_light;

typedef struct s_camera
{
	//depuis parsing
	t_coord		*p_coord;//PARS
	t_coord		*v_axe;//PARS
	float		fov;//PARS
	t_coord		*p_zero;// utilisé dans intersect sphere// a mettre ailleurs?
	// pour bouger cam
	t_coord		*v_up;// INIT TOUS PAREIL (0, 1, 0)
	t_coord		*v_left; // INIT (0, 0, 0)
	t_coord		*v_true_up; // INIT (0, 0, 0)
	float		*m_orient; // IN VIEW CAM initialiser identity matrix utilisé 1x
	float		*m_transl; // IN VIEW CAM initialiser identity matrix utilisé 1x
	float		*m_transf; // IN VIEW CAM initialiser identity matrix utilisé 1x
	float 		*m_inverse; // IN CAM PIX RAY
	float		view_width;// IMPORTANT viewport
	float		view_height; // IMPORTANT viewport
	float		canva_height; // IMPORTANT taille image ima_h
	float		canva_width; // IMPORTANT taille image ima_w
	float    	half_height;//est-ce que c est vraiment important laisser dans data struct? O
	float		half_width;// pareil, on utilise 1 fois...
	float		pixel_size;//IMPORTANT
	struct t_camera	*saved_camera; // (si on se perd. ou camera origines)
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
	t_coord	*r_origin; // utile??
	t_coord	*r_dir; // IMPORTANT DANS POSITION PREPARE COMP. 
	float	closestt;  //IMPORTANT DANS PREPARE COMP.
	int 	t_count; // utile??
	int		obj_type; //IMPORTANT DANS PREPARE COMP.
	t_obj	*obj;//pointeur closest
	t_color *obj_color;
//	t_coord *p_world;
	//pour normal at
	t_coord *origin_zero;
	t_coord *object_normal; // IMPORTANT DANS INTERSECT SPHERE a fusionner avec v_norm_parral??
	float 	*transp_inv;//IMPORTANT DANS NORMAL AT 
	t_coord *p_space;//IMPORTANT DANS NORMAL AT 
	float 	*obj_inv; //IMPORTANT DANS NORMAL AT 
	
// dans prepare computation
	t_coord	*p_touch;//
	t_coord	*v_eye; //inverse du ray de base
	t_coord	*v_norm_parral; //IMPORTANT DANS NORMAL AT ET POUR LUM
	bool	inside;// important??
	// dans shadows lights
	t_coord *v_light_to_point;
	float distance_light_p_touch;
	t_coord *v_sphere_to_point; // in shad??
	t_coord *v_point_to_light; // IMPORTANT DANS COMPUTE POINTLIGHT
	//in specular
	t_coord	*reflect_dir;
	t_coord	*scalar;
	t_coord *view_dir;
	float	height;
}	t_comps;

////////// CANVA //////////
typedef struct s_pix
{
	// a la limite on pourrait mettre dans 1 seul pointeur....
	t_camera	*cam;
	t_image		*ima;// on peut mettre ima dans cam pour faire moins de pointeurs.
	t_obj		***obj;
	t_light		***lux;

	t_coord		*p_viewport; // point sur le viewport avec xy. UTILISE 1x
	t_coord		*p_viewport_world;// point sur le viewport avec xy. UTILISE 1x
	//ray original à garder =)
	t_coord		*r_origin; // IMPORTANT UTILISE DANS INIT PIX RAY
	t_coord		*r_dir; // IMPORTANT CALCULE DANS INIT PIX RAY
	t_color		*color; // IMPORTANT
	t_hits		***hits; //array de hits pour stocker les intersections objets
	t_comps		*comps; // ici on peut faire une array pour mettre les objets dans l ordre où ils se font toucher...
//	int			t_count;//ici compter le nombre d intersection?
}	t_pix;

//	t_matrix	*neo;
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