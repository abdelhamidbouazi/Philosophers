/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:02:39 by abouazi           #+#    #+#             */
/*   Updated: 2022/08/23 23:51:39 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	getsign(char c)
{
	int	signn;

	signn = 1;
	if (c == '-')
		return (-1);
	return (signn);
}

static int	rslt(int _signcount, int _number, int _sign)
{
	if (_signcount > 1)
		return (0);
	return (_number * _sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;
	int	signcount;

	i = 0;
	sign = 1;
	number = 0;
	signcount = 0;
	while ((str[i] >= '\t' && str[i] <= '\r')
		|| str[i] == '\n' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		signcount++;
		sign *= getsign(str[i]);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (rslt(signcount, number, sign));
}
