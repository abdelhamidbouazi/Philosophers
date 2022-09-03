/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:02:30 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 18:15:57 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_container	*container;
	
	if (ac != 5 && ac != 6)
		return (printf("Arguments number error"), FT_SUCCESS);
	if (checker(ac, av) == -1)
		return (FT_SUCCESS);
	initializ_philos(&container, ac, av);
	philo(container->philosophers);
	return (FT_SUCCESS);
}