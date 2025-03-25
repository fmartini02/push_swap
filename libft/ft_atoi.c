/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:15:57 by fmartini          #+#    #+#             */
/*   Updated: 2025/03/25 14:14:48 by francema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	nmb;

	sign = 1;
	nmb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if ((nmb > INT_MAX / 10) || (nmb == INT_MAX / 10
				&& (*str - '0') > INT_MAX % 10))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		nmb = nmb * 10 + (*str++ - '0');
	}
	return (nmb * sign);
}
