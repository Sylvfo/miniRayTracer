/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 07:18:33 by cmegret           #+#    #+#             */
/*   Updated: 2025/02/21 13:27:38 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_whitespace(const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
		sign = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
	return (sign);
}

static double	parse_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**str))
		result = result * 10.0 + (*(*str)++ - '0');
	return (result);
}

static double	parse_fractional_part(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			fraction = fraction * 10.0 + (*(*str)++ - '0');
			divisor *= 10.0;
		}
	}
	return (fraction / divisor);
}

float	ft_strtod(const char *str, char **endptr)
{
	float	result;
	float	fraction;
	int		sign;

	skip_whitespace(&str);
	sign = parse_sign(&str);
	result = parse_integer_part(&str);
	fraction = parse_fractional_part(&str);
	result += fraction;
	if (endptr)
		*endptr = (char *)str;
	return (sign * result);
}
