/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathNewBook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:45:30 by sforster          #+#    #+#             */
/*   Updated: 2025/02/06 16:09:37 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirtnew.h"

//float or double???
// pointers,malloc??

// division mieux vaut multiplier par 0.5
// racine carree rapide. A voir entre precision et temps. 

// points p_blabla
// vectors v_blabal

typedef	struct s_3Dcoord {
	float x;
	float y;
	float z;
	int	t;// type 0 for vector and 1 for point. //w like in the book?
}	t_3Dcoord;

// to add a vector to a point
// or 2 vectors.
t_3Dcoord addition(t_3Dcoord t1, t_3Dcoord t2) 
{
	t_3Dcoord new;

	new.x = t1.x + t2.x;
	new.y = t1.y + t2.y;
	new.y = t1.z + t2.z;
	new.t = t1.t + t2.t;

	return (new);
}

// p.28
// subst 2 points to get a vector ex: a vector to point to your light source. 
// Or two vectors + represent the change of direction between the 2
t_3Dcoord substraciton(t_3Dcoord t1, t_3Dcoord t2) 
{
	t_3Dcoord new;

	new.x = t1.x - t2.x;
	new.y = t1.y - t2.y;
	new.y = t1.z - t2.z;
	new.t = t1.t - t2.t;

	return (new);
}

