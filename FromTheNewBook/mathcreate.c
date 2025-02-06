/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathcreate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:37:18 by sforster          #+#    #+#             */
/*   Updated: 2025/02/06 18:08:10 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

s_3Dcoord create_point(float x, float y, float z)
{
	s_3Dcoord Ppoint;

	Ppoint.x = x;
	Ppoint.y = y;
	Ppoint.z = z;
	Ppoint.t = 1;
	return(Ppoint);
}

s_3Dcoord create_vect(float x, float y, float z)
{
	s_3Dcoord Vvect;

	Vvect.x = x;
	Vvect.y = y;
	Vvect.z = z;
	Vvect.t = 0;
	return (Vvect);
}