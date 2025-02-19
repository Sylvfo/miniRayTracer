/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:53:20 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 13:56:45 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

# define RAY_T_MIN 0.0001f
# define RAY_T_MAX 1.0e30f

/* Coordonnées 3D */
typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
	int		type; // 0: vecteur, 1: point
}	t_coord;

/* Couleur RGB */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

/* Définition des objets 3D */
typedef struct s_sphere
{
	t_coord	center;
	float	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_coord	point;
	t_coord	normal;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_coord	center;
	t_coord	axis;
	float	height;
	float	diameter;
	t_color	color;
}	t_cylinder;

/* Lumières */
typedef struct s_spotlight
{
	t_coord	coord;
	float	ratio;
}	t_spotlight;

/* Caméra */
typedef struct s_camera
{
	t_coord			vn_axe_x;
	t_coord			vn_axe_y;
	t_coord			vn_axe_z;
	float			viewport_width;
	float			viewport_height;
	t_coord			v_origin_camera;
	float			center;
	struct s_camera	*saved_camera;
	float			caneva_width;
	float			caneva_hight;
}	t_camera;

/* Structure pour gérer les images avec MiniLibX */
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

/* Structure d’un pixel utilisé dans le rendu */
typedef struct s_pix
{
	t_camera	*camera;
	t_image		*img;
	t_coord		*direction;
	t_color		color;
	float		t1;
	float		t2;
}	t_pix;

#endif