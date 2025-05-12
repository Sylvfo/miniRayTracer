/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/05/12 09:15:50 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
	int		t;
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
	t_coord	*p_coord;
	t_color	*color;
	float	difuse;
	float	specular;
	float	diam;
	float	height;
	t_coord	*v_axe;
	int		type;
	bool	closed_up;
	bool	closed_down;
	float	*m_transl;
	float	*m_rot;
	float	*m_scale;
	float	*m_transf;
	float	*m_inv;
	t_coord	*v_axe_r;
	t_coord	*from;
	t_coord	*v_sph_camera;
	float	radius;
}	t_obj;

typedef struct s_hits
{
	float		t1;
	float		t2;
	int			t_count;
	t_coord		*r_origin;
	t_coord		*r_dir;
	int			type;
}	t_hits;

typedef struct s_light
{
	t_coord		*p_coord;
	float		ratio;
	t_color		*color;
}	t_light;

typedef struct s_camera
{
	t_coord		*p_coord;
	t_coord		*v_axe;
	float		fov;
	t_coord		*p_zero;
	t_coord		*v_up;
	t_coord		*v_left;
	t_coord		*v_true_up;
	float		*m_orient;
	float		*m_transl;
	float		*m_transf;
	float		*m_inverse;
	float		view_width;
	float		view_height;
	float		canva_height;
	float		canva_width;
	float		half_height;
	float		half_width;
	float		pixel_size;
}	t_camera;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*mlx_win;
}	t_image;

typedef struct s_comps
{
	t_coord	*r_origin;
	t_coord	*r_dir;
	float	closestt;
	int		t_count;
	int		type;
	t_obj	*obj;
	t_color	*obj_color;
	t_coord	*origin_zero;
	t_coord	*object_normal;
	float	*transp_inv;
	t_coord	*p_space;
	float	*obj_inv;
	t_coord	*p_touch;
	t_coord	*v_eye;
	t_coord	*v_norm_parral;
	bool	inside;
	t_coord	*v_light_to_point;
	float	distance_light_p_touch;
	t_coord	*v_sphere_to_point;
	t_coord	*v_point_to_light;
	t_coord	*reflect_dir;
	t_coord	*scalar;
	t_coord	*view_dir;
	float	height;
}	t_comps;

typedef struct s_pix
{
	t_camera	*cam;
	t_image		*ima;
	t_obj		***obj;
	t_light		***lux;
	t_coord		*p_viewport;
	t_coord		*p_viewport_world;
	t_coord		*r_origin;
	t_coord		*r_dir;
	t_color		*color;
	t_hits		***hits;
	t_comps		*comps;
}	t_pix;

typedef struct s_program_context
{
	t_pix		***pix;
	t_num_obj	*num_obj;
	int			width;
	int			height;
	t_image		*ima;
	void		*mlx_ptr;
	void		*mlx_win;
}	t_program_context;

#endif