/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:15:57 by fmartini          #+#    #+#             */
/*   Updated: 2023/09/01 16:33:29 by fmartini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	nmb;

	sign = 1;
	nmb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if(!(*str >= '0' && *str <= '9'))
            		return (nmb *= sign);
		nmb *= 10;
		nmb += (*str - '0');
		str++;
	}
	return (nmb *= sign);
}

int	main()
{
	char *s = "11";
	printf("%d\n",ft_atoi(s));
}
