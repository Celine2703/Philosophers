/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:04:26 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/16 17:38:13 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



long long	ft_get_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

long long ft_get_time_diff(long long beggining)
{
	long long time;

	time = ft_get_time();
	return (time - beggining);
}