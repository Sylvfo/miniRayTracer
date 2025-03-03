/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmegret <cmegret@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:05:57 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/19 07:21:18 by cmegret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static float	ft_parse_integer_part(const char **str)
{
	float	result;

	result = 0.0f;
	while (ft_isdigit(**str))
	{
		result = result * 10.0f + (**str - '0');
		(*str)++;
	}
	return (result);
}

static float	ft_parse_fractional_part(const char **str)
{
	float	fraction;
	float	divisor;

	fraction = 0.0f;
	divisor = 10.0f;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			fraction += (**str - '0') / divisor;
			divisor *= 10.0f;
			(*str)++;
		}
	}
	return (fraction);
}

float	ft_atof(const char *str)
{
	float	result;
	float	fraction;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = ft_parse_sign(&str);
	result = ft_parse_integer_part(&str);
	fraction = ft_parse_fractional_part(&str);
	return (sign * (result + fraction));
}
