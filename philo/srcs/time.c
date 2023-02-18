/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:04:26 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/18 16:15:28 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_philo *philo, int time)
{
	long long	beggining;
	long long	now;

	beggining = ft_get_time();
	now = beggining;
	while (now <= beggining + (time / 1000))
	{
		//printf("now %lld, beggining %lld, beggining + time %lld\n", now, beggining, beggining + time);
		if (ft_check_death(philo))
			return ;
		usleep(100);
		now = ft_get_time();
	}
}

long long	ft_get_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

long long	ft_get_time_diff(long long beggining)
{
	long long	time;

	time = ft_get_time();
	return (time - beggining);
}
