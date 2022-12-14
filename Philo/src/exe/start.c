/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:06:37 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 18:18:42 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	philo(t_philos *philo)
{
	int	i;

	i = 0;
	philo->cont->remember->start = g_time();
	while (i < philo->cont->collect->n_philos)
	{
		(philo + i)->last_eat = g_time();
		if (pthread_create (&(philo + i) \
			->philo_thread, NULL, routine, philo + i))
			return (printf ("creating thread error"), FT_SUCCESS);
		pthread_detach((philo + i)->philo_thread);
		usleep(50);
		i++;
	}
	if (pthread_create(&philo->cont->remember->rem_thread, NULL, sup, philo))
		return (printf("creating thread error"), FT_SUCCESS);
	if (pthread_join(philo->cont->remember->rem_thread, NULL))
		return (printf ("joining error"), FT_SUCCESS);
	i = -1;
	while (++i < philo->cont->collect->n_philos)
		pthread_mutex_destroy(&philo->cont->remember->mutex_forks[i]);
	pthread_mutex_destroy(&philo->cont->remember->mutex_print);
	return (FT_SUCCESS);
}
