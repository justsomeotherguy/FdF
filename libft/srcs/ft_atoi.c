/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:52:09 by jwilliam          #+#    #+#             */
/*   Updated: 2022/05/23 16:18:03 by jwilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	check_whitespace(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f'
		|| c == 32)
		return (1);
	else
		return (0);
}

/*
Receives a string character array and converts the string into an integer
variable. The return value is the integer that is created from the conversion.
*/
int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		res;

	i = 0;
	res = 0;
	neg = 1;
	if (!str)
		return (0);
	while (check_whitespace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}	
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * neg);
}
