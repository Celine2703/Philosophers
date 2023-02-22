/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:45:17 by cmartin-          #+#    #+#             */
/*   Updated: 2023/02/22 16:46:44 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_destroy(&philo->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(philo->print);
	free(philo->print);
	free(philo->mutex);
	free(philo);
}

void	*ft_philo(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (ft_check_death(philo) == 0)
	{
		ft_eat(philo);
		if (ft_check_death(philo) || philo ->data ->nb_philo == 1)
			return (NULL);
		pthread_mutex_lock(philo ->print);
		printf("%lld %d is sleeping\n",
			ft_get_time_diff(philo ->beggining_time), philo ->id);
		pthread_mutex_unlock(philo ->print);
		ft_usleep(philo, philo ->data ->time_sleep);
		if (ft_check_death(philo))
			return (NULL);
		pthread_mutex_lock(philo ->print);
		printf("%lld %d is thinking\n",
			ft_get_time_diff(philo ->beggining_time), philo ->id);
		pthread_mutex_unlock(philo ->print);
		usleep(500);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data data;
	t_philo *philo;

	philo = NULL;
	if (ft_parsing(argc, argv, &data))
		return (1);
	ft_init_philo(&philo, &data);
	ft_init_mutex(philo);
	ft_init_thread(philo);
	usleep(1000);
	ft_death(philo);
	
	//le programme se fait en 3 parties
	
	//on verifie que last meal + time to die est inferieur a time actuel
	
	//2. boucle de vie des philo
	
	end_philo(philo);
	//pthread_join(thread, NULL);
	return (0);
}
