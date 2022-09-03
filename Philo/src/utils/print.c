/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:25:37 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 18:01:17 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
 
void	print(t_philos *philo, char *str)
{
	pthread_mutex_lock (&philo->cont->remember->mutex_print);
	if (philo->cont->remember->status)
		printf("-----> [%lld] ---- [%d] ----- %s\n", \
				g_time() - philo->cont->remember->start, philo->philosopher, str);
	pthread_mutex_unlock(&philo->cont->remember->mutex_print);
}
