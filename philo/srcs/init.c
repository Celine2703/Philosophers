/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:02:38 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/23 17:12:51 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_philo(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	pthread_mutex_lock(philo ->print);
	pthread_mutex_unlock(philo ->print);
	ft_philo(philo);
	return (NULL);
}

int	ft_init_philo(t_philo **philo, t_data *data)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!*philo)
		return (1);
	ft_bzero(*philo, sizeof(t_philo) * data->nb_philo);
	while (i < data->nb_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].index_lfork = i;
		(*philo)[i].index_rfork = (i + 1) % data->nb_philo;
		(*philo)[i].data = data;
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	philo ->mutex = malloc(sizeof(pthread_mutex_t) * philo ->data->nb_philo);
	philo ->print = malloc(sizeof(pthread_mutex_t));
	if (!(philo ->mutex) || !(philo ->print))
		return (1);
	pthread_mutex_init(philo ->print, NULL);
	while (i < philo ->data->nb_philo)
	{
		if (pthread_mutex_init(&(philo ->mutex[i]), NULL))
			return (1);
		if (pthread_mutex_init(&(philo[i].dead_mutex), NULL))
			return (1);
		if (pthread_mutex_init(&(philo[i].last_meal_mutex), NULL))
			return (1);
		philo[i].mutex = philo ->mutex;
		philo[i].print = philo ->print;
		philo[i].dead = 0;
		i++;
	}
	return (0);
}

int	ft_init_thread(t_philo *philo)
{
	int			i;
	long long	beggining;

	i = 0;
	beggining = ft_get_time();
	pthread_mutex_lock(philo ->print);
	while (i < philo ->data->nb_philo)
	{
		philo[i].beggining_time = beggining;
		philo[i].last_meal_time = beggining;
		if (pthread_create(&(philo[i].thread), NULL, &start_philo, philo + i))
			return (1);
		i++;
	}
	pthread_mutex_unlock(philo ->print);
	return (0);
}
