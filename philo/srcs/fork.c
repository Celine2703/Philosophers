/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:09:21 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/23 16:09:29 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_lfork(t_philo *philo)
{
	pthread_mutex_lock(&philo ->mutex[philo ->index_lfork]);
	if (ft_check_death(philo))
		return ;
	pthread_mutex_lock(philo ->print);
	printf ("%lld %d has taken a fork\n",
		ft_get_time_diff(philo ->beggining_time), philo ->id);
	pthread_mutex_unlock(philo ->print);
}

static void	ft_rfork(t_philo *philo)
{
	pthread_mutex_lock(&philo ->mutex[philo ->index_rfork]);
	if (ft_check_death(philo))
		return ;
	pthread_mutex_lock(philo ->print);
	printf ("%lld %d has taken a fork\n",
		ft_get_time_diff(philo ->beggining_time), philo ->id);
	pthread_mutex_unlock(philo ->print);
}

void	ft_take_fork(t_philo *philo)
{
	if (philo ->id % 2 == 1)
	{
		ft_lfork(philo);
		ft_rfork(philo);
	}
	else
	{
		ft_rfork(philo);
		if (philo ->data ->nb_philo == 1)
		{
			pthread_mutex_unlock(&philo ->mutex[philo ->index_rfork]);
			return ;
		}
		ft_lfork(philo);
	}
	if (ft_check_death(philo))
	{
		pthread_mutex_unlock(&philo ->mutex[philo ->index_lfork]);
		pthread_mutex_unlock(&philo ->mutex[philo ->index_rfork]);
		return ;
	}
	ft_eat(philo);
}
