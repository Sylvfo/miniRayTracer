/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:45:21 by syl               #+#    #+#             */
/*   Updated: 2025/04/13 17:13:38 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/minirt.h"

struct timeval time_now(struct timeval start, char *str)
{
	struct timeval now;
	gettimeofday(&now, NULL);

	double duration = (now.tv_sec - start.tv_sec) + (now.tv_usec - start.tv_usec) / 1e6;
	printf("Time at %s : %.8f \n", str, duration);
	return (now);
}