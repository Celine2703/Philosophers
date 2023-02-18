/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:42:29 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/18 15:42:36 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->dead_mutex);
	i = philo->dead;
	pthread_mutex_unlock(&philo->dead_mutex);
	return (i);
}

void	ft_knowing_death(t_philo *philo)
{
	int i;

	i = 0;
	while(i < philo->data->nb_philo)
	{
		pthread_mutex_lock(&philo[i].dead_mutex);
		philo[i].dead = 1;
		pthread_mutex_unlock(&philo[i].dead_mutex);
		i++;
	}
}

void	ft_death(t_philo *philo)
{
	int i;

	while(1)
	{
		i = 0;
		while(i < philo->data->nb_philo)
		{
			//printf("time %lld last meal %lld , time to die %d\n", ft_get_time(), philo[i].last_meal_time, philo[i].data->time_die);
			if (ft_get_time() - ft_check_meal(&philo[i]) > philo[i].data->time_die)
			{
				pthread_mutex_lock(philo[i].print);
				printf("%lld %d died\n", ft_get_time_diff(philo[i].beggining_time), philo[i].id);
				pthread_mutex_unlock(philo[i].print);
				ft_knowing_death(philo);
				return;
			}
			i++;
		}
	}
}