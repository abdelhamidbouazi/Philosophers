/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:02:39 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/01 23:37:07 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	result(int sc, int nm, int s)
{
	if (sc > 1)
		return (0);
	return (nm * s);
}

static int	sn(char c)
{
	int	s;

	s = 1;
	if (c == '-')
		return (-1);
	return (s);
}
int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	nm;
	int	sc;

	i = 0;
	sign = 1;
	nm = 0;
	sc = 0;
	while ((s[i] >= '\t' && s[i] <= '\r')
		|| s[i] == '\n' || s[i] == ' ')
		i++;
	while (s[i] == '-' || s[i] == '+')
	{
		sc++;
		sign *= sn(s[i]);
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		nm = nm * 10 + (s[i] - 48);
		i++;
	}
	return (result(sc, nm, sign));
}
