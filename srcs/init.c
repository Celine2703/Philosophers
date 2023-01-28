/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:02:38 by cmartin-          #+#    #+#             */
/*   Updated: 2023/01/28 15:03:41 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philo(t_philo *philo, t_data *data) 
{
	int i;
	
	i = 0;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (1);
	ft_bzero(philo, sizeof(t_philo) * data->nb_philo); //initialise le tableau et les structures a 0 
	while (i < data->nb_philo)
	{
		philo[i].id = i;
		philo[i].data = data;
		i++;
	}
	return (0);
}

int	ft_init_mutex(t_philo *philo)
{
	int i;

	i = 0;
	philo ->mutex = malloc(sizeof(pthread_mutex_t) * philo ->data->nb_philo);
	philo ->print = malloc(sizeof(pthread_mutex_t));
	if (!(philo ->mutex) || !(philo ->print))
		return (1);
	pthread_mutex_init(philo ->print, NULL);
	while (i < philo ->data->nb_philo)
	{
		pthread_mutex_init(&(philo ->mutex[i]), NULL);
		i++;
	}
	return (0);
}

int	ft_init_thread(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo ->data->nb_philo)
	{
		if (pthread_create(&(philo ->thread), NULL, &ft_philo, NULL))
			return (1);
		i++;
	}
	return (0);
}