/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:02:36 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/03 18:54:50 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
# 	define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdbool.h>

# define FT_SUCCESS 0
# define FT_FAILURE 1

typedef struct s_remember
{
	pthread_t		rem_thread;
	bool			status;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_print;
	long			start;
}	t_remember;

typedef struct struct_data
{
	int			n_philos;
	long		time_die;
	long		time_eat;
	long		time_sleep;
	int			nom;
}			t_data;

typedef struct s_philos
{
	int					philosopher;
	int					nbr_of_meals;
	long				last_eat;
	pthread_t			philo_thread;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	struct s_container	*cont;
}	t_philos;

typedef struct s_container
{
	t_remember	*remember;
	t_philos	*philosophers;
	t_data		*collect;
}	t_container;

int		checker(int ac, char **av);
int		ft_atoi(const char *str);
int		initializ_philos(t_container **cont, int ac, char **av);
int		in_set(t_remember **rem, int numphi);
int		philo(t_philos *philo);
int64_t	g_time(void);
void	retard(int64_t time_in_ms, t_container *cnt);
void	print(t_philos *philo, char *str);
void	*routine(void *args);
void	*sup(void *args);

#endif