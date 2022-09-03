/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:12:35 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 19:00:10 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_is_digit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (FT_FAILURE);
	else
		return (FT_SUCCESS);
}

int	ft_isalnum(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_is_digit(s[i]))
			return (FT_FAILURE);
		i++;
	}
	return (FT_SUCCESS);
}

int	checker(int ac, char **av)
{
	int	i;

	if (ac < 6)
	{
		i = 1;
		while (av[i])
		{
			if (ft_isalnum(av[i]))
				return (printf("Don't enter Characters\n"), -1);
			i++;
		}
		i = 0;
		while (av[++i])
		{
			if (ft_atoi(av[i]) < 0)
				return (printf("error"), -1);
			else if (ft_atoi(av[i]) == 0)
				return (printf("don't enter 0"), -1);
		}
	}
	return (FT_SUCCESS);
}
