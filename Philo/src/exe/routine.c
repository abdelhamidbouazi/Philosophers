/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:37:09 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 18:45:40 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*routine(void *args)
{
	t_philos	*philo;

	philo = (t_philos *)args;
	philo->cont->remember->start = g_time();
	while (philo->cont->remember->status)
	{
		print(philo, " thinking");
		pthread_mutex_lock (philo->l_fork);
		print(philo, " take left fork");
		pthread_mutex_lock (philo->r_fork);
		print(philo, " take right fork");
		print(philo, " eating");
		retard(philo->cont->collect->time_eat, philo->cont);
		philo->last_eat = g_time();
		pthread_mutex_unlock (philo->l_fork);
		pthread_mutex_unlock (philo->r_fork);
		if (philo->cont->remember->status)
			philo->nbr_of_meals++;
		print(philo, " sleeping");
		retard(philo->cont->collect->time_sleep, philo->cont);
	}
	return (NULL);
}
