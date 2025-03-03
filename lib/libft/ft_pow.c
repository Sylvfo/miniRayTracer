/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 07:14:45 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 07:18:43 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double base, int exp)
{
	double	result;

	result = 1.0;
	if (exp < 0)
	{
		base = 1.0 / base;
		exp = -exp;
	}
	while (exp)
	{
		if (exp % 2 == 1)
			result *= base;
		base *= base;
		exp /= 2;
	}
	return (result);
}
