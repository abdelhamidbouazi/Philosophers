/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:02:30 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 01:12:16 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_container	*container;
	
	if (ac != 5 && ac != 6)
		return (printf("Arguments number error"), 0);
	if (checker(ac, av) == -1)
		return 0;
	initializ_philos(&container, ac, av);
	philo(container->philosophers);
	return (0);
}