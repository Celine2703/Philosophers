/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:42:29 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/23 16:40:05 by cmartin-         ###   ########.fr       */
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

void	ft_print_death(t_philo *philo, int i)
{
	ft_knowing_death(philo);
	pthread_mutex_lock(philo[i].print);
	printf("%lld %d died\n",
		ft_get_time_diff(philo[i].beggining_time), philo[i].id);
	pthread_mutex_unlock(philo[i].print);
}

void	ft_knowing_death(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo ->data ->nb_philo)
	{
		pthread_mutex_lock(&philo[i].dead_mutex);
		philo[i].dead = 1;
		pthread_mutex_unlock(&philo[i].dead_mutex);
		i++;
	}
}

void	ft_death(t_philo *philo)
{
	int	i;
	int	nb_philo_full;

	nb_philo_full = 0;
	while (nb_philo_full < philo ->data ->nb_philo)
	{
		i = 0;
		nb_philo_full = 0;
		while (i < philo->data->nb_philo)
		{
			if (ft_get_time() - ft_check_meal(&philo[i])
				>= philo[i].data->time_die)
			{
				ft_print_death(philo, i);
				return ;
			}
			if (philo[i].data->nb_meals != -1
				&& philo[i].data ->nb_meals <= ft_check_ate(&philo[i]))
				nb_philo_full++;
			i++;
		}
		usleep(1000);
	}
	ft_knowing_death(philo);
}
