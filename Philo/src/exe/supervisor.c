/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:38:57 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 18:46:03 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*sup(void *args)
{
	t_philos	*philo;
	int			i;
	int			fl;

	philo = (t_philos *)args;
	while (philo->cont->remember->status)
	{
		i = -1;
		fl = 0;
		while (++i < philo->cont->collect->n_philos)
		{
			if (g_time() - (philo + i)->last_eat
				> philo->cont->collect->time_die)
			{
				print(philo + i, " died");
				philo->cont->remember->status = false;
			}
			if (philo->cont->collect->nom != -1 && (philo + i)->nbr_of_meals
				>= philo->cont->collect->nom)
				fl++;
		}
		if (fl == philo->cont->collect->n_philos)
			philo->cont->remember->status = false;
	}
	return (NULL);
}
