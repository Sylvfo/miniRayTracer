/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:51:07 by sforster          #+#    #+#             */
/*   Updated: 2025/02/06 18:08:19 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef	struct s_3Dcoord {
	float x;
	float y;
	float z;
	int	t;// type 0 for vector and 1 for point. //w like in the book?
}	t_3Dcoord;

void print3dvect(t_3Dcoord va)
{
	printf("vx %f, vy %f, vz %f\n", va.x, va.y, va.z);
}

t_3Dcoord addition(t_3Dcoord t1, t_3Dcoord t2) 
{
	t_3Dcoord new;

	new.x = t1.x + t2.x;
	new.y = t1.y + t2.y;
	new.y = t1.z + t2.z;
	new.t = t1.t + t2.t;
	return (new);
}

int main(void)
{
	t_3Dcoord va;
	t_3Dcoord pb;

	va.x = 5;
	va.y = 8;
	va.z = 7;
	va.t = 1;

	print3dvect(va);
	return (0);
}