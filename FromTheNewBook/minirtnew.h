/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirtnew.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:03:17 by sforster          #+#    #+#             */
/*   Updated: 2025/02/06 18:08:21 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRTNEW_H
# define MINIRTNEW_H

//# include "librairies/libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define RAY_T_MIN 0.0001f // not to interract with the last object touched. no neg value. 1 is for safety
# define RAY_T_MAX 0.0e30f // really large floating number. So it means 1.0 × 10³⁰ (10 puissance 30) 1 suivi de 30 zeros

//////////////////////
/// VECTEURS

typedef	struct s_3Dcoord {
	float x;
	float y;
	float z;
	int	t;// type 0 for vector and 1 for point.
}	t_3Dcoord;

//////////////////////
/// OBJETS
// spheres
typedef struct	s_sphere {
	t_3dpoint		*center;
	int				radius;
	int				color;
}				t_sphere;

// lampe
typedef struct s_spotlight { //bulb??
	t_3dpoint	*coord;
	float		ratio;
//	int			color;	not in mandatory part
} t_spotlight;

//plan
typedef struct	s_plane {
	t_3dpoint		*point;
	t_vect3d		*normal; // normal, so 90° from the point
	int				color;
}	t_plane;

//cylindre
typedef struct	s_cyl {
	t_3dpoint		*center;
	t_vect3d		*axis;
	int				height;
	int				diam;
	int				color;
}	t_cyl;

//////////////////////
/// GENERALE

//fusionner scene + view??? pour une structure globale
// sur laquelle les pixels vont tous pointer...???
//a avoir si on a une scene camera et une scene normale...
typedef struct s_scene {
	t_sphere	**sphere;
	float		ambient_light_ratio;
	float		ambient_light_color;
	t_plane		*plane;
	t_spotlight *light1;
	//autres formes
} t_scene;


// vecteurs de la camera comme parle avec Babak

// data stuct globale.
typedef struct	s_view {//global
	t_3dpoint	*cam;
	float	caneva_width;
	float	caneva_height;
	float	view_width;
	float	view_height;
	int		Vz; //dist du viewport de la camera
	t_scene		*scene;
	int 	backgroundcolor;
	// calculer rapport en canveva et view??
}				t_view;

//////////////////////
/// PIXELS
// data struc = array of pixels.

//chaque pixel devra pointer vers l'objet le plus proche. 
// comme ça on peut sélectionner avec la souris
typedef struct	s_pix {
	int			Cx; //axe x sur le canvas
	int			Cy;  //axe y sur la canvas
	t_vect3d	*D; // vecteur entre camera et coordonnes sur viewport
	int			color;
	t_view		*global;
	t_scene		*scene;
	float		t1;
	float		t2;
//	float		light_int;
} t_pix;

//////////////////////
///	IMAGE

// data struct pour les images et minilibx. 
typedef struct s_image {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx_ptr;
	void			*mlx_win;
	t_view			*global;
}	t_image;



#endif