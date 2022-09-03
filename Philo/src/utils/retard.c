/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retard.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouazi <abouazi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:25:30 by abouazi           #+#    #+#             */
/*   Updated: 2022/09/01 18:30:33 by abouazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	retard(int64_t time_in_ms, t_container *cnt)
{
	int64_t	t_start;

	t_start = g_time();
	while (cnt->remember->status)
	{
		if (g_time() - t_start >= time_in_ms)
			break ;
		usleep(500);
	}
}