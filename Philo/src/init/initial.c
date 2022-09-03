/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:05:14 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 18:18:11 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/philo.h"

int	data_in(t_data **data, int ac, char **av)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!*data)
		return (FT_SUCCESS);
	(*data)->n_philos = ft_atoi(av[1]);
	(*data)->time_die = ft_atoi(av[2]);
	(*data)->time_eat = ft_atoi(av[3]);
	(*data)->time_sleep = ft_atoi(av[4]);
	(*data)->nom = -1;
	if (ac == 6)
		(*data)->nom = ft_atoi(av[5]);
	return (FT_SUCCESS);
}

int	in_set(t_remember **rem, int numphi)
{
	t_remember	*remember;
	int		j;

	remember = (t_remember *)malloc(sizeof(t_remember));
	if (!remember)
		return (FT_SUCCESS);
	remember->start = 0;
	remember->status = true;
	remember->mutex_forks = malloc(sizeof(pthread_mutex_t) * numphi);
	if (!remember->mutex_forks)
		return (FT_SUCCESS);
	j = -1;
	while (++j < numphi)
		if (pthread_mutex_init(remember->mutex_forks + j, NULL))
			return (-1);
	if (pthread_mutex_init(&remember->mutex_print, NULL))
		return (-1);
	*rem = remember;
	return (FT_SUCCESS);
}

int	phi_in(t_philos **phil, t_container *remember, \
	pthread_mutex_t *mutex_forks, int nphilo)
{	
	int	i;

	*phil = (t_philos *)malloc(sizeof(t_philos) * nphilo);
	if (!*phil)
		return (FT_SUCCESS);
	i = -1;
	while (++i < nphilo)
	{
		(*phil + i)->philosopher = i + 1;
		(*phil + i)->nbr_of_meals = 0;
		(*phil + i)->last_eat = 0;
		(*phil + i)->cont = remember;
		(*phil + i)->l_fork = mutex_forks + i;
		(*phil + i)->r_fork = mutex_forks + ((i + 1) % nphilo);
	}
	return (FT_SUCCESS);
}


int	initializ_philos(t_container **cont, int ac, char **av)
{
    t_container	*cnt;

	cnt = (t_container *)malloc(sizeof(t_container));
	if (!cnt)
		return (FT_SUCCESS);      
   	data_in(&cnt->collect, ac, av);
   	in_set(&cnt->remember, cnt->collect->n_philos);
	phi_in(&cnt->philosophers, cnt, cnt->remember->mutex_forks, cnt->collect->n_philos);
	*cont = cnt;
	return (FT_SUCCESS);
}
